cmake_minimum_required(VERSION 3.26)
project(GraphMaker C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(GraphMaker
        tigr.c
        tigr.h
        Vertex.c
        Vertex.h
        Dijkstra.c
        Dijkstra.h
        Mouse.c
        Mouse.h
        OperationManager.c
        OperationManager.h
        main.c
)
find_package(OpenGL REQUIRED)
target_link_libraries(GraphMaker PRIVATE OpenGL::GL)