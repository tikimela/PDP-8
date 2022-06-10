cmake_minimum_required(VERSION 3.20)
project(PDP_8 C)

set(CMAKE_C_STANDARD 99)

add_executable(PDP_8 src/main.c src/Memory.h src/Decoder.h src/Decorder.c src/Memory.c src/ControlUnit.c src/PDP-8.h src/logic.h src/ALU.h src/ALU.c)
