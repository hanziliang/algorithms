cmake_minimum_required (VERSION 2.8)

project (initializer_list)

aux_source_directory(. DIR_SRCS)

include_directories(/usr/local/include /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.1/include /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include)

add_definitions(-std=c++14)

add_executable(initializer_list initializer_list.cpp)


