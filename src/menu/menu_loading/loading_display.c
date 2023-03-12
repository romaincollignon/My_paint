/*
** EPITECH PROJECT, 2022
** menu_basic_display.c
** File description:
** Function : menu_basic_display
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

void menu_loading_display(sfRenderWindow *window, i_g *info_game,
    i_m_l *info_menu_loading)
{
    sfRenderWindow_drawText(window, info_menu_loading->txt_wait, NULL);
    sfRenderWindow_drawText(window, info_menu_loading->txt_load, NULL);
    sfRenderWindow_drawText(window, info_menu_loading->txt_leave, NULL);
    sfRenderWindow_drawRectangleShape(window, info_menu_loading->contour, NULL);
    int nb_time = (
        sfClock_getElapsedTime(info_menu_loading->time).microseconds / 1000);
    if (nb_time > 685) {
        info_game->env = 1;
    }
    sfVector2f size = {nb_time, 20};
    sfRectangleShape_setSize((info_menu_loading->bar_load), size);
    sfRenderWindow_drawRectangleShape(
        window, info_menu_loading->bar_load, NULL);
}
