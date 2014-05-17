#!/usr/bin/env -ruby

require './wordindex'

class SongList
  MaxTime = 5*60           #  5 minutes

  def initialize
    @songs = Array.new
    @index = WordIndex.new
  end

  def SongList.isTooLong(aSong)
    return aSong.duration > MaxTime
  end

  def append(aSong)
    @songs.push(aSong)
    self
  end

  def deleteFirst
    @songs.shift
  end

  def deleteLast
    @songs.pop
  end

  def [](key)
    return @songs[key] if key.kind_of?(Integer)
    return @songs.find {|aSong| aSong.name == key}
  end

  def append(aSong)
    @songs.push(aSong)
    @index.index(aSong, aSong.name, asong.artist)
  end
    
  def lookup(aWord)
    @index.lookup(aWord)
  end
end
