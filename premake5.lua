workspace "OwlEngine"

	configurations
	{
		"Debug32",
		"Releas32",
		"Dist32",
		"Debug64",
		"Releas64",
		"Dist64"
	}

	filter "configurations:*32"
		architecture "x86"

	filter "configurations:*64"
		architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "OwlEngine"
	location "OwlEngine"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OE_PLATFORM_WINDOWS",
			"OE_BUILD_DLL"
		}

		postbuildcommands
		{
			("copy ..\\bin\\Debug32-windows-x86\\OwlEngine\\OwlEngine.dll ..\\bin\\Debug32-windows-x86\\Sandbox")
		}
		
	filter "configurations:Debug*"
		defines "OE_DEBUG"
		symbols "On"

	filter "configurations:Release*"
		defines "OE_RELEASE"
		optimize "On"

	filter "configurations:Dist*"
		defines "OE_DIST"
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
		"OwlEngine/vendor/spdlog/include",
		"OwlEngine/src"
	}

	links
	{
		"OWLEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OE_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug*"
		defines "OE_DEBUG"
		symbols "On"

	filter "configurations:Release*"
		defines "OE_RELEASE"
		optimize "On"

	filter "configurations:Dist*"
		defines "OE_DIST"
		optimize "On"