/*
** EPITECH PROJECT, 2022
** periph_up.c
** File description:
** Function : cherch_perif
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>

#include "../../../include/struct_all.h"
#include "my.h"

static void verif_pass_mouse_button_suite(sfRenderWindow* w, i_g *info_game,
    i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_exit[4] = {1810, 1910, 15, 50};
    if (verif_zone(zone_exit, w) == 1) {
        sfRectangleShape_setFillColor(info_menu_home->bouton[3], sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            info_game->env = 0;
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton[3], color_default);
    }
}

void all_other_periph(sfRenderWindow* w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    periph_menu_file(w, info_game, info_menu_home, act);
    periph_menu_edition(w, info_menu_home, act);
    periph_menu_help(w, info_menu_home, act);
    int zone_help[4] = {230, 313, 15, 50};
    verif_pass_mouse_button_suite(w, info_game, info_menu_home);
    periph_menu_edition_paint(w, info_menu_home);
    periph_menu_edition_pipette(w, info_menu_home);
    periph_menu_edition_eraser(w, info_menu_home);
    periph_menu_edition_color(w, info_menu_home);
    periph_menu_edition_zoom(w, info_menu_home);
}

int periph_menu_up(sfRenderWindow* w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    int zone_menu_up[4] = {0, 1920, 0, 65};
    int zone_menu_file[4] = {10, 85, 65, 175};
    int zone_menu_edition[4] = {100, 205, 65, 255};
    int zone_edition[4] = {90, 220, 15, 50};
    sfColor color_default = {34, 33, 37, 255};
    if (info_menu_home->info_menu.choose_menu != 2)
        sfRectangleShape_setFillColor(info_menu_home->bouton[1],
            color_default);
    if (verif_zone(zone_menu_up, w) == 0 && verif_zone(zone_menu_file, w) == 0
    && verif_zone(zone_edition, w) == 0 &&
    info_menu_home->info_menu.choose_menu != 3
    && info_menu_home->info_menu.choose_menu != 2)
        return 0;
    if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
        info_game->env = 0;
        return 1;
    } all_other_periph(w, info_game, info_menu_home, act);
    if (info_menu_home->info_menu.choose_menu == 2)
        return 0;
    return 1;
}
