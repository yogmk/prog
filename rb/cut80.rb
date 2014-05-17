#!/usr/bin/ruby -w


# scan & strip lines from given files
# cobol,jcl,cards, proc, cpy etc
# to 80 bytes limit. If space is found
# after 80th bytes, strip it. If text is
# found, log & notify it.


filename=ARGV[0]
if filename == nil or File.exists?(filename) == false 
  puts "Not a valid file" 
  exit
end
  
begin
  ifs=File.open(filename, "r")
rescue
  puts "Couldn't open <#{filename}> for reading. Exiting.." 
  exit
end

#begin
#  ofs=File.open(filename+".new", "w")
#rescue
#  puts "Couldn't open <#{filename}> for writing. Exiting.."
##ensure
#  ifs.close 
#  exit
#end
#

ifs.each do |$_|

  $_.chomp!
  ln = $_.length
  if ln >= 81 
    $stdout.printf "%s:%s:%s\n", ARGV[0], $..to_s, ln.to_s
    #if $_.slice(80..-1) =~ /^ *$/           #whitespace? strip
      $_.slice!(80..-1)
    #end

  end
  #puts $_ + '|'
#  ofs.write $_

end

ifs.close
#ofs.close

#--end
