# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/angel/miniforge3/envs/gof/bin/cmake

# The command to remove a file.
RM = /home/angel/miniforge3/envs/gof/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/angel/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/angel/project/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_some_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_some_library.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_some_library.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_some_library.dir/flags.make

tests/CMakeFiles/test_some_library.dir/test_main.cpp.o: tests/CMakeFiles/test_some_library.dir/flags.make
tests/CMakeFiles/test_some_library.dir/test_main.cpp.o: /home/angel/project/tests/test_main.cpp
tests/CMakeFiles/test_some_library.dir/test_main.cpp.o: tests/CMakeFiles/test_some_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/angel/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_some_library.dir/test_main.cpp.o"
	cd /home/angel/project/build/tests && /home/angel/miniforge3/envs/gof/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_some_library.dir/test_main.cpp.o -MF CMakeFiles/test_some_library.dir/test_main.cpp.o.d -o CMakeFiles/test_some_library.dir/test_main.cpp.o -c /home/angel/project/tests/test_main.cpp

tests/CMakeFiles/test_some_library.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_some_library.dir/test_main.cpp.i"
	cd /home/angel/project/build/tests && /home/angel/miniforge3/envs/gof/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angel/project/tests/test_main.cpp > CMakeFiles/test_some_library.dir/test_main.cpp.i

tests/CMakeFiles/test_some_library.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_some_library.dir/test_main.cpp.s"
	cd /home/angel/project/build/tests && /home/angel/miniforge3/envs/gof/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angel/project/tests/test_main.cpp -o CMakeFiles/test_some_library.dir/test_main.cpp.s

# Object files for target test_some_library
test_some_library_OBJECTS = \
"CMakeFiles/test_some_library.dir/test_main.cpp.o"

# External object files for target test_some_library
test_some_library_EXTERNAL_OBJECTS =

bin/test_some_library: tests/CMakeFiles/test_some_library.dir/test_main.cpp.o
bin/test_some_library: tests/CMakeFiles/test_some_library.dir/build.make
bin/test_some_library: lib/libgtest_main.a
bin/test_some_library: lib/libgtest.a
bin/test_some_library: tests/CMakeFiles/test_some_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/angel/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_some_library"
	cd /home/angel/project/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_some_library.dir/link.txt --verbose=$(VERBOSE)
	cd /home/angel/project/build/tests && /home/angel/miniforge3/envs/gof/bin/cmake -D TEST_TARGET=test_some_library -D TEST_EXECUTABLE=/home/angel/project/build/bin/test_some_library -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/angel/project/build/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_some_library_TESTS -D CTEST_FILE=/home/angel/project/build/tests/test_some_library[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /home/angel/miniforge3/envs/gof/share/cmake-3.30/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/test_some_library.dir/build: bin/test_some_library
.PHONY : tests/CMakeFiles/test_some_library.dir/build

tests/CMakeFiles/test_some_library.dir/clean:
	cd /home/angel/project/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_some_library.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_some_library.dir/clean

tests/CMakeFiles/test_some_library.dir/depend:
	cd /home/angel/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/angel/project /home/angel/project/tests /home/angel/project/build /home/angel/project/build/tests /home/angel/project/build/tests/CMakeFiles/test_some_library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_some_library.dir/depend
