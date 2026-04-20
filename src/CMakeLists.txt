find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_library(GLEW_SOURCE STATIC ${PROJECT_SOURCE_DIR}/external/GLEW/glew.c)
target_include_directories(GLEW_SOURCE PUBLIC ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(GLEW_SOURCE PUBLIC OpenGL::GL)

add_executable(main 
    main.cc 
    # ${IMGUI_SOURCES}
)

target_include_directories(main PRIVATE
    # ${IMGUI_DIR}
    # ${IMGUI_DIR}/backends
    ${PROJECT_SOURCE_DIR}/external
)

target_link_libraries(main PRIVATE 
    glfw 
    GLEW_SOURCE 
    OpenGL::GL
)