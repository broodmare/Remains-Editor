# CMakeList.txt : CMake project for CanterCore, include source and define
# project specific logic here.
#

find_package(SDL2 REQUIRED)


# Add source to this project's executable.
add_executable (CanterCore "CanterCore.cpp" "CanterCore.h" "lib/glad/glad.c" "TileViewer.cpp" "TileViewer.h" "CanterFunctions.cpp" "CanterFunctions.h" "Components/Tile.h" "Components/Level.cpp" "Components/Level.h")

target_link_libraries(CanterCore SDL2::SDL2 SDL2::SDL2main)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CanterCore PROPERTY CXX_STANDARD 20)
endif()

