# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\mirel\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\mirel\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\Programiranje\PDP-8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\Programiranje\PDP-8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PDP_8.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PDP_8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PDP_8.dir/flags.make

CMakeFiles/PDP_8.dir/src/main.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PDP_8.dir/src/main.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\main.c.obj -c H:\Programiranje\PDP-8\src\main.c

CMakeFiles/PDP_8.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/main.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\main.c > CMakeFiles\PDP_8.dir\src\main.c.i

CMakeFiles/PDP_8.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/main.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\main.c -o CMakeFiles\PDP_8.dir\src\main.c.s

CMakeFiles/PDP_8.dir/src/Decorder.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/Decorder.c.obj: ../src/Decorder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/PDP_8.dir/src/Decorder.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\Decorder.c.obj -c H:\Programiranje\PDP-8\src\Decorder.c

CMakeFiles/PDP_8.dir/src/Decorder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/Decorder.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\Decorder.c > CMakeFiles\PDP_8.dir\src\Decorder.c.i

CMakeFiles/PDP_8.dir/src/Decorder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/Decorder.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\Decorder.c -o CMakeFiles\PDP_8.dir\src\Decorder.c.s

CMakeFiles/PDP_8.dir/src/Memory.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/Memory.c.obj: ../src/Memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/PDP_8.dir/src/Memory.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\Memory.c.obj -c H:\Programiranje\PDP-8\src\Memory.c

CMakeFiles/PDP_8.dir/src/Memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/Memory.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\Memory.c > CMakeFiles\PDP_8.dir\src\Memory.c.i

CMakeFiles/PDP_8.dir/src/Memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/Memory.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\Memory.c -o CMakeFiles\PDP_8.dir\src\Memory.c.s

CMakeFiles/PDP_8.dir/src/ControlUnit.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/ControlUnit.c.obj: ../src/ControlUnit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/PDP_8.dir/src/ControlUnit.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\ControlUnit.c.obj -c H:\Programiranje\PDP-8\src\ControlUnit.c

CMakeFiles/PDP_8.dir/src/ControlUnit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/ControlUnit.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\ControlUnit.c > CMakeFiles\PDP_8.dir\src\ControlUnit.c.i

CMakeFiles/PDP_8.dir/src/ControlUnit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/ControlUnit.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\ControlUnit.c -o CMakeFiles\PDP_8.dir\src\ControlUnit.c.s

CMakeFiles/PDP_8.dir/src/Arithmetic.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/Arithmetic.c.obj: ../src/Arithmetic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/PDP_8.dir/src/Arithmetic.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\Arithmetic.c.obj -c H:\Programiranje\PDP-8\src\Arithmetic.c

CMakeFiles/PDP_8.dir/src/Arithmetic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/Arithmetic.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\Arithmetic.c > CMakeFiles\PDP_8.dir\src\Arithmetic.c.i

CMakeFiles/PDP_8.dir/src/Arithmetic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/Arithmetic.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\Arithmetic.c -o CMakeFiles\PDP_8.dir\src\Arithmetic.c.s

CMakeFiles/PDP_8.dir/src/PDP-8.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/PDP-8.c.obj: ../src/PDP-8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/PDP_8.dir/src/PDP-8.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\PDP-8.c.obj -c H:\Programiranje\PDP-8\src\PDP-8.c

CMakeFiles/PDP_8.dir/src/PDP-8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/PDP-8.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\PDP-8.c > CMakeFiles\PDP_8.dir\src\PDP-8.c.i

CMakeFiles/PDP_8.dir/src/PDP-8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/PDP-8.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\PDP-8.c -o CMakeFiles\PDP_8.dir\src\PDP-8.c.s

CMakeFiles/PDP_8.dir/src/Logic.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/Logic.c.obj: ../src/Logic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/PDP_8.dir/src/Logic.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\Logic.c.obj -c H:\Programiranje\PDP-8\src\Logic.c

CMakeFiles/PDP_8.dir/src/Logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/Logic.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\Logic.c > CMakeFiles\PDP_8.dir\src\Logic.c.i

CMakeFiles/PDP_8.dir/src/Logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/Logic.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\Logic.c -o CMakeFiles\PDP_8.dir\src\Logic.c.s

CMakeFiles/PDP_8.dir/src/I-O.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/I-O.c.obj: ../src/I-O.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/PDP_8.dir/src/I-O.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\I-O.c.obj -c H:\Programiranje\PDP-8\src\I-O.c

CMakeFiles/PDP_8.dir/src/I-O.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/I-O.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\I-O.c > CMakeFiles\PDP_8.dir\src\I-O.c.i

CMakeFiles/PDP_8.dir/src/I-O.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/I-O.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\I-O.c -o CMakeFiles\PDP_8.dir\src\I-O.c.s

CMakeFiles/PDP_8.dir/src/UI.c.obj: CMakeFiles/PDP_8.dir/flags.make
CMakeFiles/PDP_8.dir/src/UI.c.obj: ../src/UI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/PDP_8.dir/src/UI.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PDP_8.dir\src\UI.c.obj -c H:\Programiranje\PDP-8\src\UI.c

CMakeFiles/PDP_8.dir/src/UI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PDP_8.dir/src/UI.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Programiranje\PDP-8\src\UI.c > CMakeFiles\PDP_8.dir\src\UI.c.i

CMakeFiles/PDP_8.dir/src/UI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PDP_8.dir/src/UI.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Programiranje\PDP-8\src\UI.c -o CMakeFiles\PDP_8.dir\src\UI.c.s

# Object files for target PDP_8
PDP_8_OBJECTS = \
"CMakeFiles/PDP_8.dir/src/main.c.obj" \
"CMakeFiles/PDP_8.dir/src/Decorder.c.obj" \
"CMakeFiles/PDP_8.dir/src/Memory.c.obj" \
"CMakeFiles/PDP_8.dir/src/ControlUnit.c.obj" \
"CMakeFiles/PDP_8.dir/src/Arithmetic.c.obj" \
"CMakeFiles/PDP_8.dir/src/PDP-8.c.obj" \
"CMakeFiles/PDP_8.dir/src/Logic.c.obj" \
"CMakeFiles/PDP_8.dir/src/I-O.c.obj" \
"CMakeFiles/PDP_8.dir/src/UI.c.obj"

# External object files for target PDP_8
PDP_8_EXTERNAL_OBJECTS =

PDP_8.exe: CMakeFiles/PDP_8.dir/src/main.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/Decorder.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/Memory.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/ControlUnit.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/Arithmetic.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/PDP-8.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/Logic.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/I-O.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/src/UI.c.obj
PDP_8.exe: CMakeFiles/PDP_8.dir/build.make
PDP_8.exe: CMakeFiles/PDP_8.dir/linklibs.rsp
PDP_8.exe: CMakeFiles/PDP_8.dir/objects1.rsp
PDP_8.exe: CMakeFiles/PDP_8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable PDP_8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PDP_8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PDP_8.dir/build: PDP_8.exe
.PHONY : CMakeFiles/PDP_8.dir/build

CMakeFiles/PDP_8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PDP_8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PDP_8.dir/clean

CMakeFiles/PDP_8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\Programiranje\PDP-8 H:\Programiranje\PDP-8 H:\Programiranje\PDP-8\cmake-build-debug H:\Programiranje\PDP-8\cmake-build-debug H:\Programiranje\PDP-8\cmake-build-debug\CMakeFiles\PDP_8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PDP_8.dir/depend

