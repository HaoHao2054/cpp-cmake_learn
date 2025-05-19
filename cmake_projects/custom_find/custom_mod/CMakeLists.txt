cmake_minimum_required(VERSION 3.10)

project(custom_mod)

# 添加动态库
add_library(dlib SHARED
    src/dlib.cpp
)

# 添加头文件路径
target_include_directories(dlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/
)

# 设置公共头文件
set_target_properties(dlib PROPERTIES
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/inc/dlib.h"
)

set(CMAKE_INSTALL_PREFIX "/home/hao/installed/test")

# 设置安装
install(TARGETS dlib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)