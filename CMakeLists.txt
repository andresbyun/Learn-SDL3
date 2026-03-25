cmake_minimum_required (VERSION 3.8)

project ("LearnSDL3")

set(CMAKE_CXX_STANDARD 23)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "src/main.cpp")

# Add packages
find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
