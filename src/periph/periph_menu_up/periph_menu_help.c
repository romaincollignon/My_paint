/*
** EPITECH PROJECT, 2022
** periph_menu_help.c
** File description:
** Function : periph_menu_help
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

void suite_periph_file_open(sfRenderWindow* w, i_g *info_game,
    i_m_h *info_menu_home)
{
    sfColor color_cli = {0, 0, 0, 255};
        sfRenderWindow_drawText(w,
        info_menu_home->info_menu.text_look_t, NULL);
    sfRenderWindow_display(w);
    sfRectangleShape_setFillColor(
        info_menu_home->info_menu.rect_file[3], color_cli);
    load_file_img(info_game, info_menu_home);
    info_menu_home->info_display.tmp_textu = sfTexture_createFromImage(
        info_menu_home->info_display.image_default, NULL);
    sfSprite_setTexture(info_menu_home->info_display.fond_default,
        info_menu_home->info_display.tmp_textu, NULL);
}

void open_menu_help(i_m_h *info_menu_home)
{
    if ((sfClock_getElapsedTime
        (info_menu_home->info_menu.time_help).microseconds > 100000)) {

        if (info_menu_home->info_menu.choose_menu == 3)
            info_menu_home->info_menu.choose_menu = 0;
        else
            info_menu_home->info_menu.choose_menu = 3;
        sfClock_restart(info_menu_home->info_menu.time_help);
    }
}

void periph_menu_help_save_open(sfRenderWindow* w, i_m_h *info_menu_home)
{
    int zone_help_save_open[4] = {160, 365, 65, 95};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help_save_open, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            print_help_1(info_menu_home, 1);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[1], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help);
            return;
        } else
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[1], color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_help[1],
            color_default);
    }
}

void main_periph_menu_help(sfRenderWindow* w, i_m_h *info_menu_home)
{
    periph_menu_help_save_open(w, info_menu_home);
    periph_menu_help_paint_eraser(w, info_menu_home);
    periph_menu_help_set_color(w, info_menu_home);
    periph_menu_help_zoom(w, info_menu_home);
    periph_menu_help_credit(w, info_menu_home);
    periph_menu_help_exit(w, info_menu_home);
    if (info_menu_home->info_menu.choose_menu == 3) {
        sfRenderWindow_drawText(w, info_menu_home->info_menu.text_lo_t_h, NULL);
    }
}

int periph_menu_help(sfRenderWindow* w, i_m_h *info_menu_home, sfEvent act)
{
    int zone_help[4] = {225, 310, 15, 50};
    sfColor color_def = {34, 33, 37, 255};
    sfColor color_pas = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            open_menu_help(info_menu_home);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(info_menu_home->bouton[2], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help);
            return 1;
        } else
            sfRectangleShape_setFillColor(info_menu_home->bouton[2], color_pas);
    } else {
        if (info_menu_home->info_menu.choose_menu != 3)
            sfRectangleShape_setFillColor(info_menu_home->bouton[2], color_def);
    } if (info_menu_home->info_menu.choose_menu == 3)
        main_periph_menu_help(w, info_menu_home);
    return 0;
}
