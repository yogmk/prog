import sys

from optparse import OptionParser

parser = OptionParser()

parser.add_option ("-f", "--filename", dest = "filename", help = "write to file", metavar = "FILE")
parser.add_option ("-q", "--quite", action = "store_false", dest = "verbose", default = True,
                   help = "don't print status messages to stdout")

(options, args) = parser.parse_args()


