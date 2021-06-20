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

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC masking_lib checkout_lib gtest)
