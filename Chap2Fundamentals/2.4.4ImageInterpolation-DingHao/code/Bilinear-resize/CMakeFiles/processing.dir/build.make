# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/dh/program/cmake/DIP/interpolation/double-resize

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dh/program/cmake/DIP/interpolation/double-resize

# Include any dependencies generated for this target.
include CMakeFiles/processing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/processing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processing.dir/flags.make

CMakeFiles/processing.dir/main.cpp.o: CMakeFiles/processing.dir/flags.make
CMakeFiles/processing.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dh/program/cmake/DIP/interpolation/double-resize/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/processing.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processing.dir/main.cpp.o -c /home/dh/program/cmake/DIP/interpolation/double-resize/main.cpp

CMakeFiles/processing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processing.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dh/program/cmake/DIP/interpolation/double-resize/main.cpp > CMakeFiles/processing.dir/main.cpp.i

CMakeFiles/processing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processing.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dh/program/cmake/DIP/interpolation/double-resize/main.cpp -o CMakeFiles/processing.dir/main.cpp.s

CMakeFiles/processing.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/processing.dir/main.cpp.o.requires

CMakeFiles/processing.dir/main.cpp.o.provides: CMakeFiles/processing.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/processing.dir/build.make CMakeFiles/processing.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/processing.dir/main.cpp.o.provides

CMakeFiles/processing.dir/main.cpp.o.provides.build: CMakeFiles/processing.dir/main.cpp.o


# Object files for target processing
processing_OBJECTS = \
"CMakeFiles/processing.dir/main.cpp.o"

# External object files for target processing
processing_EXTERNAL_OBJECTS =

processing: CMakeFiles/processing.dir/main.cpp.o
processing: CMakeFiles/processing.dir/build.make
processing: /usr/local/lib/libopencv_viz.so.3.1.0
processing: /usr/local/lib/libopencv_videostab.so.3.1.0
processing: /usr/local/lib/libopencv_superres.so.3.1.0
processing: /usr/local/lib/libopencv_stitching.so.3.1.0
processing: /usr/local/lib/libopencv_shape.so.3.1.0
processing: /usr/local/lib/libopencv_photo.so.3.1.0
processing: /usr/local/lib/libopencv_objdetect.so.3.1.0
processing: /usr/local/lib/libopencv_calib3d.so.3.1.0
processing: /usr/local/lib/libopencv_features2d.so.3.1.0
processing: /usr/local/lib/libopencv_ml.so.3.1.0
processing: /usr/local/lib/libopencv_highgui.so.3.1.0
processing: /usr/local/lib/libopencv_videoio.so.3.1.0
processing: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
processing: /usr/local/lib/libopencv_flann.so.3.1.0
processing: /usr/local/lib/libopencv_video.so.3.1.0
processing: /usr/local/lib/libopencv_imgproc.so.3.1.0
processing: /usr/local/lib/libopencv_core.so.3.1.0
processing: CMakeFiles/processing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dh/program/cmake/DIP/interpolation/double-resize/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable processing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/processing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processing.dir/build: processing

.PHONY : CMakeFiles/processing.dir/build

CMakeFiles/processing.dir/requires: CMakeFiles/processing.dir/main.cpp.o.requires

.PHONY : CMakeFiles/processing.dir/requires

CMakeFiles/processing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/processing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/processing.dir/clean

CMakeFiles/processing.dir/depend:
	cd /home/dh/program/cmake/DIP/interpolation/double-resize && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dh/program/cmake/DIP/interpolation/double-resize /home/dh/program/cmake/DIP/interpolation/double-resize /home/dh/program/cmake/DIP/interpolation/double-resize /home/dh/program/cmake/DIP/interpolation/double-resize /home/dh/program/cmake/DIP/interpolation/double-resize/CMakeFiles/processing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/processing.dir/depend

