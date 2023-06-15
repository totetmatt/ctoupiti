cmake_minimum_required(VERSION 3.1...3.25)
project(
	ctoupiti
	VERSION 0.1.0
	LANGUAGES C
)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_RELEASE "-O3")


execute_process(COMMAND shader_minifier.exe --aggressive-inlining  -o shaders.h --format c-variables --no-renaming vert.glsl frag.glsl compute.glsl)

# Include glfw directory, to define the 'glfw' target
add_subdirectory(glfw)

add_executable(App
	main.c
)

# Add the 'glfw' target as a dependency of our App
target_link_libraries(App PRIVATE glfw)
# set_target_properties(App PROPERTIES CXX_STANDARD 17)
