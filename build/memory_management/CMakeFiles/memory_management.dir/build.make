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
CMAKE_SOURCE_DIR = /home/furkan/Desktop/job_in_point/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/furkan/Desktop/job_in_point/build

# Include any dependencies generated for this target.
include memory_management/CMakeFiles/memory_management.dir/depend.make

# Include the progress variables for this target.
include memory_management/CMakeFiles/memory_management.dir/progress.make

# Include the compile flags for this target's objects.
include memory_management/CMakeFiles/memory_management.dir/flags.make

memory_management/CMakeFiles/memory_management.dir/src/memory_management.cpp.o: memory_management/CMakeFiles/memory_management.dir/flags.make
memory_management/CMakeFiles/memory_management.dir/src/memory_management.cpp.o: /home/furkan/Desktop/job_in_point/src/memory_management/src/memory_management.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/furkan/Desktop/job_in_point/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object memory_management/CMakeFiles/memory_management.dir/src/memory_management.cpp.o"
	cd /home/furkan/Desktop/job_in_point/build/memory_management && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memory_management.dir/src/memory_management.cpp.o -c /home/furkan/Desktop/job_in_point/src/memory_management/src/memory_management.cpp

memory_management/CMakeFiles/memory_management.dir/src/memory_management.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memory_management.dir/src/memory_management.cpp.i"
	cd /home/furkan/Desktop/job_in_point/build/memory_management && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/furkan/Desktop/job_in_point/src/memory_management/src/memory_management.cpp > CMakeFiles/memory_management.dir/src/memory_management.cpp.i

memory_management/CMakeFiles/memory_management.dir/src/memory_management.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memory_management.dir/src/memory_management.cpp.s"
	cd /home/furkan/Desktop/job_in_point/build/memory_management && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/furkan/Desktop/job_in_point/src/memory_management/src/memory_management.cpp -o CMakeFiles/memory_management.dir/src/memory_management.cpp.s

# Object files for target memory_management
memory_management_OBJECTS = \
"CMakeFiles/memory_management.dir/src/memory_management.cpp.o"

# External object files for target memory_management
memory_management_EXTERNAL_OBJECTS =

/home/furkan/Desktop/job_in_point/devel/lib/libmemory_management.so: memory_management/CMakeFiles/memory_management.dir/src/memory_management.cpp.o
/home/furkan/Desktop/job_in_point/devel/lib/libmemory_management.so: memory_management/CMakeFiles/memory_management.dir/build.make
/home/furkan/Desktop/job_in_point/devel/lib/libmemory_management.so: memory_management/CMakeFiles/memory_management.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/furkan/Desktop/job_in_point/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/furkan/Desktop/job_in_point/devel/lib/libmemory_management.so"
	cd /home/furkan/Desktop/job_in_point/build/memory_management && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memory_management.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
memory_management/CMakeFiles/memory_management.dir/build: /home/furkan/Desktop/job_in_point/devel/lib/libmemory_management.so

.PHONY : memory_management/CMakeFiles/memory_management.dir/build

memory_management/CMakeFiles/memory_management.dir/clean:
	cd /home/furkan/Desktop/job_in_point/build/memory_management && $(CMAKE_COMMAND) -P CMakeFiles/memory_management.dir/cmake_clean.cmake
.PHONY : memory_management/CMakeFiles/memory_management.dir/clean

memory_management/CMakeFiles/memory_management.dir/depend:
	cd /home/furkan/Desktop/job_in_point/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/furkan/Desktop/job_in_point/src /home/furkan/Desktop/job_in_point/src/memory_management /home/furkan/Desktop/job_in_point/build /home/furkan/Desktop/job_in_point/build/memory_management /home/furkan/Desktop/job_in_point/build/memory_management/CMakeFiles/memory_management.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : memory_management/CMakeFiles/memory_management.dir/depend

