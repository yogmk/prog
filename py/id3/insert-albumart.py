#!/usr/bin/python

from mutagen.mp3 import MP3
from mutagen.id3 import ID3, APIC, error


debug = 1

def insert_picture(mp3, picture):
    audio = MP3(mp3, ID3=ID3)
    
    # add ID3 tag if it doesn't exist
    try:
        audio.add_tags()
    except error:
        print "Tag exists.\n %s"% error
        pass
    
    audio.tags.add(
        APIC(
            encoding=3,          # 3 is for utf-8
            mime='image/jpeg',   # image/jpeg or image/png
            type=3,              # 3 is for the cover image
            desc=u'Cover',
            data=open(picture).read()
        )
    )
    audio.save()


if __name__ == "__main__":
    import sys

    if len(sys.argv) < 2:
       print "Need 2 parameters. MP3 file and album picture."
       sys.exit() 
    else:
       import os
       if not os.path.isfile(sys.argv[1]):
           print "Error: < %s >file not found."% sys.argv[1]
           sys.exit()
       if not os.path.isfile(sys.argv[2]):
           print "Error: < %s >file not found."% sys.argv[2]
           sys.exit()

       if debug: print "calling insert_picture()" 
       insert_picture(sys.argv[1], sys.argv[2]) 
