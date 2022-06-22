add_executable(span span_main.cpp)
target_link_libraries(span PUBLIC
)
set_target_properties(span PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<0:>)
