# Add source files for our library
set(CRC_SOURCES
    crc.c
    crc.h)

# Create a new STATIC library! (That is, all the contenet will be compiled, used or not)
add_library(crc
            STATIC
            ${CRC_SOURCES})

target_link_libraries(crc PUBLIC utils)

# # Set the directory as public for include -> this way, modules that need to use the header files of this library can access it.
target_include_directories(crc
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})
