# Add source files for our library
# set(CHECKOUT_SOURCES
#     checkout.cpp)

# Create a new STATIC library! (That is, all the contenet will be compiled, used or not)
add_library(utils 
            INTERFACE)


# Set the directory as public for include -> this way, modules that need to use the header files of this library can access it.
target_include_directories(utils 
                           INTERFACE 
                           ${CMAKE_CURRENT_SOURCE_DIR})
