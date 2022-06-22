add_executable(gslice gslice_main.cpp)
target_link_libraries(gslice PUBLIC
)
set_target_properties(gslice PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<0:>)
