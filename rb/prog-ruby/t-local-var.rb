#!/usr/bin/ruby

count=0
arr=[]

10.times do |i|
  arr[i] = Thread.new {
    sleep(rand(0)/10.0)
    Thread.current["myCount"] = count
    count += 1
    }
end

arr.each { | t|
  t.join
  print t["myCount"], ", "
}

puts "count= #{count}"

