/*
** EPITECH PROJECT, 2022
** menu_home.c
** File description:
** Function : menu_home
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>

#include "../../../include/struct_all.h"
#include "my.h"

void free_all(i_m_h *info_menu_home)
{
    sfText_destroy(info_menu_home->txt_file);
    sfText_destroy(info_menu_home->txt_edition);
    sfText_destroy(info_menu_home->txt_help);
    sfText_destroy(info_menu_home->txt_reset);
    sfClock_destroy(info_menu_home->info_menu.time_file);
    sfRectangleShape_destroy(info_menu_home->bar_up);
    sfFont_destroy(info_menu_home->font_txt_default);
    sfImage_destroy(info_menu_home->info_display.image_color);
    sfSprite_destroy(info_menu_home->image_color);
}

void menu_home(i_g *info_game, sfRenderWindow *window)
{
    info_game->custom_paint = 0;
    sfRenderWindow_clear(window, sfBlack);
    sfSprite* font = init_fond("./res/fond/fond_home.png");
    i_m_h *info_menu_home = malloc(sizeof(i_m_h));
    init_struct_menu_home(info_menu_home);
    info_game->display = 1;
    while (info_game->env == 1 && sfRenderWindow_isOpen(window)) {
        if (info_game->choose_paint == 1 || info_game->choose_paint == 2)
            init_paint(info_menu_home, info_game);
        sfRenderWindow_drawSprite(window, font, NULL);
        menu_home_display(window, info_game, info_menu_home);
        if (info_game->choose_paint == 4) {
            sfRenderWindow_display(window);
            load_file_img(info_game, info_menu_home);
        }
        perif_menu_home(window, info_game, info_menu_home);
        sfRenderWindow_display(window);
    }
    free_all(info_menu_home);
}
