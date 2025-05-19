cmake_minimum_required(VERSION 3.10)

project(find_demo)

# 添加可执行文件
add_executable(${PROJECT_NAME}
    main.cpp
)

# 寻找gflags库，REQUIRED表示必须找到，否则报错
find_package(gflags REQUIRED)

if(gflags_FOUND)
    message(STATUS "gflags found: ${gflags_INCLUDE_DIRS}")
    message(STATUS "gflags library: ${gflags_LIBRARIES}")

    # 为可执行文件添加头文件目录和库目录
    target_include_directories(${PROJECT_NAME} PRIVATE ${gflags_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${gflags_LIBRARIES})
else()
    message(FATAL_ERROR "gflags not found")
endif()