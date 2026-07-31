# Shader Library
add_library(shader STATIC shader.cc)
target_include_directories(shader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(shader PUBLIC GLEW OpenGL::GL glm_headers)

# Camera Library
add_library(camera STATIC camera.cc)
target_include_directories(camera PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(camera PUBLIC GLEW OpenGL::GL glm_headers)

# Mesh Library
add_library(mesh STATIC mesh.cc)
target_include_directories(mesh PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mesh PUBLIC shader GLEW OpenGL::GL glm_headers)

# Model Library
add_library(model STATIC model.cc)
target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(model PUBLIC 
    mesh 
    shader 
    GLEW 
    OpenGL::GL 
    glm_headers 
    assimp::assimp
)

# Main Executable Target
add_executable(sandbox model_loading.cc)
target_link_libraries(sandbox PRIVATE
    model
    camera
    glfw
)
