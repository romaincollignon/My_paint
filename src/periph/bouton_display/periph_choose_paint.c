/*
** EPITECH PROJECT, 2022
** periph_choose_paint.c
** File description:
** Function : periph_choose_paint
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

void suite_suite_choose_paint(sfWindow *w, i_g *info_game,
    i_m_h *info_menu_home, sfEvent act)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_pres = {14, 13, 17, 255};
    int zone_black[4] = {605, 1345, 780, 870};
    if (verif_zone(zone_black, w) == 1) {
        if (act.type == sfEvtMouseButtonPressed) {
            info_game->choose_paint = 4;
            sfRectangleShape_setFillColor(
                info_menu_home->info_display.bouton[5], color_pres);
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_display.bouton[5], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_display.bouton[5],
            color_default);
    }
}

void suite_choose_paint(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_black[4] = {990, 1340, 335, 775};
    if (verif_zone(zone_black, w) == 1) {
        if (act.type == sfEvtMouseButtonPressed)
            info_game->choose_paint = 1;
        else
            sfRectangleShape_setFillColor(
                info_menu_home->info_display.bouton[2], color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_display.bouton[2],
            color_default);
    }
    suite_suite_choose_paint(w, info_game, info_menu_home, act);
}

void verif_pass_mouse_button_choose_paint(sfWindow *w, i_g *info_game,
    i_m_h *info_menu_home, sfEvent act)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_white[4] = {600, 950, 335, 775};
    if (verif_zone(zone_white, w) == 1) {
        if (act.type == sfEvtMouseButtonPressed)
            info_game->choose_paint = 2;
        else
            sfRectangleShape_setFillColor(
                info_menu_home->info_display.bouton[1], color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_display.bouton[1],
            color_default);
    }
    suite_choose_paint(w, info_game, info_menu_home, act);
}

void periph_choose_paint(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    if (info_game->choose_paint == 4)
        return;
    while (sfRenderWindow_pollEvent(w, &act)) {
        verif_pass_mouse_button_choose_paint(w, info_game, info_menu_home,
            act);
        if (act.type == sfEvtClosed) {
            info_game->env = 0;
            return;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
            info_game->env = 0;
            return;
        }
    }
}
