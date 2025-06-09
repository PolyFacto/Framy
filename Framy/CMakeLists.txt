cmake_minimum_required(VERSION 3.26)
project(Framy)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE FRAMY_SOURCES CONFIGURE_DEPENDS
        Framy.h
        Include/*.h
        Source/*.cpp
)

add_library(Framy STATIC ${FRAMY_SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "AMD64")
    set(ARCH_NAME "x64")
else()
    set(ARCH_NAME "${CMAKE_SYSTEM_PROCESSOR}")
endif()

set(BINARIES_DIR ${CMAKE_SOURCE_DIR}/Binaries/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${ARCH_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BINARIES_DIR})
target_include_directories(Framy
        PUBLIC ${CMAKE_SOURCE_DIR}/Framy
        PUBLIC ${CMAKE_SOURCE_DIR}/Framy/Include
        PUBLIC ${CMAKE_SOURCE_DIR}/Framy/Include/Platform/Windows
        PUBLIC ${CMAKE_SOURCE_DIR}/Framy/ThirdParty/GLFW/include
        PUBLIC ${CMAKE_SOURCE_DIR}/Framy/ThirdParty/GLAD/include
)
target_precompile_headers(Framy PUBLIC framy_pch.h)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Framy PUBLIC BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(Framy PUBLIC BUILD_RELEASE)
endif()

# spdlog
add_subdirectory(ThirdParty/spdlog)
target_link_libraries(Framy PUBLIC spdlog::spdlog)

# GLFW
add_subdirectory(ThirdParty/GLFW)
target_link_libraries(Framy PUBLIC glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(Framy PUBLIC OpenGL::GL)

# GLAD
target_compile_definitions(Framy PUBLIC GLFW_INCLUDE_NONE)
add_subdirectory(ThirdParty/GLAD)
target_link_libraries(Framy PRIVATE glad)