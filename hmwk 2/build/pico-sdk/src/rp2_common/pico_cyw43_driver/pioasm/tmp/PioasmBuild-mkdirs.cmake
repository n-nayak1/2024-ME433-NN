# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/nikhilnayak/Downloads/pico/pico-sdk/tools/pioasm"
  "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pioasm"
  "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/nikhilnayak/Downloads/Github/2024-ME433-NN/hmwk 2/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
