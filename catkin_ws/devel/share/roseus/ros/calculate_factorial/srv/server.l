;; Auto-generated. Do not edit!


(when (boundp 'calculate_factorial::server)
  (if (not (find-package "CALCULATE_FACTORIAL"))
    (make-package "CALCULATE_FACTORIAL"))
  (shadow 'server (find-package "CALCULATE_FACTORIAL")))
(unless (find-package "CALCULATE_FACTORIAL::SERVER")
  (make-package "CALCULATE_FACTORIAL::SERVER"))
(unless (find-package "CALCULATE_FACTORIAL::SERVERREQUEST")
  (make-package "CALCULATE_FACTORIAL::SERVERREQUEST"))
(unless (find-package "CALCULATE_FACTORIAL::SERVERRESPONSE")
  (make-package "CALCULATE_FACTORIAL::SERVERRESPONSE"))

(in-package "ROS")





(defclass calculate_factorial::serverRequest
  :super ros::object
  :slots (_number ))

(defmethod calculate_factorial::serverRequest
  (:init
   (&key
    ((:number __number) 0)
    )
   (send-super :init)
   (setq _number (round __number))
   self)
  (:number
   (&optional __number)
   (if __number (setq _number __number)) _number)
  (:serialization-length
   ()
   (+
    ;; int64 _number
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _number
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _number (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _number) (= (length (_number . bv)) 2)) ;; bignum
              (write-long (ash (elt (_number . bv) 0) 0) s)
              (write-long (ash (elt (_number . bv) 1) -1) s))
             ((and (class _number) (= (length (_number . bv)) 1)) ;; big1
              (write-long (elt (_number . bv) 0) s)
              (write-long (if (>= _number 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _number s)(write-long (if (>= _number 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _number
#+(or :alpha :irix6 :x86_64)
      (setf _number (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _number (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass calculate_factorial::serverResponse
  :super ros::object
  :slots (_result ))

(defmethod calculate_factorial::serverResponse
  (:init
   (&key
    ((:result __result) 0)
    )
   (send-super :init)
   (setq _result (round __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; int64 _result
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _result
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _result (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _result) (= (length (_result . bv)) 2)) ;; bignum
              (write-long (ash (elt (_result . bv) 0) 0) s)
              (write-long (ash (elt (_result . bv) 1) -1) s))
             ((and (class _result) (= (length (_result . bv)) 1)) ;; big1
              (write-long (elt (_result . bv) 0) s)
              (write-long (if (>= _result 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _result s)(write-long (if (>= _result 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _result
#+(or :alpha :irix6 :x86_64)
      (setf _result (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _result (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass calculate_factorial::server
  :super ros::object
  :slots ())

(setf (get calculate_factorial::server :md5sum-) "e88fc063c14763b6e30c09ed15c1e58c")
(setf (get calculate_factorial::server :datatype-) "calculate_factorial/server")
(setf (get calculate_factorial::server :request) calculate_factorial::serverRequest)
(setf (get calculate_factorial::server :response) calculate_factorial::serverResponse)

(defmethod calculate_factorial::serverRequest
  (:response () (instance calculate_factorial::serverResponse :init)))

(setf (get calculate_factorial::serverRequest :md5sum-) "e88fc063c14763b6e30c09ed15c1e58c")
(setf (get calculate_factorial::serverRequest :datatype-) "calculate_factorial/serverRequest")
(setf (get calculate_factorial::serverRequest :definition-)
      "int64 number
---
int64 result

")

(setf (get calculate_factorial::serverResponse :md5sum-) "e88fc063c14763b6e30c09ed15c1e58c")
(setf (get calculate_factorial::serverResponse :datatype-) "calculate_factorial/serverResponse")
(setf (get calculate_factorial::serverResponse :definition-)
      "int64 number
---
int64 result

")



(provide :calculate_factorial/server "e88fc063c14763b6e30c09ed15c1e58c")


