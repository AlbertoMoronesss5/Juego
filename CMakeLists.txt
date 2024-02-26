cmake_minimum_required(VERSION 3.27)
project(Jueguito)

set(CMAKE_CXX_STANDARD 17)

include_directories(Character)
include_directories(Enemy)
include_directories(Player)

add_executable(Jueguito
        Character/Character.cpp
        Character/Character.h
        Enemy/Enemy.cpp
        Enemy/Enemy.h
        Player/Player.cpp
        Player/Player.h
        main.cpp)