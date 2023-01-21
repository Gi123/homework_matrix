cmake_minimum_required(VERSION 3.2)

if ($ENV{GITHUB_RUN_NUMBER})
    project (homework_matrix VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
else()
    project (homework_matrix VERSION 0.0.1)
endif()

configure_file(version.h.in version.h)

file(GLOB matrix_file_cpp
 "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(homework_matrix 
${matrix_file_cpp}
)

set_target_properties(homework_matrix PROPERTIES
    CMAKE_CXX_STANDARD 17
    CMAKE_CXX_STANDARD_REQUIRED ON
)

target_include_directories(homework_matrix
    PRIVATE 
    include
    "${CMAKE_BINARY_DIR}"
)

install(TARGETS homework_matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)