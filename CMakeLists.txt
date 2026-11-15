cmake_minimum_required(VERSION 4.4)
project(Ray_Tracer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ray_Tracer src/main.cpp
        src/Vector3D.cpp
        src/Vector3D.h
        src/Ray.cpp
        src/Ray.h
)
