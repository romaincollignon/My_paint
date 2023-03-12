/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes and include
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Event.h>

    #include "struct_all.h"
    #include "my.h"

    // Function:
    int mini_printf(const char *format, ...);
    char **read_file(char *av[]);
    int mini_printf(const char *format, ...);
    int printf_credit(int tmp);
    int my_strlen(char const *str);
    char *my_put_nbr_modif(int nb);
    int	my_getnbr(char const *str);
    int my_power(int nb, int p);
    char **my_double_tab(char *buffer, char separator);
    int my_strcmp(char const *s1, char const *s2);
    char *my_put_nbr_modif(int nb);
    char *my_put_nbr_double(int nb);
    char *my_revstr(char *str);
    char* my_inv_double_tab(char** txt);
    char* my_inv_double_tab_html(char** txt);
    char *my_strcpy(char *dest, char const *src);
    char **my_str_to_word_array(char *b_tab);
    void fill(char *str, int size);
    char pass_char_wait(int hit, int pos);
    char* int_pass_char(int nbr);

    // Function:
    sfVector2f get_position(int x, int y);
    sfText* init_txt(i_m_h *info_menu_home, char *txt, int x, int y);
    void setpixel_paint(i_m_h *info_menu_home, sfVector2i v, sfVector2i add,
        sfVector2f scale);
    void setpixel_ruber(i_m_h *info_menu_home, sfVector2i v, sfVector2i add,
        sfVector2f scale);
    void draw_circle_r(i_m_h *info_menu_home, int x, int y, int r);
    void draw_circle_p(i_m_h *info_menu_home, int x, int y, int r);
    sfText* init_txt_menu(sfText *text, sfVector2f position, char *str,
        int size);
    void calc_r_windo(sfRenderWindow *w, i_m_h *info_menu_home);
    sfColor my_getpixel(sfRenderWindow *w, sfImage *img, sfVector2i mouse);

    // Init:
    int init_struct(i_g *info_game);
    sfSprite* init_fond(char *image);
    sfRectangleShape* init_bar(i_m_h *info_menu_home, int pos,
        sfVector2f size, sfVector2f position);
    void init_menu(i_m_h *info_menu_home);
    void init_m_file(i_m_h *info_menu_home);
    void init_m_edition(i_m_h *info_menu_home);
    void init_m_help(i_m_h *info_menu_home);
    int periph_menu_up(sfRenderWindow* w, i_g *info_game, i_m_h *info_menu_home,
        sfEvent act);

    // Menu_loading:
    void menu_loading(i_g *info_game, sfRenderWindow *window);
    void menu_loading_display(sfRenderWindow *window, i_g *info_game,
        i_m_l *info_menu_loading);
    void init_struct_menu_load(i_m_l *info_menu_loading);
    int perif_menu_load(sfRenderWindow* w, i_g *info_game,
        i_m_l *info_menu_loading);

    // Init_Home
    void init_struct_menu_home(i_m_h *info_menu_home);
    void init_display(i_m_h *info_menu_home);
    void init_paint(i_m_h *info_menu_home, i_g *info_game);
    void init_menu_tools(i_m_h *info_menu_home);

    // Menu_home:
    void menu_home(i_g *info_game, sfRenderWindow *window);
    void suite_init_struct_menu_home(i_m_h *info_menu_home);
    void menu_home_display(sfRenderWindow *window, i_g *info_game,
        i_m_h *info_menu_home);
    int perif_menu_home(sfRenderWindow* w, i_g *info_game,
        i_m_h *info_menu_home);
    void verif_pass_mouse_tools(sfRenderWindow *w, i_m_h *info_menu_home);
    void load_file_img(i_g *info_game, i_m_h *info_menu_home);
    void menu_up_display(sfRenderWindow *window, i_m_h *info_menu_home);
    void save_file_img(i_g *info_game, i_m_h *info_menu_home);
    char *extension_file(i_g * info_game, char *file);

    // Verif_position:
    int verif_zone(int* zone, sfRenderWindow* window);

    // Tools:
    int periph_tools_paint(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
        sfEvent act);
    void periph_tools_pipette(sfWindow *w, i_m_h *info_menu_home);
    void periph_tools_color(sfWindow *w, i_m_h *info_menu_home);
    int periph_tools_rubber(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
        sfEvent act);
    int periph_tools_magnifier(sfWindow *w, i_g *info_game,
        i_m_h *info_menu_home, sfEvent act);
    void display_error_zoom(sfWindow *w, i_m_h *info_menu_home);

    // Periph_menu_up:
    int periph_menu_file(sfRenderWindow* w, i_g *info_game,
        i_m_h *info_menu_home, sfEvent act);
    int periph_menu_edition(sfRenderWindow* w, i_m_h *info_menu_home,
        sfEvent act);
    int periph_menu_help(sfRenderWindow* w, i_m_h *info_menu_home,
        sfEvent act);
    void periph_menu_edition_paint(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_edition_pipette(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_edition_eraser(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_edition_color(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_edition_zoom(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_help_paint_eraser(
        sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_help_set_color(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_help_zoom(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_help_credit(sfRenderWindow* w, i_m_h *info_menu_home);
    void periph_menu_help_exit(sfRenderWindow* w, i_m_h *info_menu_home);

    // Print_help:
    void print_help_1(i_m_h *info_menu_home, int pos);
    void print_help_2(i_m_h *info_menu_home, int pos);
    void print_help_3(i_m_h *info_menu_home, int pos);

    // Periph_tools:
    void one_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void two_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void three_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void four_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void five_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void six_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void seven_tool(sfRenderWindow *w, i_m_h *info_menu_home);
    void press_tool(sfRenderWindow *w, i_m_h *info_menu_home, sfEvent act);

    void periph_choose_paint(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
        sfEvent act);

    // Suite -> CODING STYLE
    void suite_periph_file_open(sfRenderWindow* w, i_g *info_game,
        i_m_h *info_menu_home);

    // Color:
    #define CDEF  "\x1B[0m"

    #define CBLD  "\x1B[1m"
    #define CFNT  "\x1B[2m"
    #define CITA  "\x1B[3m"
    #define CUND  "\x1B[4m"
    #define CINV  "\x1B[7m"
    #define CTGH  "\x1B[9m"
    #define CBLK  "\x1B[30m"
    #define CRED  "\x1B[31m"
    #define CGRN  "\x1B[32m"
    #define CYEL  "\x1B[33m"
    #define CBLU  "\x1B[34m"
    #define CMAG  "\x1B[35m"
    #define CCYN  "\x1B[36m"
    #define CWHT  "\x1B[37m"


#endif /* !MY_H_ */
