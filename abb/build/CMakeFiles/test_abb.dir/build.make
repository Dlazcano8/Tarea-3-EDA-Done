# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/diego/eda/t3/abb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/eda/t3/abb/build

# Include any dependencies generated for this target.
include CMakeFiles/test_abb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_abb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_abb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_abb.dir/flags.make

CMakeFiles/test_abb.dir/tests/test.cpp.o: CMakeFiles/test_abb.dir/flags.make
CMakeFiles/test_abb.dir/tests/test.cpp.o: ../tests/test.cpp
CMakeFiles/test_abb.dir/tests/test.cpp.o: CMakeFiles/test_abb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/eda/t3/abb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_abb.dir/tests/test.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_abb.dir/tests/test.cpp.o -MF CMakeFiles/test_abb.dir/tests/test.cpp.o.d -o CMakeFiles/test_abb.dir/tests/test.cpp.o -c /home/diego/eda/t3/abb/tests/test.cpp

CMakeFiles/test_abb.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_abb.dir/tests/test.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/eda/t3/abb/tests/test.cpp > CMakeFiles/test_abb.dir/tests/test.cpp.i

CMakeFiles/test_abb.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_abb.dir/tests/test.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/eda/t3/abb/tests/test.cpp -o CMakeFiles/test_abb.dir/tests/test.cpp.s

CMakeFiles/test_abb.dir/src/abbNode.cpp.o: CMakeFiles/test_abb.dir/flags.make
CMakeFiles/test_abb.dir/src/abbNode.cpp.o: ../src/abbNode.cpp
CMakeFiles/test_abb.dir/src/abbNode.cpp.o: CMakeFiles/test_abb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/eda/t3/abb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_abb.dir/src/abbNode.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_abb.dir/src/abbNode.cpp.o -MF CMakeFiles/test_abb.dir/src/abbNode.cpp.o.d -o CMakeFiles/test_abb.dir/src/abbNode.cpp.o -c /home/diego/eda/t3/abb/src/abbNode.cpp

CMakeFiles/test_abb.dir/src/abbNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_abb.dir/src/abbNode.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/eda/t3/abb/src/abbNode.cpp > CMakeFiles/test_abb.dir/src/abbNode.cpp.i

CMakeFiles/test_abb.dir/src/abbNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_abb.dir/src/abbNode.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/eda/t3/abb/src/abbNode.cpp -o CMakeFiles/test_abb.dir/src/abbNode.cpp.s

CMakeFiles/test_abb.dir/src/abb.cpp.o: CMakeFiles/test_abb.dir/flags.make
CMakeFiles/test_abb.dir/src/abb.cpp.o: ../src/abb.cpp
CMakeFiles/test_abb.dir/src/abb.cpp.o: CMakeFiles/test_abb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/eda/t3/abb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_abb.dir/src/abb.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_abb.dir/src/abb.cpp.o -MF CMakeFiles/test_abb.dir/src/abb.cpp.o.d -o CMakeFiles/test_abb.dir/src/abb.cpp.o -c /home/diego/eda/t3/abb/src/abb.cpp

CMakeFiles/test_abb.dir/src/abb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_abb.dir/src/abb.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/eda/t3/abb/src/abb.cpp > CMakeFiles/test_abb.dir/src/abb.cpp.i

CMakeFiles/test_abb.dir/src/abb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_abb.dir/src/abb.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/eda/t3/abb/src/abb.cpp -o CMakeFiles/test_abb.dir/src/abb.cpp.s

# Object files for target test_abb
test_abb_OBJECTS = \
"CMakeFiles/test_abb.dir/tests/test.cpp.o" \
"CMakeFiles/test_abb.dir/src/abbNode.cpp.o" \
"CMakeFiles/test_abb.dir/src/abb.cpp.o"

# External object files for target test_abb
test_abb_EXTERNAL_OBJECTS =

test_abb: CMakeFiles/test_abb.dir/tests/test.cpp.o
test_abb: CMakeFiles/test_abb.dir/src/abbNode.cpp.o
test_abb: CMakeFiles/test_abb.dir/src/abb.cpp.o
test_abb: CMakeFiles/test_abb.dir/build.make
test_abb: CMakeFiles/test_abb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diego/eda/t3/abb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_abb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_abb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_abb.dir/build: test_abb
.PHONY : CMakeFiles/test_abb.dir/build

CMakeFiles/test_abb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_abb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_abb.dir/clean

CMakeFiles/test_abb.dir/depend:
	cd /home/diego/eda/t3/abb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diego/eda/t3/abb /home/diego/eda/t3/abb /home/diego/eda/t3/abb/build /home/diego/eda/t3/abb/build /home/diego/eda/t3/abb/build/CMakeFiles/test_abb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_abb.dir/depend

