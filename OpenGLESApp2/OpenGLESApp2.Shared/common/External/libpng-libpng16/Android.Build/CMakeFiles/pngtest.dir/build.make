# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\source\repos\External\libpng-libpng16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\source\repos\External\libpng-libpng16\Android.Build

# Include any dependencies generated for this target.
include CMakeFiles/pngtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pngtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pngtest.dir/flags.make

CMakeFiles/pngtest.dir/pngtest.c.o: CMakeFiles/pngtest.dir/flags.make
CMakeFiles/pngtest.dir/pngtest.c.o: ../pngtest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\source\repos\External\libpng-libpng16\Android.Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pngtest.dir/pngtest.c.o"
	c:\Microsoft\AndroidNDK64\toolchain\bin\arm-linux-androideabi-gcc.exe --sysroot=c:/Microsoft/AndroidNDK64/toolchain/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pngtest.dir\pngtest.c.o   -c C:\Users\Administrator\source\repos\External\libpng-libpng16\pngtest.c

CMakeFiles/pngtest.dir/pngtest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pngtest.dir/pngtest.c.i"
	c:\Microsoft\AndroidNDK64\toolchain\bin\arm-linux-androideabi-gcc.exe --sysroot=c:/Microsoft/AndroidNDK64/toolchain/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Administrator\source\repos\External\libpng-libpng16\pngtest.c > CMakeFiles\pngtest.dir\pngtest.c.i

CMakeFiles/pngtest.dir/pngtest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pngtest.dir/pngtest.c.s"
	c:\Microsoft\AndroidNDK64\toolchain\bin\arm-linux-androideabi-gcc.exe --sysroot=c:/Microsoft/AndroidNDK64/toolchain/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Administrator\source\repos\External\libpng-libpng16\pngtest.c -o CMakeFiles\pngtest.dir\pngtest.c.s

# Object files for target pngtest
pngtest_OBJECTS = \
"CMakeFiles/pngtest.dir/pngtest.c.o"

# External object files for target pngtest
pngtest_EXTERNAL_OBJECTS =

pngtest: CMakeFiles/pngtest.dir/pngtest.c.o
pngtest: CMakeFiles/pngtest.dir/build.make
pngtest: libpng16d.so
pngtest: c:/Microsoft/AndroidNDK64/toolchain/sysroot/usr/lib/libz.so
pngtest: c:/Microsoft/AndroidNDK64/toolchain/sysroot/usr/lib/libm.so
pngtest: CMakeFiles/pngtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\source\repos\External\libpng-libpng16\Android.Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pngtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pngtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pngtest.dir/build: pngtest

.PHONY : CMakeFiles/pngtest.dir/build

CMakeFiles/pngtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pngtest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pngtest.dir/clean

CMakeFiles/pngtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\source\repos\External\libpng-libpng16 C:\Users\Administrator\source\repos\External\libpng-libpng16 C:\Users\Administrator\source\repos\External\libpng-libpng16\Android.Build C:\Users\Administrator\source\repos\External\libpng-libpng16\Android.Build C:\Users\Administrator\source\repos\External\libpng-libpng16\Android.Build\CMakeFiles\pngtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pngtest.dir/depend
