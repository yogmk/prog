#!/usr/bin/ruby

class Song
  @@plays = 0                          # total songs played

  def initialize(name, artist, duration)
    @name = name
    @artist = artist
    @duration = duration
    @plays = 0                         # how many times this song played?
  end

  def to_s
    "song: #@artist - #@name (#@duration)"
  end

  attr_reader :name, :artist, :duration

  def durationInMinutes                # virtual attribute
    @duration/60.0
  end

  attr_writer :duration

  def durationInMinutes=(value)        # virtual attribute
    @duration = (value*60).to_i
  end

  def play
    @@plays += 1
    @plays += 1
    "This song #@plays plays, total #@@plays songs played."
  end

  include Comparable

  def <=>(other)
    self.duration <=> other.duration
  end
end


class KaraokeSong < Song
  def initialize(name, artist, duration, lyrics)
    super(name, artist, duration)
    @lyrics=lyrics
  end

  def to_s
    super + "#@lyrics"
  end

end

