cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(P1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})

find_package(ROOT REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include ${Geant4_INCLUDE_DIR} ${ROOT_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(P1 P1Main.cc ${sources} ${headers})
target_link_libraries(P1 ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

set(P1_SCRIPTS P1execute.mac)

foreach(_script ${P1_SCRIPTS})
		configure_file(
			${PROJECT_SOURCE_DIR}/${_script}
			${PROJECT_BINARY_DIR}/${_script}
			COPYONLY
			)
endforeach()

install(TARGETS P1 DESTINATION bin)
