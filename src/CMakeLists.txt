file(GLOB ${PROJECT_NAME}-sources "*.cpp")

include_directories(
  ${PROJECT_SOURCE_DIR}/3rdparty/google-benchmark/src
  )

add_executable(${PROJECT_NAME}
  ${${PROJECT_NAME}-sources}
  )

target_link_libraries(${PROJECT_NAME}
  benchmark
  pthread
  )

add_dependencies(${PROJECT_NAME}
  benchmark
  )

add_custom_target(${PROJECT_NAME}-run
  COMMAND ./${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
  )
