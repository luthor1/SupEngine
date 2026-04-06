cmake_minimum_required(VERSION 3.20)
project(SupEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Disable strict minimum version checks for dependencies on CMake 4+
set(CMAKE_POLICY_DEFAULT_CMP0002 OLD)

# Dependencies
include(FetchContent)

# 1. spdlog (Logging)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(spdlog)

# 2. GLM (Genereic Math for Vulkan)
# GLM is header only. We fetch it and manually add the target to avoid its old CMakeLists.txt issues
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

# 3. GLFW (Windowing API)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

# 4. Vulkan (Find package locally installed by SDK)
find_package(Vulkan REQUIRED)

# Executable
set(SRC_FILES
    src/main.cpp
    src/Core/Application.cpp
    src/Core/Window.cpp
)
add_executable(SupEngine ${SRC_FILES})

# Include directories
target_include_directories(SupEngine PRIVATE include)
target_include_directories(SupEngine PRIVATE ${Vulkan_INCLUDE_DIRS})

# Link libraries
target_link_libraries(SupEngine PRIVATE 
    spdlog::spdlog
    glm::glm
    glfw
    Vulkan::Vulkan
)

# Compiler Warnings (GCC)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(SupEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()
