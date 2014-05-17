;;;; functions for run length encoding. compression & decompression.

;;compression

(defun compress (x)
    (if (consp x)
        (compr (car x) 1 (cdr x))
	x))


(defun compr (elm n lst)
    (if (null lst)
        (list (n-elms elm n))
	(let ((next (car lst)))
	    (if (eql next elm)
	        (compr elm (+ n 1) (cdr lst))
		(cons (n-elms elm n)
		    (compr next 1 (cdr lst)))))))

(defun n-elms (elm n)
    (if (> n 1)
        (list n elm)
	elm))

;;----------------
;;un-compression
;;----------------

(defun uncompress (lst)
    (if (null lst)
        nil
	(let ((elm (car lst))
	    (rest (uncompress (cdr lst))))
	    (if (consp elm)
	        (append (apply #'list-of elm)
		        rest)
                (cons elm rest)))))


(defun list-of (n elm)
    (if (zerop n) nil
        (cons elm (list-of (- n 1) elm))))

