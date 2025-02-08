cmake_minimum_required(VERSION 3.12)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
endif ()

project (mspcrt C)

option(BUILD_SHARED_LIBS "shared/static libs" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (MSVC)
    add_compile_options(/W4)
endif()

set(headers dirent/dirent.h misc/libgen.h misc/mspcrt.h posix/getopt.h posix/unistd.h)
set(sys_headers time/sys/time.h)
set(sources
    dirent/dirent.c
    dirent/wdirent.c
    libio/pclose.c
    libio/popen.c
    login/getlogin.c
    misc/dirname.c
    misc/tdelete.c
    misc/tdestroy.c
    misc/tfind.c
    misc/tsearch.c
    misc/twalk.c
    misc/usleep.c
    posix/getopt.c
    posix/sleep.c
    time/gettimeofday.c)

add_library(mspcrt ${sources})

# Correctly export the location of installed includes in the target
target_include_directories(mspcrt PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/dirent;${PROJECT_SOURCE_DIR}/misc;${PROJECT_SOURCE_DIR}/posix;${PROJECT_SOURCE_DIR}/time>"
    )

# set shared mode for compiling library and propagate mode to cmake clients
if (BUILD_SHARED_LIBS)
    target_compile_definitions(mspcrt PUBLIC PCRT_SHARED)
    target_compile_definitions(mspcrt PUBLIC DLL_EXPORT)
endif ()

install (TARGETS mspcrt
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install (FILES ${headers} DESTINATION include)
install (FILES ${sys_headers} DESTINATION include/sys)
