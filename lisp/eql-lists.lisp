(defun eql-lists? (x y)
    (or (eq x y)
        (and (consp x)
	     (consp y)
	     (eql-lists? (car x) (car y))
	     (eql-lists? (cdr x) (cdr y)))))

