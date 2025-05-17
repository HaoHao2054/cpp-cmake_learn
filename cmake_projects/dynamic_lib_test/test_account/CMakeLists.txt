cmake_minimum_required(VERSION 3.10)

project(test_account)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(test_account main.cpp)


# 链接静态库

# 为目标文件添加头文件目录
target_include_directories(test_account PUBLIC "../account_dir")
# 添加静态库的路径
target_link_directories(test_account PUBLIC "../account_dir/build")
# 为目标添加静态库
target_link_libraries(test_account PUBLIC Account) # Account是静态库的名称，具体的文件名是libAccount.a