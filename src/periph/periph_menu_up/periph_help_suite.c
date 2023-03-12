/*
** EPITECH PROJECT, 2022
** periph_help_suite.c
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

void periph_menu_help_paint_eraser(sfRenderWindow* w, i_m_h *info_menu_home)
{
    int zone_help_save_open[4] = {160, 365, 100, 135};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help_save_open, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            print_help_1(info_menu_home, 2);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[2], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help); return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[2], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_help[2],
            color_default);
    }
}

void periph_menu_help_set_color(sfRenderWindow* w, i_m_h *info_menu_home)
{
    int zone_help_save_open[4] = {160, 365, 140, 170};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help_save_open, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            print_help_2(info_menu_home, 1);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[3], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help); return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[3], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_help[3],
            color_default);
    }
}

void periph_menu_help_zoom(sfRenderWindow* w, i_m_h *info_menu_home)
{
    int zone_help_save_open[4] = {160, 365, 175, 210};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help_save_open, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            print_help_2(info_menu_home, 2);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[4], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help); return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[4], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_help[4],
            color_default);
    }
}

void periph_menu_help_credit(sfRenderWindow* w, i_m_h *info_menu_home)
{
    int zone_help_save_open[4] = {160, 365, 215, 252};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help_save_open, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            print_help_3(info_menu_home, 1);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[5], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help); return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[5], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_help[5],
            color_default);
    }
}

void periph_menu_help_exit(sfRenderWindow* w, i_m_h *info_menu_home)
{
    int zone_help_01[4] = {160, 365, 260, 293}; sfColor def = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_help_01, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            print_help_3(info_menu_home, 2);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_help).microseconds < 100000)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[6], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_help);
            return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_help[6], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_help[6],
            def);
    }
}
