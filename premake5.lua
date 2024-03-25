workspace "proto-math"
    platforms { "x64" }
    configurations { "Release", "Debug" }


project "proto-math-library"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "lib/%{cfg.buildcfg}"
    
    files { "include/*.hpp", "src/*.cpp" }

    includedirs { "include" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "proto-math-tests"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetdir "test-bin/%{cfg.buildcfg}"
    
    files { "tests/*.cpp" }

    includedirs { "include" }

    links { "proto-math-library" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
