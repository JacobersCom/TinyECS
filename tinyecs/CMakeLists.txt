#enitiy list
add_library(tinyecs

	include/tinyecs/entity.hpp
	src/tinyecs/entity.cpp
)

target_include_directories(tinyecs
	PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)