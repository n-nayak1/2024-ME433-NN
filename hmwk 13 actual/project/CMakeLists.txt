set(FAMILY rp2040)
set(BOARD pico_sdk)
set(TINYUSB_FAMILY_PROJECT_NAME_PREFIX "tinyusb_dev_")

add_executable(project
        main.c
        usb_descriptors.c
        )

target_sources(project PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.c
        )

target_include_directories(project PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

# pull in common dependencies
target_link_libraries(project PUBLIC hardware_i2c PUBLIC pico_stdlib pico_unique_id tinyusb_device tinyusb_board)

# create map/bin/hex file etc.
pico_add_extra_outputs(project)