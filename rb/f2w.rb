#!/usr/bin/ruby

##
## translate an amount in English words
##


# Globals
$ones = {0=>"", 1=>"one", 2=>"two", 3=>"three", 4=>"four", 5=>"five", 6=>"six", 7=>"seven", 8=>"eight", 9=>"nine"}

$tens = {1=>"ten", 2=>"twenty", 3=>"thirty", 4=>"forty", 5=>"fifty", 6=>"sixty", 7=>"seventy", 8=>"eighty", 9=>"ninety"}

$teens = {0=>'ten', 1=>'eleven', 2=>'twelve', 3=>'thirteen', 4=>'fourteen', 5=>'fifteen', 6=>'sixteen', 7=>'seventeen', 8=>'eighteen', 9=>'nineteen'}

$position = {0=>'', 1=>'', 2=>'hundred', 3=>'thousand', 4=>'', 5=>'lakh', 6=>'', 7=>'crore'}


def translate(n)
  result=""
  position_idx = 0
  prev_digit = 0
  
  while n > 0
    digit = n%10
    case position_idx
    when 0
      result = $ones[digit]
    when 1    ## tens
      if digit == 1   # 11...20 (teens!)
        result = $teens[prev_digit]
      else            # twenties and up
        result = $tens[digit] + " " + $ones[prev_digit]
      end
    when 2    ## hundreds
      if digit != 0   # avoid 'zero hundred'
        result = $ones[digit] + " " + $position[position_idx] + " " + result  
      end
    when 3,5,7 ## thousands and >
      result = $ones[digit] + " " + $position[position_idx] + " " + result
      ## look ahead if a 'tens' digit is present
    when 4,6,8
      # evaluate the digit alongwith prev. and overwrite
      if digit == 1   # teens
        a = $teens[prev_digit]
      else
        a = $tens[digit] + $ones[prev_digit]
      end

      result.gsub!(/^\w+/, a + $position[position_idx])
    end
 
    n = n/10
    position_idx += 1
    prev_digit = digit
  end
  
  return result
end


if ARGV.length < 1
  puts "f2w: need a number to translate."
else
  puts translate(ARGV[0].to_i)
end
