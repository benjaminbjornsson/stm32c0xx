project(single_conversion_sw_trig)

add_executable(single_conversion_sw_trig)

target_sources(single_conversion_sw_trig PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_link_libraries(single_conversion_sw_trig PUBLIC bsp)
