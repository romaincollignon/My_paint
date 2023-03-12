/*
** EPITECH PROJECT, 2022
** periph_menu_loading.c
** File description:
** Function :
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>

#include "../../include/struct_all.h"
#include "my.h"

int verif_zone(int* zone, sfRenderWindow* window)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    sfVector2u size_w = sfWindow_getSize(window);
    float width = size_w.x;
    float height = size_w.y;
    float radio_x = width / 1920;
    float radio_y = height / 1029;
    zone[0] *= radio_x;
    zone[1] *= radio_x;
    zone[2] *= radio_y;
    zone[3] *= radio_y;
    if (mouse.x >= zone[0] && mouse.x <= zone[1]) {
        if (mouse.y >= zone[2] && mouse.y <= zone[3])
            return 1;
    }
    return 0;
}

static void verif_pass_mouse_button(sfRenderWindow* w, i_m_l *info_menu_loading)
{
    int zone_leave[4] = {1450, 1900, 980, 1010};
    if (verif_zone(zone_leave, w) == 1)
        sfText_setColor(info_menu_loading->txt_leave, sfRed);
    else
        sfText_setColor(info_menu_loading->txt_leave, sfWhite);
}

int perif_menu_load(sfRenderWindow* w, i_g *info_game, i_m_l *info_menu_loading)
{
    int zone_leave[4] = {1450, 1900, 980, 1010};
    sfEvent act;
    while (sfRenderWindow_pollEvent(w, &act)) {
        verif_pass_mouse_button(w, info_menu_loading);
        if (act.type == sfEvtClosed) {
            info_game->env = 0;
            return 0;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
            info_game->env = 0;
            return 0;
        } if (verif_zone(zone_leave, w) == 1 &&
            act.type == sfEvtMouseButtonPressed) {
            info_game->env = 0;
        }
    } return 0;
}
