SET(execName call_function)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(${execName})

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

include_directories("/usr/local/Aria/include") #ARIA

link_directories("/usr/local/Aria/lib") #ARIA

FILE(GLOB_RECURSE SRC_FILES "main.cpp")

ADD_EXECUTABLE(${execName} ${SRC_FILES})

TARGET_LINK_LIBRARIES(${execName}
  libAria.so libpthread.so libdl.so librt.so #ARIA
)