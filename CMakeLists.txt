cmake_minimum_required(VERSION 2.8.5)
project(vpr)
add_executable(${PROJECT_NAME}
	"vpr.c"
)
install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
