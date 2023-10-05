; Auto-generated. Do not edit!


(cl:in-package calculate_factorial-srv)


;//! \htmlinclude server-request.msg.html

(cl:defclass <server-request> (roslisp-msg-protocol:ros-message)
  ((number
    :reader number
    :initarg :number
    :type cl:integer
    :initform 0))
)

(cl:defclass server-request (<server-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <server-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'server-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name calculate_factorial-srv:<server-request> is deprecated: use calculate_factorial-srv:server-request instead.")))

(cl:ensure-generic-function 'number-val :lambda-list '(m))
(cl:defmethod number-val ((m <server-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader calculate_factorial-srv:number-val is deprecated.  Use calculate_factorial-srv:number instead.")
  (number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <server-request>) ostream)
  "Serializes a message object of type '<server-request>"
  (cl:let* ((signed (cl:slot-value msg 'number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <server-request>) istream)
  "Deserializes a message object of type '<server-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'number) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<server-request>)))
  "Returns string type for a service object of type '<server-request>"
  "calculate_factorial/serverRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'server-request)))
  "Returns string type for a service object of type 'server-request"
  "calculate_factorial/serverRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<server-request>)))
  "Returns md5sum for a message object of type '<server-request>"
  "e88fc063c14763b6e30c09ed15c1e58c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'server-request)))
  "Returns md5sum for a message object of type 'server-request"
  "e88fc063c14763b6e30c09ed15c1e58c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<server-request>)))
  "Returns full string definition for message of type '<server-request>"
  (cl:format cl:nil "int64 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'server-request)))
  "Returns full string definition for message of type 'server-request"
  (cl:format cl:nil "int64 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <server-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <server-request>))
  "Converts a ROS message object to a list"
  (cl:list 'server-request
    (cl:cons ':number (number msg))
))
;//! \htmlinclude server-response.msg.html

(cl:defclass <server-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:integer
    :initform 0))
)

(cl:defclass server-response (<server-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <server-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'server-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name calculate_factorial-srv:<server-response> is deprecated: use calculate_factorial-srv:server-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <server-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader calculate_factorial-srv:result-val is deprecated.  Use calculate_factorial-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <server-response>) ostream)
  "Serializes a message object of type '<server-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <server-response>) istream)
  "Deserializes a message object of type '<server-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<server-response>)))
  "Returns string type for a service object of type '<server-response>"
  "calculate_factorial/serverResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'server-response)))
  "Returns string type for a service object of type 'server-response"
  "calculate_factorial/serverResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<server-response>)))
  "Returns md5sum for a message object of type '<server-response>"
  "e88fc063c14763b6e30c09ed15c1e58c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'server-response)))
  "Returns md5sum for a message object of type 'server-response"
  "e88fc063c14763b6e30c09ed15c1e58c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<server-response>)))
  "Returns full string definition for message of type '<server-response>"
  (cl:format cl:nil "int64 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'server-response)))
  "Returns full string definition for message of type 'server-response"
  (cl:format cl:nil "int64 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <server-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <server-response>))
  "Converts a ROS message object to a list"
  (cl:list 'server-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'server)))
  'server-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'server)))
  'server-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'server)))
  "Returns string type for a service object of type '<server>"
  "calculate_factorial/server")