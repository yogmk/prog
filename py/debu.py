#!/usr/bin/python

def addme(number1, number2):
 	"small prog to add 2 numbers"
 	if number1 is not None or number2 is not None:
 		a, b = number1,  number2
 		c = a + b 
		return c


if __name__ == "__main__" :
    print "inside main"
    #print str(addme (5, None))
    print addme (5, 1.0)
    print addme (None, None)
    print addme ("5", "stringaa")
    print addme (5, 1)

    
