cmake_minimum_required(VERSION 3.12)
project(AyumuGame)

set(CMAKE_CXX_STANDARD 11)
add_compile_options( -m32 )
link_libraries(gdi32 bgi comdlg32 uuid oleaut32 ole32)
add_executable(AyumuGame tinythread.cpp main.cpp)
