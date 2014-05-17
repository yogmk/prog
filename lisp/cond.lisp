#! /usr/bin/clisp --script

(let ((a 1)
      (b 2)
      (c 1)
      (d 1))
  (cond ( (eql a b) 1)
        ( (eql a c) "first form" 2)
        ( (eql a d) 3)))
