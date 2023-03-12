/*
** EPITECH PROJECT, 2022
** magnifier.c
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

#include "../../../include/struct_all.h"
#include "my.h"

void display_error_zoom(sfWindow *w, i_m_h *info_menu_home)
{
    int zone_01[4] = {0, 100, 180, 830};
    if (verif_zone(zone_01, w) == 1) {
        sfRenderWindow_drawText(w, info_menu_home->info_display.txt[7], NULL);
        sfRenderWindow_display(w);
        sfTime time_sleep = {.microseconds = 10000};
        sfSleep(time_sleep);
    }
    return;
}

void magnifier_zoom(i_m_h *info_menu_home)
{
    sfVector2f tmp_scal =
        sfSprite_getScale(info_menu_home->info_display.fond_default);
    tmp_scal.x = tmp_scal.x + 0.0005;
    tmp_scal.y = tmp_scal.y + 0.0005;
    sfSprite_setScale(info_menu_home->info_display.fond_default, tmp_scal);
    info_menu_home->info_display.change_tools = 1;
    return;
}

void magnifier_unzoom(i_m_h *info_menu_home)
{
    sfVector2f tmp_scal =
        sfSprite_getScale(info_menu_home->info_display.fond_default);
    if (tmp_scal.x < 0.001)
        return;
    if (tmp_scal.x > 1000)
        return;
    tmp_scal.x = tmp_scal.x - 0.0005;
    tmp_scal.y = tmp_scal.y - 0.0005;
    sfSprite_setScale(info_menu_home->info_display.fond_default, tmp_scal);
    return;
}

int suite_periph_tools_magnifier(sfWindow *w, i_m_h *info_menu_home,
    sfEvent act)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_moins[4] = {115, 165, 700, 750};
    if (verif_zone(zone_moins, w) == 1) {
        sfRectangleShape_setFillColor(
            info_menu_home->info_display.menu_tools[9], color_pass);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            magnifier_unzoom(info_menu_home);
        return 1;
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_display.menu_tools[9], color_default);
        return 0;
    }
}

int periph_tools_magnifier(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    if (info_menu_home->click_bouton_tools != 5)
        return 0;
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_add[4] = {115, 165, 640, 690};
    if (verif_zone(zone_add, w) == 1) {
        sfRectangleShape_setFillColor(
            info_menu_home->info_display.menu_tools[8], color_pass);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            magnifier_zoom(info_menu_home);
        return 1;
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_display.menu_tools[8], color_default);
    }
    return suite_periph_tools_magnifier(w, info_menu_home, act);
}
