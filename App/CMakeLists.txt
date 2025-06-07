cmake_minimum_required(VERSION 3.26)
project(App)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
        Source/*.cpp
        Source/*.h
)

add_executable(App ${APP_SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "AMD64")
    set(ARCH_NAME "x64")
else()
    set(ARCH_NAME "${CMAKE_SYSTEM_PROCESSOR}")
endif()

set(BINARIES_DIR ${CMAKE_SOURCE_DIR}/Binaries/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${ARCH_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARIES_DIR})

target_link_libraries(App PUBLIC Core)
target_include_directories(Core PUBLIC ${CMAKE_SOURCE_DIR}/Core/Source)