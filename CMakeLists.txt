cmake_minimum_required(VERSION 3.16)

project(finpilot VERSION 1.0.0 LANGUAGES CXX)

if(APPLE)
    # Point AGL variables to OpenGL framework to prevent searching for broken AGL
    set(OPENGL_agl_LIBRARY "/System/Library/Frameworks/OpenGL.framework" CACHE FILEPATH "Disable AGL" FORCE)
    set(WrapOpenGL_AGL "/System/Library/Frameworks/OpenGL.framework" CACHE FILEPATH "Disable AGL" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)

include(FetchContent)

FetchContent_Declare(ftxui
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
	GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)


qt_standard_project_setup()

add_subdirectory(src/core)



