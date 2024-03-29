cmake_minimum_required(VERSION 3.5)
project(SampleProject LANGUAGES C CXX)

set(SAMPLE_PROJECT_SOURCES
    main.c)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE
        Release
        CACHE
        STRING
        "Type of build options are Release and Debug"
        FORCE)

endif()
message(STATUS "The build option chosen is: ${CMAKE_BUILD_TYPE}")

# Set compilation flags for the project
add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS_DEBUG "-g2 -O0 -DDEBUG_PRINT_ON")
set(CMAKE_CXX_FLAGS_DEBUG "-g2 -O0 -DDEBUG_PRINT_ON")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
message(STATUS "The defualt c DEBUG flags are: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "The defualt c RELEASE flags are: ${CMAKE_CXX_FLAGS_RELEASE}")

# Add sub-directory, that contains the utilities library
# include_directories(utils)
add_subdirectory(crc)
add_subdirectory(utils)
add_subdirectory(construct)
add_subdirectory(can_sum)
add_subdirectory(how_sum)
add_subdirectory(best_sum)
add_subdirectory(fibonacci)
add_subdirectory(grid_traveler)
add_subdirectory(masking)
add_subdirectory(checkout)
add_subdirectory(longest_perfect_piece)
add_subdirectory(sum_of_beauty)
add_subdirectory(problem_of_the_day)

set(ProjectExecutable ${CMAKE_PROJECT_NAME}_run)
add_executable(${ProjectExecutable}
               ${SAMPLE_PROJECT_SOURCES})

# target_link_libraries(${ProjectExecutable} PUBLIC masking)
# target_link_libraries(${ProjectExecutable} PUBLIC checkout)
# target_link_libraries(${ProjectExecutable} PUBLIC utils)
# target_link_libraries(sample_project INTERFACE utils)

# message(STATUS "Linking ${CMAKE_PROJECT_NAME} to ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

#Cahche rules!
# if a variable was already set, it won't be set again!
# set(INSTALL_LOCATION "/usr" CACHE STRING "Install location for stuff")
# set(INSTALL_LOCATION "/opt" CACHE STRING "")
# message(STATUS "Stuff will be installed to: ${INSTALL_LOCATION}")

# set(INSTALL_LOCATION "/usr" CACHE STRING "Install location for stuff")
# set(INSTALL_LOCATION "/opt" CACHE STRING "Install location for stuff" FORCE)
# message(STATUS "Stuff will be installed to: ${INSTALL_LOCATION}")

# set(INSTALL_LOCATION "/usr")
# set(INSTALL_LOCATION "/opt" CACHE STRING "Install location for stuff")
# message(STATUS "Stuff will be installed to: ${INSTALL_LOCATION}")

string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_UCASE)
# message(DEPRECATION ">> C++ Compile Flags (for ${CMAKE_BUILD_TYPE}): \
# ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE_UCASE}}")
