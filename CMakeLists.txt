cmake_minimum_required( VERSION 3.1 )

project( cxxstreams )

find_package( Boost REQUIRED system filesystem )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
)

set( ${PROJECT_NAME}_HEADERS
  DataSink.h
  DataSource.h
  PrintSink.h
  TextFileSource.h
)
set( ${PROJECT_NAME}_SOURCES
  DataSink.cpp
  DataSource.cpp
  PrintSink.cpp
  TextFileSource.cpp
)

add_library( ${PROJECT_NAME}
  ${${PROJECT_NAME}_SOURCES}
  ${${PROJECT_NAME}_HEADERS}
)

target_link_libraries( ${PROJECT_NAME}
  ${Boost_LIBRARIES}
)

add_executable( serialExecution main.cpp )
target_link_libraries( serialExecution ${PROJECT_NAME} )
