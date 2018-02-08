CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(benchmarks)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${TARGET})

add_subdirectory(src)
add_subdirectory(3rdparty EXCLUDE_FROM_ALL)
