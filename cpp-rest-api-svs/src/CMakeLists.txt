file(GLOB_RECURSE SRC
    "main.h"
    "main.cpp"
)
source_group("Main" FILES ${SRC})

file(GLOB_RECURSE SRC_LIBS
)
source_group("Libs" FILES ${SRC_LIBS})

add_executable(cpp-rest-api-svs ${SRC} ${SRC_LIBS})
target_include_directories(cpp-rest-api-svs PRIVATE ${CONAN_INCLUDE_DIRS_SPDLOG})
target_link_libraries(cpp-rest-api-svs ${CONAN_LIBS})



# if(NOT TARGET oas-tools)
#     add_custom_target(oas-tools)
#     add_dependencies(oas-tools oas-tools)
# endif()
