cmake_minimum_required(VERSION 3.16)

add_executable(
    main
    src/main.cpp
    src/Map.cpp
    src/Apple.cpp
    src/Snake.cpp
    src/Game.cpp
)

target_include_directories(main PUBLIC ./headers)