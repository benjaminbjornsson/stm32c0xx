project(button)

add_executable(button)

target_sources(button PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_link_libraries(button PUBLIC bsp)
