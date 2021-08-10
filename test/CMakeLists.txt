set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(SOURCES
    main.cpp
    checkout/checkout_test.cpp
    masking/get_rx_tx_mask_test.cpp
    print_file_name/print_file_name_test.cpp
  )

# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

# set(SOURCES ${TEST_SOURCES})
message("Test folder CMakeLists.txt")
message("${SOURCES}")
message("${TEST_SOURCES}")
message("${SOURCES}")
message("${TEST_SOURCES}")
add_executable(${BINARY} ${SOURCES})

message("Add test arguments: ${BINARY}")
add_test(NAME ${BINARY} COMMAND ${BINARY})
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
target_link_libraries(${BINARY} PUBLIC masking checkout gtest)
