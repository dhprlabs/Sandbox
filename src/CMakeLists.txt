find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# creating library for glew
add_library(GLEW STATIC ${PROJECT_SOURCE_DIR}/external/GLEW/glew.c)
target_include_directories(GLEW PUBLIC ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(GLEW PUBLIC OpenGL::GL)

add_executable(main main.cc)

# target_include_directories(main PRIVATE
#     ${PROJECT_SOURCE_DIR}/external
# )

target_link_libraries(main PRIVATE 
    glfw 
    GLEW 
    OpenGL::GL
)
