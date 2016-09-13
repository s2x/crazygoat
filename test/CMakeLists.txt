add_test(simpleTest "${CMAKE_SOURCE_DIR}/bin/test/test-hello-world")

add_executable(test-request-hello test-request-hello.cpp)
set_target_properties(test-request-hello PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/test")
set_target_properties(test-request-hello PROPERTIES OUTPUT_NAME "test-hello-world")
target_link_libraries(test-request-hello crazygoat ${FCGI_LIBRARY} ${FCGICC_LIBRARY})