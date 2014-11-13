#!/usr/bin/env ruby 

#--------------------------------------------------------------+
# A script to modify COBOL programs. Replace CALLs to some of
# the modules with CICS calls, add required working-storage
# variables, and subsequent error/condition code movements.
# The modules, their working-storage and other code snippets
# are defined in the corrosponding file outside this program in
# JSON format.
#
# author: yogesh kulkarni   (yogesh_m_kulkarni@dell.com)
# created: 13.10.2014
# 
# modified:
#--------------------------------------------------------------+
 
#
# static data 
#

$cob_kw = 
["ACCEPT", "ADD", "CASE", "CALL", "COMPUTE", "COPY", "DISPLAY", "DIVIDE", "DOWHILE",
"DOUNTIL", "ELSE", "END", "END-ACCEPT", "END-ADD", "END-CALL", "END-COMPUTE",
"END-DELETE", "END-DISPLAY", "END-DIVIDE", "END-EVALUATE", "ENDIF", "END-IF",
"END-MULTIPLY", "END-OF-PAGE", "END-PERFORM", "END-READ", "END-RECEIVE", "END-RETURN",
"END-REWRITE", "END-SEARCH", "END-START", "END-STRING", "END-SUBTRACT", "END-UNSTRING",
"END-WRITE", "END-XML", "ENTRY", "ERRCNT", "EVALUATE", "EXEC", "EXIT", "EXITDO",
"FIND", "GO", "GOTO", "GOBACK", "HEXPRINT", "IF", "INITIALIZE", "LIST", "MOVE", "MULTIPLY",
"NEXT", "OPEN", "PERFORM", "PRINT", "READ", "RETURN", "REWRITE", "ROLLBACK", "SEARCH",
"SET", "SORT", "SORT-MERGE", "SORT-RETURN", "START", "STOP", "STRING", "SUBSTITUTE",
"SUBTRACT", "SUM", "TRANSLATE", "UNSTRING", "WHEN", "WRITE", "ABSOLUTE", "WHILE" ]

$modules = ["DISKADD", "TPFIAD", "DISKREAD", "TPFIRD", 
   "RDNXTDAT", "TPFIRDN", "TPFIRDP", "DISKDEL",
   "TPFIRDD", "DISKUP", "TPFIRUP", "DISKHOLD", 
   "TPFIRDH", "TPFIRLFN", "TPFIRLKY", "TPFISTAT"]

# Lpad 10 spaces 
$ws_vars_common = 
"01 WS-MISC-VAR.\n 05 WS-RESP        PIC S9(4) COMP.\n 05 WS-RESP-CD     PIC S9(4) COMP.\n"

# Lpad 12 spaces before writing.
$ws_vars_05 = 
[ "",
" 05 WS-TPFILOG-PGM      PIC X(08) VALUE 'TPFILOG '.\n",
" 05 KEY-RE72-PREV       PIC X(20).\n 05 WS-FILID-CTL-BR     PIC X(01).\n   88 STARTBR-FILID-CTL   VALUE 'S'.\n   88 ENDBR-FILID-CTL   VALUE 'E'.\n",
" 05 CB300-RECORD-KEY-PREV  PIC X(26).\n 05 WS-FILE-ID-BR        PIC X(01).\n 88 STARTBR-FILE-ID     VALUE 'S'.\n 88 ENDBR-FILE-ID       VALUE 'E'.\n",
" 05 TEMP-AHD-KEY-PREV   PIC X(24).\n 05 WS-TH-FILE-NAME-BR  PIC X(01).\n 88 STARTBR-TH-FILE-NAME   VALUE 'S'.\n 88 ENDBR-TH-FILE-NAME    VALUE 'E'.\n",
" 05 WS-TPFIRDH-PGM      PIC X(08) VALUE 'TPFIRDH '.\n",
" 05 WS-TPFIRLFN-PGM     PIC X(08) VALUE 'TPFIRLFN'.\n",
" 05 WS-TPFIRLKY-PGM     PIC X(08) VALUE 'TPFIRLKY'.\n",
" 05 WS-TPFISTAT-PGM     PIC X(08) VALUE 'TPFISTAT'.\n" ]

