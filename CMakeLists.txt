# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 11:04:56 by aminadzh          #+#    #+#              #
#    Updated: 2019/08/17 11:04:57 by aminadzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.14)

project(libft C)

set(CMAKE_C_STANDARD 99)

file(GLOB LIBFT_SRC "src/*.c")
add_library(libft STATIC ${LIBFT_SRC})

target_include_directories(libft PUBLIC ${PROJECT_SOURCE_DIR}/includes)

add_executable(libft_test
	test/main.c
	test/test_string.c)
target_link_libraries(libft_test PRIVATE libft)