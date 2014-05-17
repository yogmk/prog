#!/usr/bin/env python

#--------------------------------------------------
# Translate an amount into English words.
# Amount is rendered in Indian units (lac, Crore), 
# and not in western (million, billion) units.
#
# author: yo-gi@in.com
# Date: 5.7.2010
#--------------------------------------------------

position = {0:"", 1:"hundred", 2:"thousand", 3:"lac", 4:"crore"}

tens = {1:"ten", 2:"twenty", 3:"thirty", 4:"forty", 5:"fifty",
        6:"sixty", 7:"seventy", 8:"eighty", 9:"ninety"}

teens = {10:"ten", 11:"eleven", 12:"twelve", 13:"thirteen",
         14:"fourteen", 15:"fifteen", 16:"sixteen",
         17:"seventeen", 18:"eighteen", 19:"nineteen"}

last_digit = {0:"", 1: "one", 2: "two", 3: "three", 4: "four",
              5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}

def get_number (n):
    print "DEBUG: get_number(%s)" % n
    if n < 10:
        return last_digit[n]
    
    d = n%10
    ret = last_digit[d]
    n = n // 10
    if n == 0:
        return ""
    elif n == 1:     # teens!
        ret = teens[d+10]
    else:
        ret = tens[n] + ret

    print "DEBUG: ret %s" %(ret)
    return ret

def translate(n):       # n->amount
    """
        Translate an amount into English words
    """

    result = ""
    pos_ctr = 0        
    
    while n > 0:
        if pos_ctr == 1:       # hundreds. special case for indian measuring
            digit = n%10
            n = n // 10
        else:
            digit = n%100      # always take a group of 2 digits (hundreds) (Indian style)
            n = n // 100

        print "DEBUG: pos %i, %i %s" % (pos_ctr, digit, position[pos_ctr])

        tmp_result = get_number(digit)
        
        if "" != tmp_result:
            result = tmp_result + " " + position[pos_ctr] + " " + result

        pos_ctr += 1

    print result    

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print "translate: needs one integer argument"
    else:
        translate (int(sys.argv[1]))
# --end--
