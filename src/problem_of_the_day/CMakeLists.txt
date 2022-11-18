# Add source files for our library
set(PROBLEM_OF_THE_DAY_SOURCES
    geeks_for_geeks.cpp
    geeks_for_geeks.hpp)

# Create a new STATIC library! (That is, all the contenet will be compiled, used or not)
add_library(problem_of_the_day
            STATIC
            ${PROBLEM_OF_THE_DAY_SOURCES})

# Add utilstousethe debug library
target_link_libraries(problem_of_the_day PUBLIC utils)

# Set the directory as public for include -> this way, modules that need to use the header files of this library can access it.
target_include_directories(problem_of_the_day
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})
