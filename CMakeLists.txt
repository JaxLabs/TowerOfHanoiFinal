cmake_minimum_required(VERSION 3.17)
project(TowerOfHanoiFinal)

set(CMAKE_CXX_STANDARD 14)

add_executable(TowerOfHanoiFinal main.cpp Background.cpp Background.h TextureManager.cpp TextureManager.h StartScreen.cpp StartScreen.h State.cpp State.h Node.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h Color.h Story.cpp Story.h MainGame.cpp MainGame.h Fade.cpp Fade.h MainGameRunning.cpp MainGameRunning.h Disks.cpp Disks.h SetBottle.cpp SetBottle.h)

target_link_libraries(TowerOfHanoiFinal sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
