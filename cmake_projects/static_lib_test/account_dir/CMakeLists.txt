# 最低版本要求
cmake_minimum_required(VERSION 3.10)

project(account)

# 添加可执行文件
add_library(Account STATIC 
    Account.cpp
)