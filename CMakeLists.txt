# DISTRHO Plugin Framework (DPF)
# Copyright (C) 2022 falkTX <falktx@falktx.com>
# SPDX-License-Identifier: ISC

cmake_minimum_required(VERSION 3.7)

set(NAME imgui-demo-app)
project(${NAME})

add_subdirectory(dpf)

# target either cairo or opengl
#dpf__add_dgl_cairo()
dpf__add_dgl_opengl()

# define target executable
add_executable("${NAME}")
target_sources("${NAME}" PRIVATE "main.cpp")
target_sources("${NAME}" PRIVATE "${PROJECT_SOURCE_DIR}/dpf-widgets/opengl/DearImGui.cpp")

target_include_directories("${NAME}" PUBLIC "${DPF_ROOT_DIR}/distrho")
target_include_directories("${NAME}" PUBLIC "${DPF_ROOT_DIR}/dgl")
target_include_directories("${NAME}" PUBLIC "${PROJECT_SOURCE_DIR}/dpf-widgets/opengl")

target_link_libraries("${NAME}" PRIVATE dgl-opengl)
target_link_libraries("${NAME}" PUBLIC dgl-opengl-definitions dgl-system-libs-definitions)

if((NOT WIN32) AND (NOT APPLE) AND (NOT HAIKU))
    target_link_libraries("${NAME}" PRIVATE "dl")
endif()
if(MINGW)
    target_link_libraries("${NAME}" PRIVATE "-static")
endif()
