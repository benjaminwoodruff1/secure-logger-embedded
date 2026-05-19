# This CMake config configures the component library

# Specify list of sources for the component library
set (lib${CMAKE_PROJECT_NAME}_src
    ${PROJECT_SOURCE_DIR}/src/${CMAKE_PROJECT_NAME}/${CMAKE_PROJECT_NAME}.cpp
    ${PROJECT_SOURCE_DIR}/src/${CMAKE_PROJECT_NAME}/${CMAKE_PROJECT_NAME}.c
)

# Add the library, which will take the name "lib${CMAKE_PROJECT_NAME}"
# This is configured as a dynamic library here, but can be changed
add_library(${CMAKE_PROJECT_NAME} SHARED ${lib${CMAKE_PROJECT_NAME}_src})

# Add the component include directory to the include path when compiling
# the library target itself
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/src/include")
