# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\johnk\CLionProjects\ProteusPokemon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\ProteusPokemon.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ProteusPokemon.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ProteusPokemon.dir\flags.make

CMakeFiles\ProteusPokemon.dir\main.cpp.obj: CMakeFiles\ProteusPokemon.dir\flags.make
CMakeFiles\ProteusPokemon.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProteusPokemon.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ProteusPokemon.dir\main.cpp.obj /FdCMakeFiles\ProteusPokemon.dir\ /FS -c C:\Users\johnk\CLionProjects\ProteusPokemon\main.cpp
<<

CMakeFiles\ProteusPokemon.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProteusPokemon.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe > CMakeFiles\ProteusPokemon.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\johnk\CLionProjects\ProteusPokemon\main.cpp
<<

CMakeFiles\ProteusPokemon.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProteusPokemon.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ProteusPokemon.dir\main.cpp.s /c C:\Users\johnk\CLionProjects\ProteusPokemon\main.cpp
<<

CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.obj: CMakeFiles\ProteusPokemon.dir\flags.make
CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.obj: ..\World\Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProteusPokemon.dir/World/Tile.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ProteusPokemon.dir\World\Tile.cpp.obj /FdCMakeFiles\ProteusPokemon.dir\ /FS -c C:\Users\johnk\CLionProjects\ProteusPokemon\World\Tile.cpp
<<

CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProteusPokemon.dir/World/Tile.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe > CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\johnk\CLionProjects\ProteusPokemon\World\Tile.cpp
<<

CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProteusPokemon.dir/World/Tile.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ProteusPokemon.dir\World\Tile.cpp.s /c C:\Users\johnk\CLionProjects\ProteusPokemon\World\Tile.cpp
<<

CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.obj: CMakeFiles\ProteusPokemon.dir\flags.make
CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.obj: ..\World\Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProteusPokemon.dir/World/Texture.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ProteusPokemon.dir\World\Texture.cpp.obj /FdCMakeFiles\ProteusPokemon.dir\ /FS -c C:\Users\johnk\CLionProjects\ProteusPokemon\World\Texture.cpp
<<

CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProteusPokemon.dir/World/Texture.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe > CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\johnk\CLionProjects\ProteusPokemon\World\Texture.cpp
<<

CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProteusPokemon.dir/World/Texture.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ProteusPokemon.dir\World\Texture.cpp.s /c C:\Users\johnk\CLionProjects\ProteusPokemon\World\Texture.cpp
<<

CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.obj: CMakeFiles\ProteusPokemon.dir\flags.make
CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.obj: ..\Player\Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProteusPokemon.dir/Player/Player.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ProteusPokemon.dir\Player\Player.cpp.obj /FdCMakeFiles\ProteusPokemon.dir\ /FS -c C:\Users\johnk\CLionProjects\ProteusPokemon\Player\Player.cpp
<<

CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProteusPokemon.dir/Player/Player.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe > CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\johnk\CLionProjects\ProteusPokemon\Player\Player.cpp
<<

CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProteusPokemon.dir/Player/Player.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ProteusPokemon.dir\Player\Player.cpp.s /c C:\Users\johnk\CLionProjects\ProteusPokemon\Player\Player.cpp
<<

CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.obj: CMakeFiles\ProteusPokemon.dir\flags.make
CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.obj: ..\Player\Item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProteusPokemon.dir/Player/Item.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ProteusPokemon.dir\Player\Item.cpp.obj /FdCMakeFiles\ProteusPokemon.dir\ /FS -c C:\Users\johnk\CLionProjects\ProteusPokemon\Player\Item.cpp
<<

CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProteusPokemon.dir/Player/Item.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe > CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\johnk\CLionProjects\ProteusPokemon\Player\Item.cpp
<<

CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProteusPokemon.dir/Player/Item.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ProteusPokemon.dir\Player\Item.cpp.s /c C:\Users\johnk\CLionProjects\ProteusPokemon\Player\Item.cpp
<<

# Object files for target ProteusPokemon
ProteusPokemon_OBJECTS = \
"CMakeFiles\ProteusPokemon.dir\main.cpp.obj" \
"CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.obj" \
"CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.obj" \
"CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.obj" \
"CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.obj"

# External object files for target ProteusPokemon
ProteusPokemon_EXTERNAL_OBJECTS =

ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\main.cpp.obj
ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\World\Tile.cpp.obj
ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\World\Texture.cpp.obj
ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\Player\Player.cpp.obj
ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\Player\Item.cpp.obj
ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\build.make
ProteusPokemon.exe: CMakeFiles\ProteusPokemon.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ProteusPokemon.exe"
	"C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ProteusPokemon.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1424~1.282\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ProteusPokemon.dir\objects1.rsp @<<
 /out:ProteusPokemon.exe /implib:ProteusPokemon.lib /pdb:C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\ProteusPokemon.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ProteusPokemon.dir\build: ProteusPokemon.exe

.PHONY : CMakeFiles\ProteusPokemon.dir\build

CMakeFiles\ProteusPokemon.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProteusPokemon.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ProteusPokemon.dir\clean

CMakeFiles\ProteusPokemon.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\johnk\CLionProjects\ProteusPokemon C:\Users\johnk\CLionProjects\ProteusPokemon C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug C:\Users\johnk\CLionProjects\ProteusPokemon\cmake-build-debug\CMakeFiles\ProteusPokemon.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ProteusPokemon.dir\depend

