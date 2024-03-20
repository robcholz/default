set_project("libdefault")
add_rules("mode.debug", "mode.release")
set_languages("cxx23")
set_targetdir("bin")

-- treat all warnings as errors
set_warnings("all")
set_warnings("error")

target("test")
set_kind("binary")
add_files("test.cpp")
add_includedirs("include")
target_end()