$ws_cb = [
"",
"COPY LSTPFIL.\n",
"COPY LSTPFIRH.\n",
"COPY LSFIRLFN.\n",
"COPY LSFIRLKY.\n",
"COPY LSFISTAT.\n" ]

$copybooks = ["", "COPY  LSRESPCD.\n", "COPY  LSRESPCD.\nCOPY  LSTPLOG.\n" ]

$code_hash = nil

$ws_added = false

$stmt_ends_in_dot = false

$parms = Array.new     # paramaters of the CALL stmt

#***********
# Methods
#***********

def pad80( line, existing=false, comment=false )   # existing line?, comment?

  dellTag = "DELLCH"
  char7th = ' '
  char7th = "*" if comment
  
  if existing
    _line = String.new(" " * 80)
    _line.replace( line )
    _line[6] = char7th 
    _line[72..80] = dellTag + "\n"
  else
    line = (' ' * 6) + char7th + ("%-65s" % line) + dellTag + "\n"
    _line = line
  end
  return _line
end

def comment?( line )
  return true if line =~ /^......\*/
  return false
end

##collect parameters of a COBOL CALL stmt
def gather_call_parms( line, p )

   return if line.length < 2      #empty line, just a \n

  _line = line[7..71]

  if _line =~ / USING +.*$/
    $&.split.each do |parm|
      p << parm.tr( "\.", '' )
    end
  else                         # we've past the USING phrase
    _line.split.each do |parm|
      p << parm.tr("\.", '')
    end
  end
  print "DEBUG: gather_call() > #{p}\n" 

  $stmt_ends_in_dot = true if endof_curr_stmt?( _line )
end

def add_ws( old_fname, fd, mods )
  return if $ws_added
  $ws_vars_common.each_line do |line|
      #print "DEBUG:>#{line}<\n"
      fd.write( pad80( line.chomp! ) )
  end
  #add working-storage for all modules found (only once!)
  # 05 level
  ws05_state = Array.new( $ws_vars_05.length )    #to record state of each snippet (written/not written)
  idx = 0
  mods.each do |mod|
    idx = $code_hash[mod]["ws05"].to_i
    if ws05_state[idx].nil?                       
      $ws_vars_05[idx].split("\n").each do |line|
        fd.write( pad80( line ) )
      end
      ws05_state[idx] = 1                       #'idx'th snippet has been written 
    end
  end

  # copybooks
  wscb_state = Array.new( $ws_cb.length )
  idx=0
  mods.each do |mod|
    idx = $code_hash[mod]["ws_cb"].to_i
    if wscb_state[idx].nil?                     #write only if the slot is still nil
      $ws_cb[idx].split("\n").each do |line|
        fd.write( pad80( line ) )
      end
      wscb_state[idx] = 1                      
    end
  end
  $ws_added = true
end

def add_procdiv_code( mod, _parms, f )
  puts "DEBUG: adding proc div code for #{mod}\n"
  #puts "DEBUG: #{ $code_hash[mod]["procdiv"]}\n"

  $code_hash[mod]["procdiv"].split("\n").each do |codeline|
    if codeline =~ /<[0-9]>/
      printf "DEBUG: codeline > %s <\n" % codeline
      codeline.gsub!( $&, _parms[$&.tr("<>", "").to_i] )
      print "DEBUG: add_procdiv(): #{codeline}\n"
    end
    f.write( pad80( codeline ) )
  end
  
  # The fullstop.  Area B!
  f.write( pad80( "   ." ) ) if $stmt_ends_in_dot
  $stmt_ends_in_dot = false

end


def add_copybooks( m, f )
  #currently only a max upto 2 copybooks are to be written.
  #From the hash see if any module needs 2 copybooks, if yes just write it.

  #FIXME: this logic is fragile, and will break if situation changes!

  idx = last_idx = 0
  m.each do |mod| 
    if $code_hash[mod]["cpybk"] > last_idx
      idx = $code_hash[mod]["cpybk"]
      last_idx = idx
    end
  end

  f.write( pad80(" ") )
  $copybooks[idx].split("\n").each do |line|
      f.write( pad80( line ) )
      line=""
  end
end


