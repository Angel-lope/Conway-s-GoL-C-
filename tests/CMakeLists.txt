include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)


# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

add_executable(test_gol4 ${CMAKE_SOURCE_DIR}/tests/test_gol4.cpp)

# Set the SFML directory 
set(SFML_DIR "${CMAKE_SOURCE_DIR}/include/SFML")

# Find SFML 
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
# Link against any required libraries. The library "some_library" is compiled in src/
target_link_libraries(
  test_gol4
  gol4_lib
  GTest::gtest_main
  sfml-system 
  sfml-window 
  sfml-graphics
  udev
)


# Discover the tests in both test executables            
gtest_discover_tests(test_gol4) # Register the tests to gtest