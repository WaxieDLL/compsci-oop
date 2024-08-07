﻿cmake_minimum_required (VERSION 3.21)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("compsci-oop")

include(FetchContent)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG master)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)
find_package(OpenGL REQUIRED)

FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v1.14.1)
FetchContent_MakeAvailable(spdlog)

file(GLOB SOURCES
    imgui/*.h
    imgui/*.cpp
    "main.cpp"
)

add_executable (${PROJECT_NAME} ${SOURCES}  "gui/window.cpp" "app.cpp" "widgets/impl/navbar.cpp" "dependencies/stb_image.h" "widgets/impl/loaders.cpp" "backend/classes/units/cpoliceunit.cpp" "backend/classes/units/cmedicalunit.cpp" "backend/classes/units/cfireunit.cpp" "backend/classes/calls/cshootingcall.cpp" "backend/classes/calls/cmedicalcall.cpp" "backend/classes/ccallmanager.cpp" "backend/classes/calls/cfirecall.cpp" "backend/classes/calls/cburglarycall.cpp")
include_directories(${PROJECT_NAME} PRIVATE "imgui/")
target_link_libraries(${PROJECT_NAME} PRIVATE glfw ${OPENGL_LIBRARY} spdlog)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()
