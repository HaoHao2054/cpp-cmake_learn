cmake_minimum_required(VERSION 3.10)

project(find_demo)

# 设置CMAKE_MODULE_PATH，添加自定义模块的路径，find_package会从这里查找Findlib.cmake文件
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# 使用find_package查找自定义模块，会从CMAKE_MODULE_PATH中查找
find_package(dlib REQUIRED)

if(dlib_FOUND)
    message(STATUS "dlib found: ${dlib_INCLUDE_DIR}")
    message(STATUS "dlib library: ${dlib_LIBRARY}")
    message(STATUS "dlib version: ${dlib_VERSION}")
    message(STATUS "dlib author: ${dlib_AUTHOR}")
    message(STATUS "dlib lib dir: ${dlib_LIBRARY_DIR}")
else()
    message(FATAL_ERROR "dlib not found")
endif()

# 设置RPATH
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${dlib_LIBRARY_DIR}")

# 添加可执行文件
add_executable(${PROJECT_NAME}
    main.cpp
)

# 添加头文件
target_include_directories(${PROJECT_NAME} PRIVATE
    ${dlib_INCLUDE_DIR}
)

# 链接动态库
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${dlib_LIBRARY}
)