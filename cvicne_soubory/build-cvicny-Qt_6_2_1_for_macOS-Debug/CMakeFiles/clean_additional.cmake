# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/cvicny_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cvicny_autogen.dir/ParseCache.txt"
  "cvicny_autogen"
  )
endif()
