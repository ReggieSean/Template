cmake_minimum_required(VERSION 3.13)
project(TestDoubleLinkedList)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)

include(FetchContent)
FetchContent_Declare( #declare information about google test
        googletest #its variable name
        #its location on the internet
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master #what branch we want
        )
FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)

endif ()
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})





add_subdirectory(DoublyLinkedList)

add_executable(DoubleLinkedListTester
main.cpp
DoubleLinkedListTest.cpp DoubleLinkedListTest.h)

target_include_directories(DoubleLinkedListTester PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(DoubleLinkedListTester
PRIVATE
DoubleLinkedList
gtest
Threads::Threads)
target_compile_options(DoubleLinkedListTester PRIVATE -Wall -Werror)
