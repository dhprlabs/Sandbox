cmake_minimum_required(VERSION 3.28)
project(Sandbox LANGUAGES C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# variables for external source codes
# set(IMGUI_DIR "${PROJECT_SOURCE_DIR}/external/imgui")

# variables for bin and lib output paths
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# set(IMGUI_SOURCES
#     ${IMGUI_DIR}/imgui.cpp
#     ${IMGUI_DIR}/imgui_draw.cpp
#     ${IMGUI_DIR}/imgui_tables.cpp
#     ${IMGUI_DIR}/imgui_widgets.cpp
#     ${IMGUI_DIR}/imgui_demo.cpp
# )

# list(APPEND IMGUI_SOURCES
#     ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
#     ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
# )

add_subdirectory(src)

message(STATUS "main program built successfully")
