# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "calculate_factorial: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(calculate_factorial_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" NAME_WE)
add_custom_target(_calculate_factorial_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "calculate_factorial" "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(calculate_factorial
  "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/calculate_factorial
)

### Generating Module File
_generate_module_cpp(calculate_factorial
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/calculate_factorial
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(calculate_factorial_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(calculate_factorial_generate_messages calculate_factorial_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" NAME_WE)
add_dependencies(calculate_factorial_generate_messages_cpp _calculate_factorial_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(calculate_factorial_gencpp)
add_dependencies(calculate_factorial_gencpp calculate_factorial_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS calculate_factorial_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(calculate_factorial
  "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/calculate_factorial
)

### Generating Module File
_generate_module_eus(calculate_factorial
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/calculate_factorial
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(calculate_factorial_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(calculate_factorial_generate_messages calculate_factorial_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" NAME_WE)
add_dependencies(calculate_factorial_generate_messages_eus _calculate_factorial_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(calculate_factorial_geneus)
add_dependencies(calculate_factorial_geneus calculate_factorial_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS calculate_factorial_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(calculate_factorial
  "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/calculate_factorial
)

### Generating Module File
_generate_module_lisp(calculate_factorial
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/calculate_factorial
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(calculate_factorial_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(calculate_factorial_generate_messages calculate_factorial_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" NAME_WE)
add_dependencies(calculate_factorial_generate_messages_lisp _calculate_factorial_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(calculate_factorial_genlisp)
add_dependencies(calculate_factorial_genlisp calculate_factorial_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS calculate_factorial_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(calculate_factorial
  "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/calculate_factorial
)

### Generating Module File
_generate_module_nodejs(calculate_factorial
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/calculate_factorial
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(calculate_factorial_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(calculate_factorial_generate_messages calculate_factorial_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" NAME_WE)
add_dependencies(calculate_factorial_generate_messages_nodejs _calculate_factorial_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(calculate_factorial_gennodejs)
add_dependencies(calculate_factorial_gennodejs calculate_factorial_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS calculate_factorial_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(calculate_factorial
  "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/calculate_factorial
)

### Generating Module File
_generate_module_py(calculate_factorial
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/calculate_factorial
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(calculate_factorial_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(calculate_factorial_generate_messages calculate_factorial_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/user/catkin_ws/src/calculate_factorial/srv/server.srv" NAME_WE)
add_dependencies(calculate_factorial_generate_messages_py _calculate_factorial_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(calculate_factorial_genpy)
add_dependencies(calculate_factorial_genpy calculate_factorial_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS calculate_factorial_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/calculate_factorial)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/calculate_factorial
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(calculate_factorial_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/calculate_factorial)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/calculate_factorial
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(calculate_factorial_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/calculate_factorial)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/calculate_factorial
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(calculate_factorial_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/calculate_factorial)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/calculate_factorial
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(calculate_factorial_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/calculate_factorial)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/calculate_factorial\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/calculate_factorial
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(calculate_factorial_generate_messages_py std_msgs_generate_messages_py)
endif()
