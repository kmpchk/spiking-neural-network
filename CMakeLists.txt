cmake_minimum_required(VERSION 3.8)
project(spiking_neural_network)

set(PROJECT_NAME spiking_neural_network)

###################
## Preprocessing ##
###################

## Decalare a build type
set(CMAKE_BUILD_TYPE Release)

## Compile as C++11
add_compile_options(-std=c++11)

## Libraries
find_package(Boost REQUIRED
  COMPONENTS
    system
    filesystem
    thread
    graph
)

## Grab project files
#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)
set(SOURCE_FILES src/main.cpp)


###########
## Build ##
###########

## Generate the executable file
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

## Specify additional locations of header files
## Your package locations should be listed before other locations
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${Boost_INCLUDE_DIRS}
)

## Link libraries to the executable
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
)
