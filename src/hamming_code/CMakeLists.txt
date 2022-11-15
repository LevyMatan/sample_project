# Add source files for our library
set(HAMMING_CODE_SOURCES
    hamming_code.cpp
    hamming_code.hpp)

# Create a new STATIC library! (That is, all the contenet will be compiled, used or not)
add_library(hamming_code
            STATIC
            ${HAMMING_CODE_SOURCES})

target_link_libraries(hamming_code PUBLIC utils)

# Set the directory as public for include -> this way, modules that need to use the header files of this library can access it.
target_include_directories(hamming_code
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})
