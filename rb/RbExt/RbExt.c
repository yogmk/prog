# include "ruby.h"

VALUE RubExt = Qnil;

/* proto for init method. Ruby calls this */
void Init_RubExt();

/* proto for our main method. prefix method_ is must. */
VALUE method_foo(VALUE self);

/* Init */

void
Init_RubExt() {
  RubExt = rb_define_module ("RubExt");
  rb_define_method(RubExt, "foo", method_foo, 0);
}


VALUE method_foo (VALUE self)
{
  int x = 10;
  return INT2NUM(x);
}

