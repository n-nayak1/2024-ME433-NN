# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build"

# Utility rule file for ELF2UF2Build.

# Include any custom commands dependencies for this target.
include project/CMakeFiles/ELF2UF2Build.dir/compiler_depend.make

# Include the progress variables for this target.
include project/CMakeFiles/ELF2UF2Build.dir/progress.make

project/CMakeFiles/ELF2UF2Build: project/CMakeFiles/ELF2UF2Build-complete

project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
project/CMakeFiles/ELF2UF2Build-complete: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E make_directory "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/CMakeFiles"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/CMakeFiles/ELF2UF2Build-complete"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done"

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/elf2uf2" && $(MAKE)

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: project/elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/elf2uf2" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make "-GUnix Makefiles" -S /Users/nikhilnayak/Downloads/pico/pico-sdk/tools/elf2uf2 -B "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/elf2uf2"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/elf2uf2" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure"

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-source_dirinfo.txt
project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download"

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/elf2uf2" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -Dcfgdir= -P "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/tmp/ELF2UF2Build-mkdirs.cmake"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir"

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch-info.txt
project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch"

project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update-info.txt
project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'ELF2UF2Build'"
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E echo_append
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && /opt/homebrew/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update"

ELF2UF2Build: project/CMakeFiles/ELF2UF2Build
ELF2UF2Build: project/CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: project/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: project/CMakeFiles/ELF2UF2Build.dir/build.make
.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
project/CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build
.PHONY : project/CMakeFiles/ELF2UF2Build.dir/build

project/CMakeFiles/ELF2UF2Build.dir/clean:
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" && $(CMAKE_COMMAND) -P CMakeFiles/ELF2UF2Build.dir/cmake_clean.cmake
.PHONY : project/CMakeFiles/ELF2UF2Build.dir/clean

project/CMakeFiles/ELF2UF2Build.dir/depend:
	cd "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test" "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/project" "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build" "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project" "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 16 test/build/project/CMakeFiles/ELF2UF2Build.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : project/CMakeFiles/ELF2UF2Build.dir/depend

