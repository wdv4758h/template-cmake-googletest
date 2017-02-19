set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin_tests/)
set(REPORT_DIRECTORY ${CMAKE_BINARY_DIR}/report/)

include_directories(${CMAKE_SOURCE_DIR}/googletest/include ${CMAKE_SOURCE_DIR}/src)

add_executable(_sampleTests
    main.cpp
    sampleTests.cpp
)

target_link_libraries(_sampleTests
    gtest
    gmock
    sample
)

macro (create_test target)
    add_test (NAME ${target}
              COMMAND $<TARGET_FILE:${target}> "--gtest_output=xml:${REPORT_DIRECTORY}/${target}.xml")
endmacro (create_test)

create_test(_sampleTests)
