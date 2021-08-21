# Add source files for our library
set(UTILS_SOURCES
    matrix.c
    matrix.h
    print_file_name.h)

# Create a new STATIC library! (That is, all the contenet will be compiled, used or not)
add_library(utils 
            STATIC
            ${UTILS_SOURCES})

# Set the directory as public for include -> this way, modules that need to use the header files of this library can access it.
target_include_directories(utils 
                           PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR})
