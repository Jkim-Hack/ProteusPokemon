cmake_minimum_required(VERSION 3.15)
project(ProteusPokemon)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProteusPokemon main.cpp World/Tile.cpp World/Tile.h World/Texture.h Player/Player.cpp Player/Player.h Libraries
        Music/Music.cpp World/World.cpp World/World.h Util/PixelLCDConvert.cpp Util/PixelLCDConvert.h)