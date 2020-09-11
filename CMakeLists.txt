cmake_minimum_required(VERSION 3.17)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes)

add_executable(lem_in
        includes/lemin.h
        srcs/check_links.c
        srcs/check_max.c
        srcs/check_rooms.c
        srcs/create_end.c
        srcs/create_start.c
        srcs/dlc.c
        srcs/ft_lemin.c
        srcs/move_ants.c
        srcs/pars_map.c
        srcs/put_ants.c
        srcs/read_map.c
        srcs/search_path.c)

find_library(FT ft libft)
target_link_libraries(lem_in LINK_PUBLIC ${FT})