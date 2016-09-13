cmake_minimum_required(VERSION 3.2)
project(crazygoat)
include( CTest )
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(crazygoat_VERSION_MAJOR 0)
set(crazygoat_VERSION_MINOR 2)
set(crazygoat_VERSION_PATCH 3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Fcgi)

set(SOURCE_FILES src/App.cpp src/App.h src/Response.cpp src/Response.h src/Request.cpp src/Request.h src/Attributes/AttributesList.cpp src/Attributes/AttributesList.cpp src/Attributes/AttributesList.h src/Attributes/Attribute.cpp src/Attributes/Attribute.h src/Filters/Filter.cpp src/Filters/Filter.h)
add_library(crazygoat ${SOURCE_FILES})

add_executable(example-hello-world examples/hello/hello-world.cpp)
set_target_properties(example-hello-world PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/examples")
set_target_properties(example-hello-world PROPERTIES OUTPUT_NAME "hello-world.fcgi")
target_link_libraries(example-hello-world crazygoat ${FCGI_LIBRARY} ${FCGICC_LIBRARY})


add_executable(example-filters examples/hello/filters.cpp)
set_target_properties(example-filters PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/examples")
set_target_properties(example-filters PROPERTIES OUTPUT_NAME "filters.fcgi")
target_link_libraries(example-filters crazygoat ${FCGI_LIBRARY} ${FCGICC_LIBRARY})

install(TARGETS crazygoat DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

add_subdirectory(test)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
"${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${ccframework_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${ccframework_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${ccframework_VERSION_PATCH}")
SET (CPACK_DEBIAN_PACKAGE_MAINTAINER "Piotr Hałas <halaspiotr@gmail.com>") #required
set (CPACK_GENERATOR "DEB")
SET (CPACK_DEBIAN_PACKAGE_DEPENDS "libyaml-cpp0.5, libpcre3, libboost-dev, libfcgi")

set (CPACK_SOURCE_GENERATOR "TGZ")
set (CPACK_SOURCE_PACKAGE_FILE_NAME
"${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set (CPACK_SOURCE_IGNORE_FILES "/_CPack_Packages/;/CMakeFiles/;/.git/;/.osc/;~$;${CPACK_SOURCE_IGNORE_FILES}")
list (APPEND CPACK_SOURCE_IGNORE_FILES ".gitignore")
list (APPEND CPACK_SOURCE_IGNORE_FILES ".tar.gz")
list (APPEND CPACK_SOURCE_IGNORE_FILES ".fcgi")
list (APPEND CPACK_SOURCE_IGNORE_FILES "ccframework.pc$")
list (APPEND CPACK_SOURCE_IGNORE_FILES "libccframework.a")
list (APPEND CPACK_SOURCE_IGNORE_FILES "router-test")
list (APPEND CPACK_SOURCE_IGNORE_FILES "form-test")
list (APPEND CPACK_SOURCE_IGNORE_FILES "request-test")
list (APPEND CPACK_SOURCE_IGNORE_FILES "Makefile")
list (APPEND CPACK_SOURCE_IGNORE_FILES "install_manifest.txt")
list (APPEND CPACK_SOURCE_IGNORE_FILES "CPackSourceConfig.cmake")
list (APPEND CPACK_SOURCE_IGNORE_FILES "CPackConfig.cmake")
list (APPEND CPACK_SOURCE_IGNORE_FILES "cmake_install.cmake")
list (APPEND CPACK_SOURCE_IGNORE_FILES "CMakeCache.txt")
include (CPack)