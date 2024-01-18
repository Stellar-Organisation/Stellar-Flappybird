-- Add boost packages
add_requires("boost", "spdlog")

-- Create the Stellar-Engine project
target("flappybird")

    -- Set the project kind to static
    set_kind("binary")

    -- Set the C++ standard to C++20
    set_languages("cxx20")

    -- Add the source files
    add_files("src/**.cpp")

    -- Add lib include
    add_includedirs("/usr/local/include")

    -- Add lib dir
    add_linkdirs("/usr/local/lib")

    -- Add the library dependencies
    add_links("Stellar-Engine")

    -- Set the target directory to bin/tests
    set_targetdir("bin")

    -- Add the boost packages
    add_packages("boost", "spdlog")

    -- Add the system libraries
    add_syslinks("pthread")

    -- Set the warnings to all (-Wall)
    set_warnings("all", "pedantic", "extra")

    -- Set the build modes
    -- If the mode is debug, set the optimization to none and the symbols to debug
    if is_mode("debug") then
        set_optimize("none")
        set_symbols("debug")
    end

    -- If the mode is release, set the optimization to fastest and the symbols to hidden
    if is_mode("release") then
        set_optimize("fastest")
        set_symbols("hidden")
    end

    -- Define the _CRT_SECURE_NO_WARNINGS macro for the MSVC compiler (in case)
    add_defines("_CRT_SECURE_NO_WARNINGS")
