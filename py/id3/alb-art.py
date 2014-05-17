#!/usr/bin/python

from mutagen.id3 import ID3, APIC, COMM

def add_alb_art(filename, picture):
    """
    adds (embeds) the given picture as
    album art (Cover) in the mp3 file.
    """
    audio = ID3(filename)
    apic = audio.getall('APIC')
    
    if apic != None:
        print "File <%s> has album art present."%filename
        apic.__str__()
        sys.exit(-1)


if __name__ == "__main__":
    import sys

    if len(sys.argv) < 2:
       print "Need 2 parameters. MP3 filename and album picture."
       sys.exit() 
    else:
       import os
       if not os.path.isfile(sys.argv[1]):
           print "Error: < %s >file not found."% sys.argv[1]
           sys.exit()
       if not os.path.isfile(sys.argv[2]):
           print "Error: < %s >file not found."% sys.argv[2]
           sys.exit()
       
       add_alb_art(sys.argv[1], sys.argv[2]) 
