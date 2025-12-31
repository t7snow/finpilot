cmake_minimum_required(VERSION 3.16)
project(finpilot VERSION 1.0.0 LANGUAGES CXX)

if(APPLE)
    set(OPENGL_agl_LIBRARY "/System/Library/Frameworks/OpenGL.framework" CACHE FILEPATH "Disable AGL" FORCE)
    set(WrapOpenGL_AGL "/System/Library/Frameworks/OpenGL.framework" CACHE FILEPATH "Disable AGL" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

qt_standard_project_setup()
file(GLOB_RECURSE CORE_SOURCES "src/core/*.cpp" "src/core/*.h")
file(GLOB_RECURSE UI_SOURCES "src/ui/*.cpp" "src/ui/*.hpp" )
qt_add_executable(finpilot
    ${CORE_SOURCES}
    ${UI_SOURCES}
)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_include_directories(finpilot PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ui"
)

target_link_libraries(finpilot PRIVATE 
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Sql
    ftxui::screen
    ftxui::dom
    ftxui::component
)
