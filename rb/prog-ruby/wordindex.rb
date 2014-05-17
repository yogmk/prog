
class WordIndex
  def initialize
    @index = Hash.new(nil)
  end

  def index(anObject, *phrases)
    phrases.each do |aPhrase|
      aPhrase.scan /\W[-W']+/ do |aWord|
        aWord.downcase!
        @index[aWord] = [] if @index[aWord].nil?
        @index[aWord].push(anObject)
      end
    end
  end

  def lookup(aWord)
    @index[aWord.downcase]
  end

end
