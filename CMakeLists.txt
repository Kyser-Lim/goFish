cmake_minimum_required(VERSION 3.15)
project(goFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(goFish
        card_demo.cpp player.cpp player.h deck.cpp deck.h card.cpp card.h go_fish.cpp)
