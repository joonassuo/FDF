cmake_minimum_required(VERSION 3.10)
project(fdf)
file(GLOB SOURCES "libft/*.c")
add_executable(fdf src/main.c src/bresenham.c src/create_mlx_struct.c src/make_grid.c src/rot_g_onkey.c src/rotate_grid.c src/rotate.c)
add_library(ft STATIC ${SOURCES})
include_directories(./includes)
target_link_libraries(fdf ft)
target_link_libraries(fdf /Users/jsuonper/fdf/miniLibX/libmlx.a)
target_link_libraries(fdf "-framework OpenGL")
target_link_libraries(fdf "-framework AppKit")