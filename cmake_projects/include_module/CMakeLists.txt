cmake_minimum_required(VERSION 3.10)

project(include_demo)

include("${CMAKE_CURRENT_SOURCE_DIR}/module_1/module_1.cmake")

message("打印module_1中的变量：${MODULE_1_VAR}")

message("执行完了")