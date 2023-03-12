/*
** EPITECH PROJECT, 2022
** menu_loading.c
** File description:
** Function : menu_loading
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

void free_loading(i_m_l *info_menu_loading)
{
    sfClock_destroy(info_menu_loading->time);
    sfFont_destroy(info_menu_loading->Font_txt_01);
    sfText_destroy(info_menu_loading->txt_load);
    sfText_destroy(info_menu_loading->txt_leave);
}

void menu_loading(i_g *info_game, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite* font = init_fond("./res/fond/fond_start.jpg");
    i_m_l *info_menu_loading = malloc(sizeof(i_m_l));
    init_struct_menu_load(info_menu_loading);
    while (info_game->env == -1 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, font, NULL);
        menu_loading_display(window, info_game, info_menu_loading);
        perif_menu_load(window, info_game, info_menu_loading);
        sfRenderWindow_display(window);
    }
    free_loading(info_menu_loading);
}
