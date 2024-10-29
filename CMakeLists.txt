cmake_minimum_required(VERSION 3.20)

project(ChaosCamp2)

set(CMAKE_CXX_STANDARD 20)
message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

file(GLOB_RECURSE ENTRY_TASK_SOURCE_FILES ./EntryTask/src/*.cpp)
file(GLOB_RECURSE ENTRY_TASK_HEADER_FILES ./EntryTask/src/*.h)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(EntryTask ${ENTRY_TASK_SOURCE_FILES} ${ENTRY_TASK_HEADER_FILES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(EntryTask PRIVATE -static-libstdc++)
    target_compile_options(EntryTask PRIVATE -Wall)
    target_compile_options(EntryTask PRIVATE -pedantic)
endif()

