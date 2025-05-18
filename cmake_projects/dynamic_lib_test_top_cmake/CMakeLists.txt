cmake_minimum_required(VERSION 3.10)

# 在一个cmake文件中完成动态库的生成和链接
project(test_account)

# 设置生成动态库还是静态库
set(BUILD_SHARED_LIBS OFF) # 生成动态库
# set(BUILD_SHARED_LIBS OFF) # 生成静态库

# 添加目标：动态库
add_library(Account 
    account_dir/Account.cpp # 相对于顶层cmake文件的路径
    account_dir/Account.h
)

# 添加可执行文件
add_executable(test_account
    test_account/main.cpp
)

# 添加头文件搜索路径，注意，这里是指定了头文件的搜索路径，而不是动态库的搜索路径
# 动态库搜索路径是：target_link_directories
target_include_directories(test_account PUBLIC
    account_dir/
)

# 添加动态库链接，可执行文件和动态库在同一个路径下，因此不用指定路径
target_link_libraries(test_account PUBLIC
    # ${CMAKE_CURRENT_SOURCE_DIR}/account_dir/
    Account
)

message("是否是Windows系统：${WIN32}")
message("是否是Linux系统：${UNIX}")
message("是否是Mac系统：${APPLE}")
message("当前系统的编译器：${CMAKE_CXX_COMPILER_ID}")
message("当前系统的编译器版本：${CMAKE_CXX_COMPILER_VERSION}")
message("当前系统的编译器路径：${CMAKE_CXX_COMPILER}")
message("系统名称：${CMAKE_SYSTEM_NAME}")