#!/usr/bin/ruby -w

# open a file
# read each line
# search for match
# if found, replace the text
# write to new file
# close file 

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

begin
  ofs=File.open(filename+".new", "w")
rescue
  puts "Couldn't open <#{filename}> for writing. Exiting.."
#ensure
  ifs.close 
  exit
end

rx=Regexp.new(/\, *FILES\=[0-9]/)                         

ifs.each do |line|

  if line =~ /^[^*].*SORT *FIELDS\=.*\, *FILES\=[0-9]/               # match?
    line.chomp!
    line << ' ' * (80 - line.length) if line.length < 80 
    ofs.write("*#{line[1..71]}TI0739\n")                      # comment & write
    md=line.match(rx)
    line.sub!(rx, ' ' * md.to_s.length)                       # sub pattern with space
    line[72..80]="TI0739\n"                                   # paste 'tag'
  end

  ofs.write line

end

ifs.close
ofs.close

#--end
