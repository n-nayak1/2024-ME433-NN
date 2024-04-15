add_executable(project
  main.c
  ssd1306.c
  )

# pull in common dependencies
target_link_libraries(project pico_stdlib hardware_i2c hardware_adc)

pico_enable_stdio_usb(project 1) 
pico_enable_stdio_uart(project 0)


# create map/bin/hex file etc.
pico_add_extra_outputs(project)

