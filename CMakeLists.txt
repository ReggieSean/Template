cmake_minimum_required(VERSION 3.13)
project(DoubleLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_library(DoubleLinkedList INTERFACE)
#add_executable(DoubleLinkedNode.h )
target_sources(DoubleLinkedList INTERFACE
        DoubleLinkedNode.h
        DoublyLinkedList.h
        ConstDoublyLinkedListIterator.h
        DoublyLinkedListIterator.h
        DoublyLinkedListIterator.h
        ConstReverseDoublyLinkedListIterator.h)
target_include_directories(DoubleLinkedList INTERFACE .)
