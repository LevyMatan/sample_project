cmake_minimum_required(VERSION 3.17.3)

# project command initialises the ${PROJECT_NAME} variale
project("SampleProject" VERSION 1.0)

enable_testing()

# set the project name and version 
configure_file(SampleProjectConfig.h.in SampleProjectConfig.h)

# target_include_directories(SampleProject PUBLIC "${PROJECT_BINARY_DIR}")

include_directories("${PROJECT_BINARY_DIR}")
# message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
# include_directories(lib/googletest/googlemock/include)
# include_directories(src/utils)

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

OPTION( ENABLE_CODECOVERAGE "Enable code coverage testing support" ON)

if ( ENABLE_CODECOVERAGE )
    message(STATUS "Coverage was enabled")

    if ( NOT CMAKE_BUILD_TYPE STREQUAL "Debug" )
        message( WARNING "Code coverage results with an optimised (non-Debug) build may be misleading" )
    endif ( NOT CMAKE_BUILD_TYPE STREQUAL "Debug" )

    if ( NOT DEFINED CODECOV_OUTPUTFILE )
        set( CODECOV_OUTPUTFILE cmake_coverage.output )
    endif ( NOT DEFINED CODECOV_OUTPUTFILE )

    if ( NOT DEFINED CODECOV_HTMLOUTPUTDIR )
        set( CODECOV_HTMLOUTPUTDIR coverage_results )
    endif ( NOT DEFINED CODECOV_HTMLOUTPUTDIR )

    if ( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCXX )
        message(STATUS "I am GNU compiler")
        find_program( CODECOV_GCOV gcov )
        find_program( CODECOV_LCOV lcov )
        find_program( CODECOV_GENHTML genhtml )
        add_definitions( -fprofile-arcs -ftest-coverage )
        link_libraries( gcov )
        set( CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} --coverage )
        add_custom_target( coverage_init ALL ${CODECOV_LCOV} --base-directory .  --directory ${CMAKE_BINARY_DIR} --output-file ${CODECOV_OUTPUTFILE} --capture --initial )
        add_custom_target( coverage ${CODECOV_LCOV} --base-directory .  --directory ${CMAKE_BINARY_DIR} --output-file ${CODECOV_OUTPUTFILE} --capture COMMAND genhtml -o ${CODECOV_HTMLOUTPUTDIR} ${CODECOV_OUTPUTFILE} )
    endif ( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCXX )

endif (ENABLE_CODECOVERAGE )
