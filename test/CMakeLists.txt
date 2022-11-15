set(BINARY ${CMAKE_PROJECT_NAME}_test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

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
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
# target_link_libraries(${BINARY} PUBLIC construct crc best_sum how_sum can_sum grid_traveler fibonacci masking checkout gtest)
