set(CMAKE_MINIMUM_REQUIRED_VERSION 3.27.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(qic)
add_executable(qic "src/main.cpp" src/libs/HBZPack/hbz.cpp
src/libs/HBZPack/hbz.h src/qic.cpp src/qic.h
src/query.cpp
)
