cmake_minimum_required(VERSION 3.14)

project(Bomberman)

set(NAME_LIB "libPuff")
set(NAME_CLIENT "bomberman")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(INCLUDE_DIRECTORY "${PROJECT_SOURCE_DIR}/${NAME_LIB}/inc/"
					  "${PROJECT_SOURCE_DIR}/${NAME_CLIENT}/inc/")
set(SRC_DIRECTORY "${PROJECT_SOURCE_DIR}/${NAME_LIB}/src/"
				  "${PROJECT_SOURCE_DIR}/${NAME_CLIENT}/src/")

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}")

# cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(FBXSDK_VERSION "2019.2")
find_package(FBX)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Lua REQUIRED)
find_package(FFmpeg REQUIRED)

INCLUDE(CheckApplyCompilerFlags)

# --- global compiler flags ---
if (UNIX)
  COMPILER_FLAGS(FLAGS "-pipe" "-Wall" "-Wextra" "--std=c++11")
elseif (MSVC)
  COMPILER_FLAGS(FLAGS "/EHsc")
endif()

include_directories("${CMAKE_CURRENT_BINARY_DIR}/common/inc")

# All source files using globs
file(
  GLOB
  lib_source_files
  ${NAME_LIB}/src/*
)

file(
  GLOB_RECURSE
  lib_include_files
  ${NAME_LIB}/inc/*
)

file(
  GLOB_RECURSE
  client_source_files
  ${NAME_CLIENT}/src/*
  ${NAME_CLIENT}/src/Widgets/*.cpp
)

file(
  GLOB_RECURSE
  client_include_files
  ${NAME_CLIENT}/inc/*
  ${NAME_CLIENT}/src/Widgets/*.hpp
)

add_library(
# executable name
  ${NAME_LIB} STATIC
# source files
  ${lib_source_files}
  ${lib_include_files}
)

set_property(TARGET ${NAME_LIB} APPEND PROPERTY INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/${NAME_LIB}/inc")
set_property(TARGET ${NAME_LIB} APPEND PROPERTY INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/${NAME_LIB}")

add_executable(
  # executable name
    ${NAME_CLIENT}
 # source files
    ${client_source_files}
    ${client_include_files}
)

set_property(TARGET ${NAME_CLIENT} APPEND PROPERTY INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/${NAME_CLIENT}/inc")
set_property(TARGET ${NAME_CLIENT} APPEND PROPERTY INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/${NAME_CLIENT}/src/Widgets")
set_property(TARGET ${NAME_CLIENT} APPEND PROPERTY INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/${NAME_LIB}/inc")
set_property(TARGET ${NAME_CLIENT} APPEND PROPERTY INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/${NAME_LIB}")
target_link_libraries(${NAME_CLIENT} ${NAME_LIB})


## Librairy Dependencies
if (FBXSDK_FOUND)
    target_include_directories(${NAME_LIB} PUBLIC ${FBXSDK_INCLUDE_DIR})
    target_link_libraries (${NAME_LIB} ${FBXSDK_LIBRARY})
endif()

if (SDL2IMAGE_FOUND)
    target_include_directories(${NAME_LIB} PUBLIC ${SDL2IMAGE_INCLUDE_DIR})
    target_link_libraries(${NAME_LIB} ${SDL2IMAGE_LIBRARY})
endif()

if (SDL2_FOUND)
    target_include_directories(${NAME_LIB} PUBLIC ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${NAME_LIB} ${SDL2_LIBRARIES})
endif()

if (GLEW_FOUND)
    target_include_directories(${NAME_LIB} PUBLIC ${GLEW_INCLUDE_DIRS})
    target_link_libraries(${NAME_LIB} ${GLEW_LIBRARIES})
endif()

if (OPENGL_FOUND)
    target_include_directories(${NAME_LIB} PUBLIC ${OPENGL_INCLUDE_DIR})
    target_link_libraries(${NAME_LIB} ${OPENGL_LIBRARIES})
endif()

## Client Dependencies

if (LUA_FOUND)
    target_include_directories(${NAME_CLIENT} PUBLIC ${LUA_INCLUDE_DIR})
    target_link_libraries(${NAME_CLIENT} ${LUA_LIBRARIES})
endif()

if (SDL2_MIXER_FOUND)
    target_include_directories(${NAME_CLIENT} PUBLIC ${SDL2_MIXER_INCLUDE_DIRS})
    target_link_libraries(${NAME_CLIENT} ${SDL2_MIXER_LIBRARIES})
endif()

if (AVCODEC_FOUND)
    target_include_directories(${NAME_CLIENT} PUBLIC ${AVCODEC_INCLUDE_DIRS})
    target_link_libraries(${NAME_CLIENT} ${AVCODEC_LIBRARIES})
endif()

# if (THREADS_FOUND)
#   target_link_libraries (${NAME_LIB} ${CMAKE_THREAD_LIBS_INIT})
# endif()

