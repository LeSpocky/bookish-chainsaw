cmake_minimum_required(VERSION 2.8.5)
project(bookish-chainsaw C)

add_executable(ipr
	"ipr.c"
)
install(TARGETS ipr DESTINATION "bin")

add_executable(vpr
	"vpr.c"
)
install(TARGETS vpr DESTINATION "bin")
