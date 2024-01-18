project(pwm)

add_executable(pwm)

target_sources(pwm PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_link_libraries(pwm PUBLIC bsp)
