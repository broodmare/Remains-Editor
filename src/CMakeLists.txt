# CMakeList.txt : CMake project for CanterCore, include source and define
# project specific logic here.
#

find_package(SDL2 REQUIRED)


# Add source to this project's executable.
add_executable(
    CanterCore 
    CanterCore.cpp
    CanterCore.h
    "${PROJECT_SOURCE_DIR}/lib/glad/glad.c"
    TileViewer.cpp
    TileViewer.h
    CanterFunctions.cpp
    CanterFunctions.h
)

target_include_directories(CanterCore PRIVATE 
    ${PROJECT_SOURCE_DIR}/lib/imgui
    ${PROJECT_SOURCE_DIR}/lib/imgui
    ${PROJECT_SOURCE_DIR}/lib/glad
    )
target_link_libraries(CanterCore SDL2::SDL2 SDL2::SDL2main)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CanterCore PROPERTY CXX_STANDARD 20)
endif()


#Where the SDL2.dll file is located.
set(SDL2_DLL_PATH "${PROJECT_SOURCE_DIR}/lib/SDL2.dll")
#Where to copy it to. (Same directory as output exe.)
set(SDL2_DLL_DEST "${CMAKE_CURRENT_BINARY_DIR}")
#Run command when building to copy SDL2.dll to the output directory if it's different than what's already there.
add_custom_command(TARGET CanterCore POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SDL2_DLL_PATH}
    ${SDL2_DLL_DEST}
)