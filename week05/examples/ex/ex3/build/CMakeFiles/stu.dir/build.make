# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build

# Include any dependencies generated for this target.
include CMakeFiles/stu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stu.dir/flags.make

CMakeFiles/stu.dir/main.cpp.o: CMakeFiles/stu.dir/flags.make
CMakeFiles/stu.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stu.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stu.dir/main.cpp.o -c /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/main.cpp

CMakeFiles/stu.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stu.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/main.cpp > CMakeFiles/stu.dir/main.cpp.i

CMakeFiles/stu.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stu.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/main.cpp -o CMakeFiles/stu.dir/main.cpp.s

CMakeFiles/stu.dir/src/stdfun.cpp.o: CMakeFiles/stu.dir/flags.make
CMakeFiles/stu.dir/src/stdfun.cpp.o: ../src/stdfun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stu.dir/src/stdfun.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stu.dir/src/stdfun.cpp.o -c /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/src/stdfun.cpp

CMakeFiles/stu.dir/src/stdfun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stu.dir/src/stdfun.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/src/stdfun.cpp > CMakeFiles/stu.dir/src/stdfun.cpp.i

CMakeFiles/stu.dir/src/stdfun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stu.dir/src/stdfun.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/src/stdfun.cpp -o CMakeFiles/stu.dir/src/stdfun.cpp.s

# Object files for target stu
stu_OBJECTS = \
"CMakeFiles/stu.dir/main.cpp.o" \
"CMakeFiles/stu.dir/src/stdfun.cpp.o"

# External object files for target stu
stu_EXTERNAL_OBJECTS =

stu: CMakeFiles/stu.dir/main.cpp.o
stu: CMakeFiles/stu.dir/src/stdfun.cpp.o
stu: CMakeFiles/stu.dir/build.make
stu: CMakeFiles/stu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stu.dir/build: stu

.PHONY : CMakeFiles/stu.dir/build

CMakeFiles/stu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stu.dir/clean

CMakeFiles/stu.dir/depend:
	cd /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3 /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3 /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build /home/water/桌面/c++_yushiqi/CPP/week05/examples/ex/ex3/build/CMakeFiles/stu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stu.dir/depend
