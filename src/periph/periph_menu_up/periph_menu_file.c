/*
** EPITECH PROJECT, 2022
** periph_menu_file.c
** File description:
** Function : periph_menu_file
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

int periph_menu_file_open(sfRenderWindow* w, i_g *info_game,
    i_m_h *info_menu_home)
{
    int zone_file_new[4] = {15, 83, 140, 170};
    sfColor co_d = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    if (verif_zone(zone_file_new, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            suite_periph_file_open(w, info_game, info_menu_home);
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_file[3], color_pass);
        } return 1;
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_file[3],
            co_d);
    } return 0;
}

int periph_menu_file_save(sfRenderWindow* w, i_g *info_game,
    i_m_h *info_menu_home)
{
    int zone_file_new[4] = {15, 83, 100, 130};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_file_new, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_drawText(w,
                info_menu_home->info_menu.text_look_t, NULL);
            sfRenderWindow_display(w);
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_file[2], color_cli);
            save_file_img(info_game, info_menu_home);
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_file[2], color_pass);
        } return 1;
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_file[2],
            color_default);
    } return 0;
}

int periph_menu_file_new(sfRenderWindow* w, i_g *info_game,
    i_m_h *info_menu_home)
{
    int zone_file_new[4] = {15, 83, 65, 95};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_file_new, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_file[1], color_cli);
            info_game->choose_paint = -1;
            return 1;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_file[1], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->info_menu.rect_file[1],
            color_default);
    } return 0;
}

void open_menu_file(i_m_h *info_menu_home)
{
    if ((sfClock_getElapsedTime
        (info_menu_home->info_menu.time_edition).microseconds > 100000)) {

        if (info_menu_home->info_menu.choose_menu == 1)
            info_menu_home->info_menu.choose_menu = 0;
        else
            info_menu_home->info_menu.choose_menu = 1;
        sfClock_restart(info_menu_home->info_menu.time_file);
    }
}

int periph_menu_file(sfRenderWindow* w, i_g *info_game,
    i_m_h *info_menu_home, sfEvent act)
{
    int zone_file[4] = {10, 80, 15, 50}; sfColor color_def = {34, 33, 37, 255};
    sfColor color_pas = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_file, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            open_menu_file(info_menu_home);
        if (sfMouse_isButtonPressed(sfMouseLeft) && (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_file).microseconds < 100000)) {
            sfRectangleShape_setFillColor(info_menu_home->bouton[0], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_edition);
            return 1;
        } else
            sfRectangleShape_setFillColor(info_menu_home->bouton[0], color_pas);
    } else {
        if (info_menu_home->info_menu.choose_menu != 1)
            sfRectangleShape_setFillColor(info_menu_home->bouton[0], color_def);
    } if (info_menu_home->info_menu.choose_menu != 1) return 1;
    if (periph_menu_file_new(w, info_game, info_menu_home) == 1) return 1;
    if (periph_menu_file_save(w, info_game, info_menu_home) == 1) return 1;
    if (periph_menu_file_open(w, info_game, info_menu_home) == 1) return 1;
    return 0;
}
