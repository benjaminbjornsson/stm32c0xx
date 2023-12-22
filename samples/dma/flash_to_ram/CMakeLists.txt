project(dma_flash_to_ram)

add_executable(dma_flash_to_ram)

target_sources(dma_flash_to_ram PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_link_libraries(dma_flash_to_ram PUBLIC bsp)
