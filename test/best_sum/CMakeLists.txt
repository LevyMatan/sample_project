get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(EXE_NAME ${DIR_NAME}_test)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")

# message("**--** Test folder CMakeLists.txt **--**")
# message("All test files that are compiled:")
# message("${TEST_SOURCES}")
add_executable(${EXE_NAME}
               ${TEST_SOURCES})


# message("**--** Target binary file: **--** \n${EXE_NAME}")
add_test(NAME ${EXE_NAME} COMMAND ${EXE_NAME})
target_link_libraries(${EXE_NAME} PUBLIC ${DIR_NAME} gtest utils)
