find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# creating library for glew
add_library(GLEW STATIC ${PROJECT_SOURCE_DIR}/external/GLEW/glew.c)
target_include_directories(GLEW PUBLIC ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(GLEW PUBLIC OpenGL::GL)

add_executable(main main.cc)
add_executable(two_triangles two_triangles.cc)
add_executable(two_different_buffers two_different_buffers.cc)
add_executable(two_fragment_shaders two_fragment_shaders.cc)

target_link_libraries(main PRIVATE 
    glfw 
    GLEW 
    OpenGL::GL
)

target_link_libraries(two_triangles PRIVATE 
    glfw 
    GLEW 
    OpenGL::GL
)

target_link_libraries(two_different_buffers PRIVATE 
    glfw 
    GLEW 
    OpenGL::GL
)

target_link_libraries(two_fragment_shaders PRIVATE 
    glfw 
    GLEW 
    OpenGL::GL
)
