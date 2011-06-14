(defun Y (A B) (and (A)(B)) )

(defun thunknil ( ) nil)

(defun thunkdiv0 () (/ 1 0) )

(y thunknil thunkdiv0)