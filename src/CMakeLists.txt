add_library(shader STATIC shader.cc)
target_include_directories(shader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(shader PUBLIC GLEW OpenGL::GL)

add_executable(sandbox application.cc)
target_link_libraries(sandbox PRIVATE 
    glm
    shader
    glfw 
    GLEW 
    OpenGL::GL
)
