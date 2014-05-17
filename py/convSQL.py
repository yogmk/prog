#!/usr/bin/env python

import re

def convSQL (fname):
    
    import os.path
    if not os.path.exists(fname):
        print "Could not find: %s" % fname
        return
    

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print "This python script needs a filename argument"
        exit
    else:
        convSQL (sys.argv[1])

# --end--        