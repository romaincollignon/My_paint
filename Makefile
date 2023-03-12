##
## EPITECH PROJECT, 2022
## makefile
## File description:
## My_paint
##

SRC 	=	src/function/mini_printf.c \
			src/function/my_put_nbr.c \
			src/function/my_putchar.c \
			src/function/my_putstr.c \
			src/function/my_compute_power_rec.c \
			src/function/my_revstr.c \
			src/function/my_strcp.c \
			src/function/my_str_to_word_array.c \
			src/function/my_getnbr.c \
			src/function/int_pass_char.c \
			src/menu/menu_loading/init_loading.c \
			src/menu/menu_loading/loading_display.c \
			src/menu/menu_loading/menu_loading.c \
			src/periph/periph_menu_loading.c \
			src/menu/menu_home/init/init_home.c \
			src/menu/menu_home/init/init_display.c \
			src/menu/menu_home/init/init_bouton_tools.c \
			src/menu/menu_home/init/init_paint.c \
			src/menu/menu_home/init/init_menu_tools.c \
			src/menu/menu_home/init/init_menu_up/init_m_file.c \
			src/menu/menu_home/init/init_menu_up/init_m_edition.c \
			src/menu/menu_home/init/init_menu_up/init_m_help.c \
			src/menu/menu_home/menu_up_display.c \
			src/menu/menu_home/home_display.c \
			src/menu/menu_home/menu_home.c \
			src/menu/menu_home/load_file_img.c \
			src/menu/menu_home/save_file_img.c \
			src/menu/menu_home/suite_save_file_img.c \
			src/periph/periph_menu_home.c \
			src/periph/periph_menu_home_tools.c \
			src/periph/periph_menu_up/periph_menu_up.c \
			src/periph/periph_menu_up/periph_help_suite.c \
			src/periph/periph_menu_up/print_menu_periph_help.c \
			src/periph/periph_menu_up/periph_menu_file.c \
			src/periph/periph_menu_up/periph_menu_edition.c \
			src/periph/periph_menu_up/periph_menu_edition_tools.c \
			src/periph/periph_menu_up/periph_menu_help.c \
			src/periph/bouton_tools/periph_bouton_tools_01.c \
			src/periph/bouton_tools/periph_bouton_tools_02.c \
			src/periph/bouton_display/periph_choose_paint.c \
			src/periph/tools/paint.c \
			src/periph/tools/pipette.c \
			src/periph/tools/color.c \
			src/periph/tools/rubber.c \
			src/periph/tools/magnifier.c \
			src/init.c \
			src/function.c \
			src/function_circle.c \
			src/main.c

OBJ	=	$(SRC:.c=.o)

CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS = -Wall -Wextra -I ./include/ -g

NAME	=	my_paint

all:	$(NAME)

$(NAME): $(OBJ)
	@echo -e "🔨 \033[0;32mCompile My paint \033[0;30m🔨"
	gcc $(OBJ) $(CFLAGS) $(CSFMLFLAGS)  -o $(NAME) -lncurses
	@echo -e "✅ \033[0;31mMy paint is compiled ✅ \033[0m"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug :
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g $(CFLAGS) $(CSFMLFLAGS)

.PHONY:	all clean fclean re
