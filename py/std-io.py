import sys
import re

data = sys.stdin.readlines()
#while True:
    #data = sys.stdin.readline()
    #data = sys.stdin.read(256)
if data != '':
        #data = '#' + data
        data = re.sub('[A-Z]', '=', str(data))
        sys.stdout.write(data)
else:
        sys.stdout.flush()
#        break
