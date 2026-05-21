add_executable(hello_triangle hello_triangle.cc)
add_executable(two_triangles two_triangles.cc)
add_executable(two_different_buffers two_different_buffers.cc)
add_executable(two_fragment_shaders two_fragment_shaders.cc)

target_link_libraries(hello_triangle PRIVATE 
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

add_library(shader STATIC shader.cc)
target_include_directories(shader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(shader PUBLIC GLEW OpenGL::GL)

add_executable(test_shaders test_shaders.cc)

target_link_libraries(test_shaders PRIVATE 
    shader
    glfw 
    GLEW 
    OpenGL::GL
)

