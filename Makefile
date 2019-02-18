
## Name of Project

NAME = rt

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs
LIB_DIR = libft
FRMWK_DIR = frameworks

COLLIDER_DIR = collider
DEBUG_DIR = debug
DIGEST_DIR = digest
FILTER_DIR = filter
INITIALIZE_DIR = initialize
LIGHT_DIR = light
PARSER_DIR = parser
PICTURE_DIR = picture
RECURSIVE_DIR = recursive
ROTATE_DIR = rotate
SCENE_DIR = scene
UTILS_DIR = utils
VECTOR_DIR = vector
VISIBLE_DIR = visible
SDL_PART_DIR = sdl_part
OPTIONS_DIR = options

## Compilating Utilities

FAST = -Ofast
# DEBUG = -g3 -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT

# INC = $(INC_DIR:%=-I./$(LIB_DIR)/%) $(INC_DIR:%=-I./%)
INC = $(INC_DIR:%=-I./$(LIB_DIR)/%) $(INC_DIR:%=-I./%) -I./libpng/include -I ./libxml2/include/libxml2
# LIB = -L$(LIB_DIR) -lft
LIB = -L$(LIB_DIR) -lft -Llibxml2/lib -lxml2 -Llibpng/lib -lpng
INC_FRMWK = -D_THREAD_SAFE -F ./$(FRMWK_DIR)

HOME =  $(shell pwd)/Frameworks
FRMWK = -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./$(FRMWK_DIR) -rpath $(HOME)

CC = clang $(FLAGS) $(INC)

## List of Functions

INCLUDE_H = rtv1 \
			define \
			struct \
			filter \
			parsing \
			events \
			interface

COLLIDER_FT =	rt_collider_delta \
				rt_collider_normal \
				rt_collider_sphere \
				rt_collider_cylinder \
				rt_collider_cone \
				rt_collider_plane \
				rt_collider_disk


DIGEST_FT = 	rt_add_pool \
				rt_add_queue \
				rt_get_pool \
				rt_get_queue \
				rt_list_pool \
				rt_list_queue

FILTER_FT =		rt_basic_filters \
				rt_kernel_convolution \
				rt_cartoon \
				rt_calc_line \
				rt_calc_pallet

INITIALIZE_FT =	rt_init_origin \
				rt_init_projection \
				rt_update_buffer \
				rt_origin_object \
				rt_translate_screen \
				rt_rotate_screen \

LIGHT_FT =	rt_light_diffuse \
			rt_impact_to_light \
			rt_light \
			rt_look_lights

PARSER_FT = call_parser \
			rt_check_scene \
			rt_default_camera \
			rt_default_light \
			rt_default_object \
			rt_default_scene \
			rt_fill_ambient \
			rt_fill_camera \
			rt_fill_cone \
			rt_fill_cylinder \
			rt_fill_directional \
			rt_fill_disk \
			rt_fill_light \
			rt_fill_object \
			rt_fill \
			rt_fill_plane \
			rt_fill_scene \
			rt_fill_sphere \
			rt_fill_spot \
			rt_get_float \
			rt_get_float3 \
			rt_get_float4 \
			rt_get_int \
			rt_get_path \
			rt_get_string \
			rt_malloc \
			rt_open_xml \
			rt_parser \
			rt_post_computing \
			rt_put_end_tag \
			rt_put_path_fd \
			rt_put_start_tag_name \
			rt_put_string_fd \
			rt_put_t_float_fd \
			rt_put_t_float3_fd \
			rt_put_t_float4_fd \
			rt_save_xml

PICTURE_FT = rt_picture_save_stable



RECURSIVE_FT =	rt_recurse_reflection \
				rt_recurse_refraction \
				rt_recurse_pixel \
				rt_recurse

ROTATE_FT = rt_quaternion_create \
			rt_quaternion_multiply \
			rt_quaternion_to_euler \
			rt_quaternion_to_matrix \
			rt_quaternion_apply \
			rt_matrix_apply \
			rt_euler_to_quaternion

SCENE_FT =	rt_scene_camera \
			rt_scene_pixels \

OPTIONS_FT =	apply_options \
				rotate_normal \
				get_noise_val \
				get_pos \
				get_checker_cylinder \
				get_checker_plane \
				get_checker_sphere \
				get_noise_value_cylinder \
				get_noise_value_plane \
				get_noise_value_sphere \
				get_tex_value_cylinder \
				get_tex_value_plane \
				get_tex_value_sphere \
				texture_maths \
				getpixel \


UTILS_FT =	color \
			rt_atof \
			rt_error \
			rt_putfloat_fd \
			rt_float3_mult \
			rt_float3_mult_float \
			rt_float3_add \
			rt_float3_min \
			rt_float_min_max \
			rt_float3_min_max \
			rt_int_min_max \

VECTOR_FT =	rt_vector_angle \
			rt_vector_cam \
			rt_vector_dot_p \
			rt_vector_impact \
			rt_vector_length \
			rt_vector_normalize \
			rt_vector_reverse \
			rt_vector_cross_p \

VISIBLE_FT = 	rt_impact_to_visible \
				rt_first_noticeable \
				rt_apply_limits \

SDL_PART_FT = event_main_side \
			init \
			event \
			rndr \
			rt_create_background \
			rt_display_interface \
			rt_get_surface \
			rt_get_text \
			rt_get_texture \
			rt_parse_button \
			rt_display_interface_2 \
			rt_display_interface_3 \
			rt_display_interface_4 \
			event_2 \


SRC_FT = main \

## List of Utilities

