(defun stack(n)
(setf a ((lambda (x) (make-array x :initial-element 1)) ((lambda (y) (expt 2 y)) n)))
(setq sum 0)
(setq start (get-internal-real-time))

(setq m (- ((lambda (x) (expt 2 x)) n) 1))

(loop for i from 0 to m do
	((lambda (x) (+ sum (aref x i))) a )
)
(setq end (get-internal-real-time))

(print (float (/ (- end start) )))
)


(defun stack_repeat(n)
(loop for i from 4 to 20 do
	(stack i)
)
)
