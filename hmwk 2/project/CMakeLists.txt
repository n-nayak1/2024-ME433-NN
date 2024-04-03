add_executable(project
  blink.c
  )

# pull in common dependencies
target_link_libraries(project pico_stdlib)



# create map/bin/hex file etc.
pico_add_extra_outputs(project)

