find_package(mdspan CONFIG REQUIRED)

add_executable(mdim_span mdspan_main.cpp)
target_link_libraries(mdim_span PRIVATE
	std::mdspan
)
set_target_properties(mdim_span PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<0:>)
