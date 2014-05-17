
# singleton class. new() is pvt.
# caution! this impl is not thread safe.
#
class Logger
  private_class_method :new
  @@logger = nil

  def Logger.create
    @@logger = new unless @@logger
    @logger
  end
end

