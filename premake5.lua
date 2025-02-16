workspace "Umber"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
startproject "Sandbox"

project "Umber"
    location "Umber"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outdir .. "/%{prj.name}")
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"
        
        defines
        {
            "UM_PLATFORM_WINDOWS",
            "UM_BUILD_DLL"
        }        
        
        postbuildcommands 
        { 
            "{MKDIR} ../bin/" .. outdir .. "/Sandbox", 
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outdir .. "/Sandbox" 
        }

    filter "configurations:Debug"
        defines { "UM_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "UM_RELEASE" }        
        optimize "On"

    filter "configurations:Dist"
        defines { "UM_DIST" }
        optimize "On"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outdir .. "/%{prj.name}")
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Umber/vendor/spdlog/include",
        "Umber/src"
    }
    
    links
    {
        "Umber"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        defines
        {
            "UM_PLATFORM_WINDOWS"
        }        

    filter "configurations:Debug"
        defines { "UM_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "UM_RELEASE" }        
        optimize "On"

    filter "configurations:Dist"
        defines { "UM_DIST" }
        optimize "On"