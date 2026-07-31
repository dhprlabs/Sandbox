cmake_minimum_required(VERSION 3.12) 
project(Sandbox LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# ---------------------------------------------------------------------------
# External Packages (System Installed)
# ---------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(assimp REQUIRED) 

# ---------------------------------------------------------------------------
# External Vendors / Subdirectories (In-Project Dependencies)
# ---------------------------------------------------------------------------

add_library(GLEW STATIC ${PROJECT_SOURCE_DIR}/external/GLEW/glew.c)
target_include_directories(GLEW PUBLIC ${PROJECT_SOURCE_DIR}/external/GLEW/GL)
target_link_libraries(GLEW PUBLIC OpenGL::GL)

add_library(glm_headers INTERFACE)
target_include_directories(glm_headers INTERFACE ${PROJECT_SOURCE_DIR}/external/GLM)

# ---------------------------------------------------------------------------
# Source Directory
# ---------------------------------------------------------------------------
add_subdirectory(src)
