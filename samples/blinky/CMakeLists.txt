project(led)

add_executable(led)

target_sources(led PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_link_libraries(led PUBLIC bsp)
