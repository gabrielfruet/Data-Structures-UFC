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
CMAKE_SOURCE_DIR = /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/tarefa1.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa1.cpp.o: ../tarefa1.cpp
CMakeFiles/main.dir/tarefa1.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/tarefa1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa1.cpp.o -MF CMakeFiles/main.dir/tarefa1.cpp.o.d -o CMakeFiles/main.dir/tarefa1.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa1.cpp

CMakeFiles/main.dir/tarefa1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa1.cpp > CMakeFiles/main.dir/tarefa1.cpp.i

CMakeFiles/main.dir/tarefa1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa1.cpp -o CMakeFiles/main.dir/tarefa1.cpp.s

CMakeFiles/main.dir/tarefa2.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa2.cpp.o: ../tarefa2.cpp
CMakeFiles/main.dir/tarefa2.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/tarefa2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa2.cpp.o -MF CMakeFiles/main.dir/tarefa2.cpp.o.d -o CMakeFiles/main.dir/tarefa2.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa2.cpp

CMakeFiles/main.dir/tarefa2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa2.cpp > CMakeFiles/main.dir/tarefa2.cpp.i

CMakeFiles/main.dir/tarefa2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa2.cpp -o CMakeFiles/main.dir/tarefa2.cpp.s

CMakeFiles/main.dir/tarefa3.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa3.cpp.o: ../tarefa3.cpp
CMakeFiles/main.dir/tarefa3.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/tarefa3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa3.cpp.o -MF CMakeFiles/main.dir/tarefa3.cpp.o.d -o CMakeFiles/main.dir/tarefa3.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa3.cpp

CMakeFiles/main.dir/tarefa3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa3.cpp > CMakeFiles/main.dir/tarefa3.cpp.i

CMakeFiles/main.dir/tarefa3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa3.cpp -o CMakeFiles/main.dir/tarefa3.cpp.s

CMakeFiles/main.dir/tarefa4.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa4.cpp.o: ../tarefa4.cpp
CMakeFiles/main.dir/tarefa4.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/tarefa4.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa4.cpp.o -MF CMakeFiles/main.dir/tarefa4.cpp.o.d -o CMakeFiles/main.dir/tarefa4.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa4.cpp

CMakeFiles/main.dir/tarefa4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa4.cpp > CMakeFiles/main.dir/tarefa4.cpp.i

CMakeFiles/main.dir/tarefa4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa4.cpp -o CMakeFiles/main.dir/tarefa4.cpp.s

CMakeFiles/main.dir/tarefa5.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa5.cpp.o: ../tarefa5.cpp
CMakeFiles/main.dir/tarefa5.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/tarefa5.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa5.cpp.o -MF CMakeFiles/main.dir/tarefa5.cpp.o.d -o CMakeFiles/main.dir/tarefa5.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa5.cpp

CMakeFiles/main.dir/tarefa5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa5.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa5.cpp > CMakeFiles/main.dir/tarefa5.cpp.i

CMakeFiles/main.dir/tarefa5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa5.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa5.cpp -o CMakeFiles/main.dir/tarefa5.cpp.s

CMakeFiles/main.dir/tarefa6.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa6.cpp.o: ../tarefa6.cpp
CMakeFiles/main.dir/tarefa6.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/tarefa6.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa6.cpp.o -MF CMakeFiles/main.dir/tarefa6.cpp.o.d -o CMakeFiles/main.dir/tarefa6.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa6.cpp

CMakeFiles/main.dir/tarefa6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa6.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa6.cpp > CMakeFiles/main.dir/tarefa6.cpp.i

CMakeFiles/main.dir/tarefa6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa6.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa6.cpp -o CMakeFiles/main.dir/tarefa6.cpp.s

CMakeFiles/main.dir/tarefa7.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa7.cpp.o: ../tarefa7.cpp
CMakeFiles/main.dir/tarefa7.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/tarefa7.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa7.cpp.o -MF CMakeFiles/main.dir/tarefa7.cpp.o.d -o CMakeFiles/main.dir/tarefa7.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa7.cpp

CMakeFiles/main.dir/tarefa7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa7.cpp > CMakeFiles/main.dir/tarefa7.cpp.i

CMakeFiles/main.dir/tarefa7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa7.cpp -o CMakeFiles/main.dir/tarefa7.cpp.s

CMakeFiles/main.dir/tarefa8.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa8.cpp.o: ../tarefa8.cpp
CMakeFiles/main.dir/tarefa8.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/tarefa8.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa8.cpp.o -MF CMakeFiles/main.dir/tarefa8.cpp.o.d -o CMakeFiles/main.dir/tarefa8.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa8.cpp

CMakeFiles/main.dir/tarefa8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa8.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa8.cpp > CMakeFiles/main.dir/tarefa8.cpp.i

CMakeFiles/main.dir/tarefa8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa8.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa8.cpp -o CMakeFiles/main.dir/tarefa8.cpp.s

CMakeFiles/main.dir/tarefa9.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tarefa9.cpp.o: ../tarefa9.cpp
CMakeFiles/main.dir/tarefa9.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.dir/tarefa9.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/tarefa9.cpp.o -MF CMakeFiles/main.dir/tarefa9.cpp.o.d -o CMakeFiles/main.dir/tarefa9.cpp.o -c /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa9.cpp

CMakeFiles/main.dir/tarefa9.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tarefa9.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa9.cpp > CMakeFiles/main.dir/tarefa9.cpp.i

CMakeFiles/main.dir/tarefa9.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tarefa9.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/tarefa9.cpp -o CMakeFiles/main.dir/tarefa9.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/tarefa1.cpp.o" \
"CMakeFiles/main.dir/tarefa2.cpp.o" \
"CMakeFiles/main.dir/tarefa3.cpp.o" \
"CMakeFiles/main.dir/tarefa4.cpp.o" \
"CMakeFiles/main.dir/tarefa5.cpp.o" \
"CMakeFiles/main.dir/tarefa6.cpp.o" \
"CMakeFiles/main.dir/tarefa7.cpp.o" \
"CMakeFiles/main.dir/tarefa8.cpp.o" \
"CMakeFiles/main.dir/tarefa9.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/tarefa1.cpp.o
main: CMakeFiles/main.dir/tarefa2.cpp.o
main: CMakeFiles/main.dir/tarefa3.cpp.o
main: CMakeFiles/main.dir/tarefa4.cpp.o
main: CMakeFiles/main.dir/tarefa5.cpp.o
main: CMakeFiles/main.dir/tarefa6.cpp.o
main: CMakeFiles/main.dir/tarefa7.cpp.o
main: CMakeFiles/main.dir/tarefa8.cpp.o
main: CMakeFiles/main.dir/tarefa9.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1 /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1 /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build /home/gabrielfruet/dev/c++/estrutura-de-dados/lab1/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

