set(target UnitTests)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB sources
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(${target} ${sources})

set_target_properties(${target} PROPERTIES ${DEFAULT_PROJECT_OPTIONS})

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
		-Wno-unused-variable)
endif()

target_compile_options(${target}
	PRIVATE
	${DEFAULT_COMPILE_OPTIONS})

target_compile_definitions(${target}
	PRIVATE)

target_link_libraries(${target}
	PRIVATE
	${DEFAULT_LINKER_OPTIONS}
	cpp_practice
	doctest) 