workspace "proto-math"
    platforms { "x64" }
    configurations { "Release", "Debug" }


project "proto-math-library"
    kind "StaticLib"
    language "C"
    cdialect "C90"
    targetdir "lib/%{cfg.buildcfg}"
    
    files { "include/*.h", "src/*.c" }

    includedirs { "include" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "proto-math-tests"
    kind "ConsoleApp"
    language "C"
    cdialect "C90"
    targetdir "test-bin/%{cfg.buildcfg}"
    
    files { "tests/*.c" }

    includedirs { "include" }

    links { "proto-math-library" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
