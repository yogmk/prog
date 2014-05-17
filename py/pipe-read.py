#! /usr/bin/python

import os

try:
    pipe = os.popen('cat ./sleep.py | pr -2', 'r')

except IOError:
    exit (0)

print pipe.read()

                    