# Add source files for our library
set(SUM_OF_BEAUTY_SOURCES
    sum_of_beauty.cpp
    sum_of_beauty.hpp)

# Create a new STATIC library! (That is, all the contenet will be compiled, used or not)
add_library(sum_of_beauty
            STATIC
            ${SUM_OF_BEAUTY_SOURCES})


# Set the directory as public for include -> this way, modules that need to use the header files of this library can access it.
target_include_directories(sum_of_beauty
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})
