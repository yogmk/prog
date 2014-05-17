(defun -copy-list (x)
    (if (atom x)
        x
	(cons (car x) (-copy-list (cdr x)))))

