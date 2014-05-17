;(defmacro for ((var start stop) &body body)
;(let ((gstop (gensym)))
;  '(do ((,var ,start (1+ ,var))
;        (,gstop ,stop))
;        ((> ,gstop ,stop))
;        ,@body))

(defun minus (x y)
    (+ x y))

(minus 2 3)