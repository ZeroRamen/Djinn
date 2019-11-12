workspace "Djinn"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Djinn/vendor/GLFW/include"

include "Djinn/vendor/GLFW"

project "Djinn"
	location "Djinn"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dngpch.h"
	pchsource "Djinn/src/dngpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DJINN_PLATFORM_WINDOWS",
			"DJINN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "Djinn_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "Djinn_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "Djinn_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Djinn/vendor/spdlog/include",
		"Djinn/src"
	}

	links
	{
		"Djinn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DJINN_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Debug"
		defines "Djinn_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "Djinn_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "Djinn_DIST"
		optimize "On"