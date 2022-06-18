cmake_minimum_required(VERSION 3.20)
project(PDP_8 C)

set(CMAKE_C_STANDARD 99)

add_executable(PDP_8 src/main.c src/Memory.h src/Decoder.h src/Decorder.c src/Memory.c src/ControlUnit.c src/Logic.h src/Arithmetic.h src/Arithmetic.c src/PDP-8.c src/ControlUnit.h src/PDP-8.h src/Logic.c "src/I-O.h" src/I-O.c src/UI.c src/UI.h src/Asembler.c src/Asembler.h src/input.c src/input.h)
