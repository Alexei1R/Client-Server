workspace "Trace"
	architecture "x64"
	language "C++"
	cppdialect "C++17"

	startproject "Server"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


	--outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	outputdir = "-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir[""] = ""

	include ""


	---------------------------
	--StaticLib Engine Server--
	---------------------------
	project "Server"
		location "Server"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


		--------pch-------
		pchheader "pch.h"
		pchsource "%{prj.name}/pch.cpp"
		------------------

		------files------
		files{
			"%{prj.name}/pch.h",
			"%{prj.name}/pch.cpp",
		
			"%{prj.name}/Trace/src/**.h",
			"%{prj.name}/Trace/src/**.cpp",

			
		}

		------defines------
		defines{
			""
		}

		------includedirs------
		includedirs{
			"%{prj.name}/Trace/src/",
			"%{prj.name}/",
			"%{prj.name}/Trace/vendor/spdlog/include",
		}


		links 
		{ 
		}

		------filter------
		filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
			defines "_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "_DIST"
			runtime "Release"
			optimize "on"







	--------------------------------
	--Client -----------------------
	--------------------------------
	project "Client"
		location "Client"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


		--------pch-------
		pchheader "pch.h"
		pchsource "%{prj.name}/pch.cpp"
		------------------

		------files------
		files{
			"%{prj.name}/pch.h",
			"%{prj.name}/pch.cpp",
		
			"%{prj.name}/Trace/src/**.h",
			"%{prj.name}/Trace/src/**.cpp",

			
		}

		------defines------
		defines{
			""
		}

		------includedirs------
		includedirs{
			"%{prj.name}/Trace/src/",
			"%{prj.name}/",
			"%{prj.name}/Trace/vendor/spdlog/include",
		}



		------links------
		links{
		}



		------filter------
		filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
			defines "_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "_DIST"
			runtime "Release"
			optimize "on"