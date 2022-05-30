# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/szabolcs/folder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/szabolcs/folder

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/szabolcs/folder/CMakeFiles /home/szabolcs/folder//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/szabolcs/folder/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named runTests

# Build rule for target.
runTests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 runTests
.PHONY : runTests

# fast build rule for target.
runTests/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/build
.PHONY : runTests/fast

class.o: class.cpp.o
.PHONY : class.o

# target to build an object file
class.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/class.cpp.o
.PHONY : class.cpp.o

class.i: class.cpp.i
.PHONY : class.i

# target to preprocess a source file
class.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/class.cpp.i
.PHONY : class.cpp.i

class.s: class.cpp.s
.PHONY : class.s

# target to generate assembly for a file
class.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/class.cpp.s
.PHONY : class.cpp.s

functions.o: functions.cpp.o
.PHONY : functions.o

# target to build an object file
functions.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/functions.cpp.o
.PHONY : functions.cpp.o

functions.i: functions.cpp.i
.PHONY : functions.i

# target to preprocess a source file
functions.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/functions.cpp.i
.PHONY : functions.cpp.i

functions.s: functions.cpp.s
.PHONY : functions.s

# target to generate assembly for a file
functions.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/functions.cpp.s
.PHONY : functions.cpp.s

g_test.o: g_test.cpp.o
.PHONY : g_test.o

# target to build an object file
g_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/g_test.cpp.o
.PHONY : g_test.cpp.o

g_test.i: g_test.cpp.i
.PHONY : g_test.i

# target to preprocess a source file
g_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/g_test.cpp.i
.PHONY : g_test.cpp.i

g_test.s: g_test.cpp.s
.PHONY : g_test.s

# target to generate assembly for a file
g_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/g_test.cpp.s
.PHONY : g_test.cpp.s

storage.o: storage.cpp.o
.PHONY : storage.o

# target to build an object file
storage.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/storage.cpp.o
.PHONY : storage.cpp.o

storage.i: storage.cpp.i
.PHONY : storage.i

# target to preprocess a source file
storage.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/storage.cpp.i
.PHONY : storage.cpp.i

storage.s: storage.cpp.s
.PHONY : storage.s

# target to generate assembly for a file
storage.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/runTests.dir/build.make CMakeFiles/runTests.dir/storage.cpp.s
.PHONY : storage.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... runTests"
	@echo "... class.o"
	@echo "... class.i"
	@echo "... class.s"
	@echo "... functions.o"
	@echo "... functions.i"
	@echo "... functions.s"
	@echo "... g_test.o"
	@echo "... g_test.i"
	@echo "... g_test.s"
	@echo "... storage.o"
	@echo "... storage.i"
	@echo "... storage.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

