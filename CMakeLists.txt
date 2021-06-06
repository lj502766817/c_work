cmake_minimum_required(VERSION 3.19)
project(demo1 C)

set(CMAKE_C_STANDARD 99)

add_executable(SqeList main.c MyDemo.h)
add_executable(LinkedList LinkedListDemo.c MyLinkedList.h)