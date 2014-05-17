#!/usr/bin/python

#
# Translate an amount into English words #

def translate(n):
    """
        Translate an amount into English words
    """
    
    if n < 10:       # single digit.
        print last_digit[n]
        return

    result = ""
    tens_ctr = 0

    position = {0:"", 1:"", 2:"hundred", 3:"thousand", 4:"",
                5:"lakh", 6:"", 7:"crore"}
    tens = {1:"", 2:"twenty", 3:"thirty", 4:"forty", 5:"fifty",
            6:"sixty", 7:"seventy", 8:"eighty", 9:"ninety"}

    teens = {11:"eleven", 12:"twelve", 13:"thirteen", 14:"fourteen",
             15:"fifteen", 16:"sixteen", 17:"seventeen", 18:"eighteen",
             19:"nineteen", 20:"twenty"}

    last_digit = {0: "zero", 1: "one", 2: "two", 3: "three",
                  4: "four", 5: "five", 6: "six", 7: "seven",
                  8: "eight", 9: "nine"}

    prev_digit=0

    while n > 0:
        digit = n%10
        if tens_ctr == 1: # we are in tens!
            if digit ==1: # we're in teeens! what was the preious digit?
                result = teens[int(prev_digit)+10]
            else:
                result = tens[digit] + " " + last_digit[prev_digit]
        else:
            result = last_digit[digit] + " " + position[tens_ctr] + " " + result

        prev_digit = digit  # save this for next iteration
        n = n // 10
        tens_ctr += 1

    print result


if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print "translate: needs one argument"

    else:
        translate (sys.argv[1])

# -- end --
