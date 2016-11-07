cmake_minimum_required(VERSION 2.8)
project(libcrazygoat)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(crazygoat_VERSION_MAJOR 0)
set(crazygoat_VERSION_MINOR 0)
set(crazygoat_VERSION_PATCH 3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Fcgi)

set(SOURCE_FILES
        src/App.cpp
        src/Response.cpp
        src/Request.cpp
        src/Attributes/AttributesList.cpp
        src/Attributes/Attribute.cpp
        src/Filters/Filter.cpp
        src/Array/Array.cpp
        include/crazygoat/Array.h
)

add_library(crazygoat ${SOURCE_FILES})

add_executable(example-hello-world examples/hello/hello-world.cpp)
set_target_properties(example-hello-world PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set_target_properties(example-hello-world PROPERTIES OUTPUT_NAME "hello-world.fcgi")
target_link_libraries(example-hello-world crazygoat ${FCGI_LIBRARY} ${FCGICC_LIBRARY})

add_executable(example-filters examples/hello/filters.cpp)
set_target_properties(example-filters PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set_target_properties(example-filters PROPERTIES OUTPUT_NAME "filters.fcgi")
target_link_libraries(example-filters crazygoat ${FCGI_LIBRARY} ${FCGICC_LIBRARY})

add_executable(example-array examples/array/array.cpp examples/array/array.cpp)
set_target_properties(example-array PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set_target_properties(example-array PROPERTIES OUTPUT_NAME "array")
target_link_libraries(example-array crazygoat ${FCGI_LIBRARY} ${FCGICC_LIBRARY})

install(TARGETS crazygoat DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX} FILES_MATCHING PATTERN "*")
