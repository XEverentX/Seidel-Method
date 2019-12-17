message(STATUS "algo")

file(GLOB_RECURSE header_files "*.hpp")
file(GLOB_RECURSE source_files "*.cpp")

add_library(algo ${header_files} ${source_files})
