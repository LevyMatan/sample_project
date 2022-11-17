set(BINARY ${CMAKE_PROJECT_NAME}_test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_BUILD_TYPE
    Debug
    CACHE
    STRING
    "Type of build options are Release and Debug"
    FORCE)

message(STATUS "The build option chosen is: ${CMAKE_BUILD_TYPE}")

# Set compilation flags for the project
add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS_DEBUG "-g2 -O0 -DDEBUG_PRINT_ON")
set(CMAKE_CXX_FLAGS_DEBUG "-g2 -O0 -DDEBUG_PRINT_ON")

message(STATUS "The defualt c DEBUG flags are: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "The defualt c RELEASE flags are: ${CMAKE_CXX_FLAGS_RELEASE}")

add_subdirectory(construct)
add_subdirectory(crc)
add_subdirectory(best_sum)
add_subdirectory(how_sum)
add_subdirectory(can_sum)
add_subdirectory(grid_traveler)
add_subdirectory(fibonacci)
add_subdirectory(checkout)
add_subdirectory(masking)
add_subdirectory(print_file_name)
add_subdirectory(longest_perfect_piece)
add_subdirectory(sum_of_beauty)

# target_link_libraries(${BINARY} PUBLIC construct crc best_sum how_sum can_sum grid_traveler fibonacci masking checkout gtest)

# include_directories(${CMAKE_SOURCE_DIR}/src/utils)

# set(TEST_SOURCES
#     main.cpp
#     construct/construct_test.cpp
#     crc/crc_test.cpp
#     best_sum/best_sum_test.cpp
#     how_sum/how_sum_test.cpp
#     can_sum/can_sum_test.cpp
#     grid_traveler/grid_traveler_test.cpp
#     fibonacci/fibonacci_test.cpp
#     checkout/checkout_test.cpp
#     masking/get_rx_tx_mask_test.cpp
#     print_file_name/print_file_name_test.cpp
#   )

# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

# set(SOURCES ${TEST_SOURCES})
# message("**--** Test folder CMakeLists.txt **--**")
# message("All test files that are compiled:")
# message("${TEST_SOURCES}")
# add_executable(${BINARY} ${TEST_SOURCES})

# message("")

# message("**--** Target binary file: **--** \n${BINARY}")
# add_test(NAME ${BINARY} COMMAND ${BINARY})
# target_link_libraries(${BINARY} PUBLIC construct crc best_sum how_sum can_sum grid_traveler fibonacci masking checkout gtest)
