add_rules("mode.debug", "mode.release")

set_languages("c++20")
set_policy("build.sanitizer.address", true)
set_policy("build.sanitizer.undefined", true)
add_rules("plugin.compile_commands.autoupdate")
add_cxxflags("-Wall -Wextra -Wpedantic -Wshadow -g")
add_requires("dbg-macro")

for _, file in ipairs(os.files("src/*.cpp")) do
	local name = path.basename(file)

	target(name)
		set_kind("binary")
		add_files(file)
    add_packages("dbg-macro")
end
