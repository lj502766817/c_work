cmake_minimum_required(VERSION 3.19)
project(demo1 C)

set(CMAKE_C_STANDARD 99)

add_executable(SqeList seqList/main.c seqList/MyDemo.h)
add_executable(LinkedList linkedList/LinkedListDemo.c linkedList/MyLinkedList.h)
add_executable(kmp_demo other/KMP_demo.c)