SRC = $(SRC_FT:%=$(SRC_DIR)/%.c) \
	$(COLLIDER_FT:%=$(SRC_DIR)/$(COLLIDER_DIR)/%.c) \
	$(DIGEST_FT:%=$(SRC_DIR)/$(DIGEST_DIR)/%.c) \
	$(FILTER_FT:%=$(SRC_DIR)/$(FILTER_DIR)/%.c) \
	$(INITIALIZE_FT:%=$(SRC_DIR)/$(INITIALIZE_DIR)/%.c) \
	$(LIGHT_FT:%=$(SRC_DIR)/$(LIGHT_DIR)/%.c) \
	$(PARSER_FT:%=$(SRC_DIR)/$(PARSER_DIR)/%.c) \
	$(PICTURE_FT:%=$(SRC_DIR)/$(PICTURE_DIR)/%.c) \
	$(RECURSIVE_FT:%=$(SRC_DIR)/$(RECURSIVE_DIR)/%.c) \
	$(ROTATE_FT:%=$(SRC_DIR)/$(ROTATE_DIR)/%.c) \
	$(SCENE_FT:%=$(SRC_DIR)/$(SCENE_DIR)/%.c) \
	$(SDL_PART_FT:%=$(SRC_DIR)/$(SDL_PART_DIR)/%.c) \
	$(UTILS_FT:%=$(SRC_DIR)/$(UTILS_DIR)/%.c) \
	$(VECTOR_FT:%=$(SRC_DIR)/$(VECTOR_DIR)/%.c) \
	$(VISIBLE_FT:%=$(SRC_DIR)/$(VISIBLE_DIR)/%.c) \
	$(OPTIONS_FT:%=$(SRC_DIR)/$(OPTIONS_DIR)/%.c) \

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(COLLIDER_DIR:%=$(OBJ_DIR)/%) \
			$(DIGEST_DIR:%=$(OBJ_DIR)/%) \
			$(FILTER_DIR:%=$(OBJ_DIR)/%) \
			$(INITIALIZE_DIR:%=$(OBJ_DIR)/%) \
			$(LIGHT_DIR:%=$(OBJ_DIR)/%) \
			$(PARSER_DIR:%=$(OBJ_DIR)/%) \
			$(PICTURE_DIR:%=$(OBJ_DIR)/%) \
			$(RECURSIVE_DIR:%=$(OBJ_DIR)/%) \
			$(ROTATE_DIR:%=$(OBJ_DIR)/%) \
			$(SCENE_DIR:%=$(OBJ_DIR)/%) \
			$(SDL_PART_DIR:%=$(OBJ_DIR)/%) \
			$(UTILS_DIR:%=$(OBJ_DIR)/%) \
			$(VECTOR_DIR:%=$(OBJ_DIR)/%) \
			$(VISIBLE_DIR:%=$(OBJ_DIR)/%) \
			$(OPTIONS_DIR:%=$(OBJ_DIR)/%) \


INCLUDES = $(INCLUDE_H:%=./$(INC_DIR)/%.h)
## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@$(CC) $(INC_FRMWK) -c $< -o $@
	@echo "$(COLOR)Compiled :\t\0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INCLUDES)
	@$(MAKE) -j $(OBJ)
	@echo "$(COLOR)Objects\t\t\0033[0;32m[Created]\0033[1;37m"
	@make -j -C $(LIB_DIR)
	@$(CC) $(LIB) $(FRMWK) $(OBJ) -o $@
	@echo "$(COLOR)$(NAME)\t\t\0033[0;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIB_DIR)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;31m[Deleted]\0033[1;37m"

re: fclean all

norme:
	@norminette $(SRC) $(INC_DIR)/
	@make norme -C $(LIB_DIR)

frameworks_clean:
	@rm -rf ./$(FRMWK_DIR)

frameworks: frameworks_clean
	@mkdir ./$(FRMWK_DIR)
	curl -o SDL2 https://www.libsdl.org/release/SDL2-2.0.8.dmg
	curl -o SDL2_image https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.3.dmg
	curl -o SDL2_ttf https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.dmg
	hdiutil attach SDL2
	hdiutil attach SDL2_image
	hdiutil attach SDL2_ttf
	cp -rf /Volumes/SDL2/SDL2.framework ./$(FRMWK_DIR)
	cp -rf /Volumes/SDL2_image/SDL2_image.framework ./$(FRMWK_DIR)
	cp -rf /Volumes/SDL2_ttf/SDL2_ttf.framework ./$(FRMWK_DIR)
	hdiutil detach /Volumes/SDL2
	hdiutil detach /Volumes/SDL2_image
	hdiutil detach /Volumes/SDL2_ttf
	rm -rf SDL2
	rm -rf SDL2_image
	rm -rf SDL2_ttf

coffee: libs frameworks all

libs_clean:
	@rm -rf ./libxml2
	@rm -rf ./libpng

libs: libs_clean
	curl -o XML2 ftp://xmlsoft.org/libxml2/libxml2-2.9.8.tar.gz
	curl -o PNG ftp://ftp-osl.osuosl.org/pub/libpng/src/libpng16/libpng-1.6.34.tar.gz
	gunzip -c XML2 | tar xopf -
	gunzip -c PNG | tar xopf -
	rm -rf XML2
	rm -rf PNG
	mkdir ./libxml2
	mkdir ./libpng
	(cd ./libxml2 && ../libxml2-2.9.8/configure --prefix=$$PWD --with-python-install-dir=$$PWD/python)
	(cd ./libpng && ../libpng-1.6.34/configure --prefix=$$PWD)
	(cd ./libxml2 && make && make install)
	(cd ./libpng && make && make install)
	rm -r ./libxml2-2.9.8
	rm -r ./libpng-1.6.34

.PHONY: all clean fclean re norme frameworks frameworks_clean libs libs_clean coffee
