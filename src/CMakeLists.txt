add_executable(main main.cc ${IMGUI_SOURCES})

target_include_directories(main PRIVATE 
    ${IMGUI_DIR} 
    ${IMGUI_DIR}/backends
)   

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(main PRIVATE glfw OpenGL::GL)
