cmake_minimum_required(VERSION 3.17.3)

# project command initialises the ${PROJECT_NAME} variale
project("SampleProject" VERSION 1.0)

# set the project name and version 
configure_file(SampleProjectConfig.h.in SampleProjectConfig.h)

# target_include_directories(SampleProject PUBLIC "${PROJECT_BINARY_DIR}")

include_directories("${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
include_directories(lib/googletest/googlemock/include)
include_directories(src/include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

# Cretae an excutable, takes two parameters:
# First - executable name
# Second - source file to compile
# In this example, we give the executable the same name as our project
# add_executable(${PROJECT_NAME} main.cpp)

# install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
# install(FILES "main.cpp" DESTINATION src)

# add_subdirectory(adder)

# target_include_directories(${PROJECT_NAME} PRIVATE adder/)
# target_link_libraries(${PROJECT_NAME} adder)
