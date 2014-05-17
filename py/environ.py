#! /usr/bin/python

import os

for name in os.environ.keys():
    print name + ' -> ' + os.environ[name]

    