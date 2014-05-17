require "rubygems"

a=['zero',0,'one',1,'two',2,'three',3,'four',4]
b= Array.new

def conv(old, b)
  while old != [] 
    pair=[old.slice!(0,1), old.slice!(0,1)].flatten
    b.push(pair)
    puts "b #{b}"
    conv(old, b)
  end
end

conv(a, b)
puts "Final b #{b}"
