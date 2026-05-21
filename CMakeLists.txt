cmake_minimum_required(VERSION 3.28)
project(Sandbox LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

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

# creating library for glew
add_library(GLEW STATIC ${PROJECT_SOURCE_DIR}/external/GLEW/glew.c)
target_include_directories(GLEW PUBLIC ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(GLEW PUBLIC OpenGL::GL)

# building glfw
# add_subdirectory(${PROJECT_SOURCE_DIR}/external/GLFW)

# building src
add_subdirectory(src)
