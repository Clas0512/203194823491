
(cl:in-package :asdf)

(defsystem "calculate_factorial-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "server" :depends-on ("_package_server"))
    (:file "_package_server" :depends-on ("_package"))
  ))