cmake_minimum_required(VERSION 3.20)
project(Data_Structures_ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structures_ex1
        BinaryTreeAVL/Node.cpp
        BinaryTreeAVL/Node.h
        BinaryTreeAVL/avlTree.cpp
        BinaryTreeAVL/avlTree.h
        BinaryTreeAVL/EmptyTree.cpp
        BinaryTreeAVL/EmptyTree.h
        PlayersTree/PlayerNode.cpp
        PlayersTree/PlayerNode.h
        TeamsTree/TeamNode.cpp
        TeamsTree/TeamNode.h
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h
        LinkedList/LinkedListNode.cpp
        LinkedList/LinkedListNode.h
        main.cpp)