project(asymmetric_pwm)

add_executable(asymmetric_pwm)

target_sources(asymmetric_pwm PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_link_libraries(asymmetric_pwm PUBLIC bsp)
