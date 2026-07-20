add_library(shader STATIC shader.cc)
target_include_directories(shader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(shader PUBLIC GLEW OpenGL::GL)

add_library(camera STATIC camera.cc)
target_include_directories(camera PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(camera PUBLIC GLEW OpenGL::GL)

add_executable(sandbox application.cc)
target_link_libraries(sandbox PRIVATE 
    shader
    camera
    glfw 
    GLEW 
    OpenGL::GL
)
target_include_directories(sandbox PRIVATE
    ${PROJECT_SOURCE_DIR}/external/GLM
)
