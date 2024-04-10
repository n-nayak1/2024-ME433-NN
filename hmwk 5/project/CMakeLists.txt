add_executable(project
  main.c
  )

# pull in common dependencies
target_link_libraries(project pico_stdlib hardware_i2c)



# create map/bin/hex file etc.
pico_add_extra_outputs(project)

