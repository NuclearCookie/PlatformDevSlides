solution "genie_gp1"
    configurations {
        "Debug",
        "Release"
    }

    platforms {
        "x32",
        "x64",
        "Native" -- for targets where bitness is not specified
    }

    language "C++"

    location "../"

PROJECT_DIR = "../"

project "GP1Framework_genie"
    kind "WindowedApp"

    configuration "Debug"
        targetdir "bin/debug"
        objdir "obj/debug"
        defines { "_DEBUG" }
        flags { "Symbols" }
    configuration "Release"
        targetdir "bin/release"
        objdir "obj/debug"

    configuration "vs*"
        flags { "Unicode", "Winmain"}
        defines { "WIN32" }

    configuration {}

    defines { "_CONSOLE" }

    files {
        path.join(PROJECT_DIR, "*.cpp"),
        path.join(PROJECT_DIR, "*.h")
    }

    excludes {
        path.join(PROJECT_DIR, "PhysxErrorCallback.h"),
        path.join(PROJECT_DIR, "PhysxErrorCallback.cpp"),
        path.join(PROJECT_DIR, "GP2_RenderingPipeline.h"),
        path.join(PROJECT_DIR, "GP2_RenderingPipeline.cpp")
    }

    -- optional. This is purely cosmetically.
    vpaths {
        [ "Game Files/Main"] = { 
            path.join(PROJECT_DIR, "main.cpp"),
            path.join(PROJECT_DIR, "MainGame.*")
        },
        [ "Game Files/Prefabs"] = {
            path.join(PROJECT_DIR, "*PosColorNorm.*"),
            path.join(PROJECT_DIR, "GimbalRig.*")
        },
        [ "Game Files/Scenes"] = {
            path.join(PROJECT_DIR, "*Scene.*"),
        },
        [ "Framework Files/Camera"] = {
            path.join(PROJECT_DIR, "*Camera.*")
        },
        [ "Framework Files/Content"] = {
            path.join(PROJECT_DIR, "*Loader.*")
        },
        [ "Framework Files/Helpers"] = {
            path.join(PROJECT_DIR, "stdafx.*"),
            path.join(PROJECT_DIR, "DdsTextureResource.*"),
            path.join(PROJECT_DIR, "Debug.*"),
            path.join(PROJECT_DIR, "GameContext.*"),
            path.join(PROJECT_DIR, "GameTimer.*"),
            path.join(PROJECT_DIR, "Singleton.h"),
            path.join(PROJECT_DIR, "VertexStructs.h"),
        },
        [ "Framework Files/Managers"] = {
            path.join(PROJECT_DIR, "*Manager.*"),
        },
        [ "Framework Files/SceneGraph"] = {
            path.join(PROJECT_DIR, "GameObject.*"),
            path.join(PROJECT_DIR, "GameScene.*"),
        }
        
    }