# call a C function 'inlone' from ruby

require 'rubygems'
require 'inline'

class RubyInlineC
  inline(:C) do | builder|
  builder.c "
  int
  method_foo (void) {
    int x=10;
    /*puts ('This is a C function called from Ruby inline');*/
    return x;
  }"
  end
end

p RubyInlineC.new.method_foo

