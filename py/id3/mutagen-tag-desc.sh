#!/usr/bin/bash

fms=$(python -c "from mutagen import id3; print [x for x in dir(id3) if x.isupper()]" | sed -n "{
s/'//g
s/,//g
s/\[//g
s/\]//gp
}" )


for frame in $(echo $fms);
do
     echo -n "$frame";
     pydoc mutagen.id3."$frame" | sed -n '4p';
done
