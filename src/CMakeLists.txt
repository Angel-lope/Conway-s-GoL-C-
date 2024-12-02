# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the library for gol4
add_library(gol4_lib SHARED gol/gol4.cpp)

# Add the executable for the main program
add_executable(GameOfLife gol/main.cpp)
target_link_libraries(GameOfLife gol4_lib sfml-system sfml-window sfml-graphics)


