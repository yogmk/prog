#! /usr/bin/python

import os

try:
    n = 100
    pipe = os.popen('sed \'s/-/+/g\' > output', 'w')
except IOError:
    exit(0)

while n != 0:
    n -= 1
    pipe.write('---\n')

    