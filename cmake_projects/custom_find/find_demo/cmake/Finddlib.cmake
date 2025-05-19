# 找 dlib.h
find_path(dlib_INCLUDE_DIR
    NAMES dlib.h
    PATHS /home/hao/installed/test/include
)

# 找 libdlib.so
find_library(dlib_LIBRARY
    NAMES dlib
    PATHS /home/hao/installed/test/lib
)

# 如果dlib.h和libdlib.so都找到了，就设置dlib_FOUND为true
if(dlib_INCLUDE_DIR AND dlib_LIBRARY)
    set(dlib_FOUND TRUE)

    # 设置dlib的版本和作者信息
    set(dlib_VERSION "1.0.0")
    set(dlib_AUTHOR "hao")

    # lib文件所在的目录
    get_filename_component(dlib_LIBRARY_DIR ${dlib_LIBRARY} DIRECTORY)
else()
    set(dlib_FOUND FALSE)
endif()