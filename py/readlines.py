
#import os

#fd = os.open("C\:\\music\\kishore kumar\\linked", "r")

f = open ("C:\\music\\Oldies\\linked", 'r')

lines = f.readlines()

for l in lines:
    print l

#os.close(fd)
