cmake_minimum_required(VERSION 3.26)
project(Framy)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE FRAMY_SOURCES CONFIGURE_DEPENDS
        Source/*.cpp
        Include/*.h
)

add_library(Framy STATIC ${FRAMY_SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "AMD64")
    set(ARCH_NAME "x64")
else()
    set(ARCH_NAME "${CMAKE_SYSTEM_PROCESSOR}")
endif()

set(BINARIES_DIR ${CMAKE_SOURCE_DIR}/Binaries/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${ARCH_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BINARIES_DIR})
target_include_directories(Framy PUBLIC ${CMAKE_SOURCE_DIR}/Include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Framy PUBLIC BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(Framy PUBLIC BUILD_RELEASE)
endif()

# spdlog
add_subdirectory(ThirdParty/spdlog)
target_link_libraries(Framy PUBLIC spdlog::spdlog)