def endof_curr_stmt?( line )
  #check if the line has a fullstop (end of cobol sentence)
  code_section = line[7..71]
  if code_section =~ /\.[ \t]+/    #if it has a fullstop, then stmt ends here
      puts "DEBUG: stmt ends with a fullstop.\n #{line}\n"
      return true
  end
  return false
end


def startof_new_stmt?( line )
  #If first word on the line is one of the language keywords,
  #Then, this is the start of a new COBOL sentence.

  return false if line.length == 1

  code_section = line[7..71]
  if $cob_kw.include?( code_section.split(' ')[0] )
    return true
   else
    return false
  end
end


def pass1(src, mods_a)
  # make a pass and gather all modules.
  src.each do |line|
    next if comment?( line )
    if line =~ / CALL ['"][A-Z]+['"]/
      foo = $&.split[1].tr("'", "")
      mods_a << foo if $modules.include? foo
    end
  end 
end


def main(src_file)
  require 'json'

  print "DEBUG: ARGV[0] = #{ARGV[0]}\n"
  print "DEBUG: ARGV[1] = #{ARGV[1]}\n"
  
  new_file = File.new("#{src_file}.new", "w")

  orig_file = File.readlines(src_file)

  pass1( orig_file, mods_a=Array.new(0) )
  print "DEBUG: modules #{mods_a} found in Cobol source\n"
  return if mods_a.empty?

  #read static data and build a data structure
  json_file = File.read( ARGV[1]).tr("\n", "" ) 
  $code_hash = JSON.parse( json_file )
  print "DEBUG: json parsing OK.\n" if !$code_hash.nil?

  foo = String.new()    #save module name across iterations
  in_call_stmt = false

  orig_file.each do |line|

    if comment?(line)
      new_file.write( line ) 
      next
    end

    if line =~ /LINKAGE +SECTION *\./ || line =~ /PROCEDURE +DIVISION/
      #add new variables just before
      add_ws( src_file, new_file, mods_a )
      new_file.write( line ) 
      next
    end 

    _line = line.dup
    if line =~ / CALL ['"][A-Z]+['"]/
      #comment this CALL stmt (!! can be spread across 2/more lines)

      foo = $&.split[1].tr( "'", "" )
      if mods_a.include? foo
        in_call_stmt = true
        puts "DEBUG: in a call statement #{foo}\n"
        new_file.write( pad80( _line, true, true) )

        if line =~ / USING /
            gather_call_parms( line, $parms )
        end

        ##if CALL ends in one line, it must have USING as above
        if endof_curr_stmt?(line)      
            add_procdiv_code( foo, $parms, new_file )
            $parms.clear
            in_call_stmt = false
            next
        end
      else          # call stmt not of our interest
        new_file.write( line )
      end

      next  
    end

    if in_call_stmt

      # Check if the the new line is a 
      ## end of current CALL stmt or a 
      ## begining of a new COBOL stmt
      ### because a '.' may not be there at the end.

      if startof_new_stmt?( line )
        in_call_stmt = false
        add_procdiv_code( foo, $parms, new_file )
        $parms.clear
        new_file.write( line )   #write back new line after adding proc div code.
        next
      end

      if endof_curr_stmt?( line ) 
        gather_call_parms( line, $parms )
        printf "DEBUG: $parms > %s <\n" % $parms.to_s
        new_file.write( pad80( _line, true, true) )
        in_call_stmt = false
        add_procdiv_code( foo, $parms, new_file )
        $parms.clear
        next
      end

      in_call_stmt = true    #Still inside a CALL stmt
      gather_call_parms( line, $parms)
      new_file.write( pad80( _line, true, true) )
      next
    end
    
    #All other lines (comments, code) will be written as they are.
    new_file.write( line ) 

  end

  add_copybooks( mods_a, new_file )

end

# ----------
# Execution
# ----------

if 0
 print "need a COBOL source file AND a json data to work with."
 exit false
end if ARGV.length < 2


Dir.chdir(File.dirname(__FILE__))

if File.exists?(ARGV[0]) && File.exists?(ARGV[1])
  main(ARGV[0])
else
  print "File %s not found!\n" % ARGV[0].to_s
end

