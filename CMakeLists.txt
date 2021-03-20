cmake_minimum_required(VERSION 3.17)
project(DataStructAlgorithm C)

set(CMAKE_C_STANDARD 11)
set(
        SOURCE_FILES
        main.c
        sequence_list/sequence_list.c
        sequence_list/sequence_list.h
        common.h
        single_link_list/link_list.c
        single_link_list/link_list.h
        du_link_list/duLinkList.c
        du_link_list/duLinkList.h
        stack_sq/stack.c
        stack_sq/stack.h
        stack_link/stack_link.c
        stack_link/stack_link.h
)

add_executable(DataStructAlgorithm ${SOURCE_FILES})
