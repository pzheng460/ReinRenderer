cmake_minimum_required (VERSION 3.1)
project(SoftwareRenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENMP_LIBRARIES "/opt/homebrew/Cellar/libomp/18.1.6/lib") #这里写你的libomp路径, 通过brew安装的默认地址
set(OPENMP_INCLUDES "/opt/homebrew/Cellar/libomp/18.1.6/include")#这里写你的libomp路径

# Find OpenMP
if(APPLE)
  if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(OpenMP_C "${CMAKE_C_COMPILER}")
    set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -lomp -Wno-unused-command-line-argument")
    set(OpenMP_C_LIB_NAMES "libomp" "libgomp" "libiomp5")
    set(OpenMP_libomp_LIBRARY ${OpenMP_C_LIB_NAMES})
    set(OpenMP_libgomp_LIBRARY ${OpenMP_C_LIB_NAMES})
    set(OpenMP_libiomp5_LIBRARY ${OpenMP_C_LIB_NAMES})
  endif()
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(OpenMP_CXX "${CMAKE_CXX_COMPILER}")
    set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -lomp -Wno-unused-command-line-argument")
    set(OpenMP_CXX_LIB_NAMES "libomp" "libgomp" "libiomp5")
    set(OpenMP_libomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
    set(OpenMP_libgomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
    set(OpenMP_libiomp5_LIBRARY ${OpenMP_CXX_LIB_NAMES})
  endif()
endif()


find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)
  include_directories("${OPENMP_INCLUDES}")
  link_directories("${OPENMP_LIBRARIES}")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

#find_package(assimp REQUIRED)
#include_directories(${ASSIMP_INCLUDE_DIRS})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB_RECURSE SOURCES "src/*.h" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

