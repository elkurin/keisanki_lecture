(defun matrix (i)
 
 (setf a_size (expt 2 i))
 (setf a (make-array '(a_size a_size) :initial-element 1))
 (setf ans (make-array '(a_size a_size) :initial-element 0))

(setq start (get-internal-real-time))

(loop for x from 0 to (- a_size 1) do
	(loop for y from 0 to (- a_size 1) do
		(loop for z from 0 to (- a_size 1) do
			(setf (aref ans x y) (+ (aref ans x y) (* (aref a x z) (aref a z y)))))))
	

(setq end (get-internal-real-time))

(print (float (/ (- end start) (* 1000000 a_size a_size a_size)))))

(defun matrix_repeat(n)
 (loop for i from 0 to 9 do
	(matrix i)))
