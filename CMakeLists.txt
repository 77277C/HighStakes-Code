cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(PROS_Project VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set the toolchain for ARM architecture (PROS toolchain)
set(USER_HOME_DIR $ENV{USERPROFILE})
set(CMAKE_C_COMPILER "${USER_HOME_DIR}/AppData/Roaming/Code/User/globalStorage/sigbots.pros/install/pros-toolchain-windows/usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "${USER_HOME_DIR}/AppData/Roaming/Code/User/globalStorage/sigbots.pros/install/pros-toolchain-windows/usr/bin/arm-none-eabi-g++")

# Add include directories
include_directories(
        ${CMAKE_SOURCE_DIR}
        "${CMAKE_SOURCE_DIR}/include"
        "${CMAKE_SOURCE_DIR}/include/subsystems"
)

# Define preprocessor macros
add_definitions(
        -D_DEBUG
        -DUNICODE
        -D_UNICODE
)

# Specify the compile commands (if relevant for your setup)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the source files for the project
# Add your .cpp and .c files here
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

# Define the executable target
add_executable(PROS_Project ${SOURCES}
        include/subsystems/intake.hpp
        include/subsystems/clamp.hpp
        include/subsystems/doinker.hpp
        include/subsystems/ladybrown.hpp
)

# Optionally, link to external libraries if necessary
# target_link_libraries(PROS_Project <external_libraries>)

# Optionally, configure include directories for browse features (if applicable)
# set(BROWSE_PATH "c:/Users/s-kdabbiru/OneDrive - Lake Washington School District/lib")

# Note: Adjust paths as needed and ensure the toolchain is set up correctly on your system.
