include_directories(${CMAKE_SOURCE_DIR}/googletest/include ${CMAKE_SOURCE_DIR}/src)

add_executable(_sampleTests
	main.cpp
	sampleTests.cpp
)

target_link_libraries(_sampleTests
	gtest
	sample
)

add_custom_command(
	TARGET _sampleTests
    POST_BUILD
    COMMAND _sampleTests
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
