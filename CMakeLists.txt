cmake_minimum_required(VERSION 3.10)
project(proto-math)

# Set the configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Static Library: proto-math-static
add_library(proto-math-static STATIC
    src/pmGeneral.c
    src/pmMat3.c
    src/pmTrigonometry.c
    src/pmVec3.c
    src/pmVec4.c
)

set_target_properties(proto-math-static PROPERTIES
    C_STANDARD 90
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>"
    OBJECT_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/obj/staticlib/$<CONFIG>"
)

target_include_directories(proto-math-static PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Shared Library: proto-math-dynamic
add_library(proto-math-dynamic SHARED
    src/pmGeneral.c
    src/pmMat3.c
    src/pmTrigonometry.c
    src/pmVec3.c
    src/pmVec4.c
)

set_target_properties(proto-math-dynamic PROPERTIES
    C_STANDARD 90
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>"
    OBJECT_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/obj/sharedlib/$<CONFIG>"
)

target_include_directories(proto-math-dynamic PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(proto-math-dynamic PRIVATE SHARED_LIB)

# Console Application: proto-math-tests
add_executable(proto-math-tests
    tests/Main.c
)

set_target_properties(proto-math-tests PROPERTIES
    C_STANDARD 90
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test-bin/$<CONFIG>"
    OBJECT_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/obj/tests/$<CONFIG>"
)

target_include_directories(proto-math-tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(proto-math-tests PRIVATE proto-math-static)

# Configuration specific settings
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)

    set_target_properties(proto-math-static PROPERTIES 
        ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib/${OUTPUTCONFIG}
        OBJECT_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib/obj/staticlib/${OUTPUTCONFIG}
    )

    set_target_properties(proto-math-dynamic PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib/${OUTPUTCONFIG}
        OBJECT_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib/obj/sharedlib/${OUTPUTCONFIG}
    )

    set_target_properties(proto-math-tests PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/test-bin/${OUTPUTCONFIG}
        OBJECT_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib/obj/tests/${OUTPUTCONFIG}
    )
endforeach()

# Platform specific settings
if(WIN32)
    target_compile_definitions(proto-math-static PRIVATE WIN32)
    target_compile_definitions(proto-math-dynamic PRIVATE WIN32)
    target_compile_definitions(proto-math-tests PRIVATE WIN32)
elseif(UNIX)
    target_compile_definitions(proto-math-static PRIVATE LINUX)
    target_compile_definitions(proto-math-dynamic PRIVATE LINUX)
    target_compile_definitions(proto-math-tests PRIVATE LINUX)
    target_link_libraries(proto-math-static PRIVATE m)
    target_link_libraries(proto-math-dynamic PRIVATE m)
    target_link_libraries(proto-math-tests PRIVATE m)
endif()

# Configuration specific definitions and settings
foreach(CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${CONFIG} CONFIG_UPPER)

    if(CONFIG_UPPER STREQUAL "DEBUG")
        target_compile_definitions(proto-math-static PRIVATE DEBUG)
        target_compile_definitions(proto-math-dynamic PRIVATE DEBUG)
        target_compile_definitions(proto-math-tests PRIVATE DEBUG)
        target_compile_options(proto-math-static PRIVATE $<$<CONFIG:DEBUG>:-g>)
        target_compile_options(proto-math-dynamic PRIVATE $<$<CONFIG:DEBUG>:-g>)
        target_compile_options(proto-math-tests PRIVATE $<$<CONFIG:DEBUG>:-g>)
    elseif(CONFIG_UPPER STREQUAL "RELEASE")
        target_compile_definitions(proto-math-static PRIVATE NDEBUG)
        target_compile_definitions(proto-math-dynamic PRIVATE NDEBUG)
        target_compile_definitions(proto-math-tests PRIVATE NDEBUG)
        target_compile_options(proto-math-static PRIVATE $<$<CONFIG:RELEASE>:-O3>)
        target_compile_options(proto-math-dynamic PRIVATE $<$<CONFIG:RELEASE>:-O3>)
        target_compile_options(proto-math-tests PRIVATE $<$<CONFIG:RELEASE>:-O3>)
    endif()
endforeach()

