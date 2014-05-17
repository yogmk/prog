
require "mp3info"

Mp3Info.open("/home/ymk/Desktop/posters/abba-sos.mp3") do |mp3info|
puts mp3info
end

   # read/write tag1 and tag2 with Mp3Info#tag attribute
   # when reading tag2 have priority over tag1
   # when writing, each tag is written.
Mp3Info.open("/home/ymk/Desktop/posters/abba-sos.mp3") do |mp3|
   puts mp3.tag.title   
   puts mp3.tag.artist   
   puts mp3.tag.album
   puts mp3.tag.tracknum
   # mp3.tag.title = "track title"
   #   mp3.tag.artist = "artist name"
end

# tags are written when calling Mp3Info#close or at the end of the #open block

### access id3v2 tags

Mp3Info.open("/home/ymk/Desktop/posters/abba-sos.mp3")do |mp3|
	# you can access four letter v2 tags like this
	puts mp3.tag2.TIT2
	mp3.tag2.TIT2 = "new TIT2"
	# or like that
	mp3.tag2["TIT2"]
	# at this time, only COMM tag is processed after reading and before writing
	# according to ID3v2#options hash
	mp3.tag2.options[:lang] = "FRE"
	mp3.tag2.COMM = "my comment in french, correctly handled when reading and writing"
end

