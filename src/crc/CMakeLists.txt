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










# # set(BINARY ${CMAKE_PROJECT_NAME})

# # file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

# # set(SOURCES ${SOURCES})

# set(MASKING_SOURCES
#     masking/get_rx_tx_mask.c
#     )
# # adding the header files (.h) is need for integration with some IDEs like CLion

# add_library(masking_lib STATIC
#     ${MASKING_SOURCES})

# target_include_directories(masking_lib PUBLIC .)


# # add_executable(${BINARY}_run ${SOURCES})

# # add_library(${BINARY}_lib STATIC ${SOURCES})

# set(BINARY ${CMAKE_PROJECT_NAME})

# # file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

# # set(SOURCES ${SOURCES})

# set(CHECKOUT_SOURCES
#     checkout/checkout.cpp
#     masking/get_rx_tx_mask.c
#     )
# # adding the header files (.h) is need for integration with some IDEs like CLion

# add_library(checkout_lib STATIC
#     ${CHECKOUT_SOURCES})

# target_include_directories(checkout_lib PUBLIC .)


# add_executable(${BINARY}_run main.cpp)

# # add_library(${BINARY}_lib STATIC ${SOURCES})
