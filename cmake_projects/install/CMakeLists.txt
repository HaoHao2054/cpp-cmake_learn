cmake_minimum_required(VERSION 3.10)

project(install_demo)
set(CMAKE_CXX_STANDARD 11)

# 添加公共头文件路径
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 添加静态库
add_library(slib STATIC
    src/slib.cpp
    include/slib.h
)

# 添加动态库
add_library(dlib SHARED
    src/dlib.cpp
    include/dlib.h
)

# 设置安装路径
set(CMAKE_INSTALL_PREFIX "/home/hao/installed/test")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib") 

# 添加可执行文件
add_executable(${PROJECT_NAME}
    main.cpp
)

# 添加链接库
target_link_libraries(${PROJECT_NAME} 
    slib
    dlib
)

# 打印安装路径默认值
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

install(DIRECTORY 
    include/ DESTINATION include
)


# 安装
install(TARGETS ${PROJECT_NAME} slib dlib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)