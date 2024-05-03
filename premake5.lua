workspace "proto-math"
    platforms { "x64", "x86" }
    configurations { "Release", "Debug" }



project "proto-math-static"
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
    filter "system:windows"
        defines { "WIN32" }
    filter "system:linux"
        defines { "LINUX" }



project "proto-math-dynamic"
    kind "SharedLib"
    language "C"
    cdialect "C90"
    targetdir "lib/%{cfg.buildcfg}"
    
    files { "include/*.h", "src/*.c" }

    includedirs { "include" }

    defines { "SHARED_LIB" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
    filter "system:windows"
        defines { "WIN32" }
    filter "system:linux"
        defines { "LINUX" }



        
project "proto-math-tests"
    kind "ConsoleApp"
    language "C"
    cdialect "C90"
    targetdir "test-bin/%{cfg.buildcfg}"
    
    files { "tests/*.c" }

    includedirs { "include" }

    links { "proto-math-static" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
    filter "system:windows"
        defines { "WIN32" }
    filter "system:linux"
        defines { "LINUX" }
