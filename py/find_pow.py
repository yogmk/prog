#!/usr/bin/env python

def find_pow(n):
    """find out how many bits (power of 2) are needed to hold 'n'"""
    c=2
    p=1  # we'd always maintain c=2^p
    while (c<n):
        print "DEBUG: c=",c, "p=",p
        p = p+1
        c = c<<p

    print "number ", n, "needs ", p, "bits."


if "__name__" == "__main__":
    import sys
    find_pow(sys.argv[1])
             