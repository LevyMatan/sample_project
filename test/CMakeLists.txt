set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(TEST_SOURCES
    main.cpp
    grid_traveler/grid_traveler_test.cpp
    fibonacci/fibonacci_test.cpp
    checkout/checkout_test.cpp
    masking/get_rx_tx_mask_test.cpp
    print_file_name/print_file_name_test.cpp
  )

# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

# set(SOURCES ${TEST_SOURCES})
message("**--** Test folder CMakeLists.txt **--**")
message("All test files that are compiled:")
message("${TEST_SOURCES}")
add_executable(${BINARY} ${TEST_SOURCES})

message("")

message("**--** Target binary file: **--** \n${BINARY}")
add_test(NAME ${BINARY} COMMAND ${BINARY})
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
target_link_libraries(${BINARY} PUBLIC grid_traveler fibonacci masking checkout gtest)
