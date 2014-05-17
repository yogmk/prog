#!/usr/bin/python

import sys
import signal

def int_handler (sig, frame):
    print 'you pressed Ctrl+C'
    sys.exit (0)

def alrm_handler (sig, frame):
    print "alarm BOOOOOOOM!"
    sys.exit (0)

signal.signal(signal.SIGINT, int_handler)
print "you may press Ctrl+C to terminate before alarm sets off!"

signal.signal(signal.SIGALRM, alrm_handler)
signal.alarm(5) # raise SIGALRM ater 7 secs.

n=0
while True:
    #print n
    n += 1
