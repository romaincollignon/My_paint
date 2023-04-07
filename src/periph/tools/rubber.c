/*
** EPITECH PROJECT, 2022
** rubber.c
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
#include <math.h>

#include "../../../include/struct_all.h"
#include "my.h"

void update_image_rubber(sfWindow *w, i_m_h *info_menu_home, int pos_y,
    int pos_x)
{
    int zone_01[4] = {185, 10000, 130, 10000};
    if (verif_zone(zone_01, w) == 0)
        return;
    int size_rub = info_menu_home->info_display.size_rubber;
    int mid = size_rub / 2;
    for (int x = 0; x < size_rub; x++) {
        for (int y = 0; y < size_rub; y++) {
            setpixel_ruber(info_menu_home,
                (sfVector2i) {(float) (pos_x - mid) / info_menu_home->rad_x_w,
                (pos_y - mid) / info_menu_home->rad_y_w},
                (sfVector2i) {(float) (x), (y)},
                sfSprite_getScale(info_menu_home->info_display.fond_default));
        }
    }
    sfTexture_updateFromImage(info_menu_home->info_display.tmp_textu,
        info_menu_home->info_display.image_default, 0, 0);
    sfSprite_setTexture(info_menu_home->info_display.fond_default,
        info_menu_home->info_display.tmp_textu, sfFalse);
}

void edit_size_ruber(sfWindow *w, i_m_h *info_menu_home, int pos_y,
    int pos_x)
{
    int zone_01[4] = {110, 170, 370, 630};
    if (verif_zone(zone_01, w) == 0)
        return;
    sfVector2u size_w = sfWindow_getSize(w);
    float height = size_w.y;
    float radio_y = height / 1029;
    info_menu_home->info_display.size_rubber = ((pos_y - (367 * radio_y)) * 2);
    sfRectangleShape_setPosition(info_menu_home->info_display.menu_tools[3],
        (sfVector2f){120, (pos_y / radio_y)});
    sfText_setString(info_menu_home->info_display.txt[3],
        int_pass_char(info_menu_home->info_display.size_rubber));
}

int change_form_ruber(sfWindow *w, i_m_h *info_menu_home, int pos_y,
    int pos_x)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {110, 170, 700, 770};
    if (verif_zone(zone_01, w) == 0) {
        sfRectangleShape_setFillColor(
            info_menu_home->info_display.form_rubber[1], color_default);
        return 0;
    } sfRectangleShape_setFillColor(
        info_menu_home->info_display.form_rubber[1], color_pass);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfClock_getElapsedTime
            (info_menu_home->info_display.coldown).microseconds < 700000) {
            return 1;
        } if (info_menu_home->info_display.choose_rubber == 0)
            info_menu_home->info_display.choose_rubber = 1;
        else
            info_menu_home->info_display.choose_rubber = 0;
        sfClock_restart(info_menu_home->info_display.coldown);
        return 1;
    } return 0;
}

void periph_tools_rubber_circle(sfWindow *w, i_m_h *info_menu_home,
    int pos_y, int pos_x)
{
    int zone_01[4] = {185, 10000, 130, 10000};
    if (verif_zone(zone_01, w) == 0)
        return;
    draw_circle_r(info_menu_home,
        pos_x / info_menu_home->rad_x_w,
        pos_y / info_menu_home->rad_y_w,
        info_menu_home->info_display.size_rubber);
}

int periph_tools_rubber(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    if (info_menu_home->click_bouton_tools != 3)
        return 0;
    sfVector2i mouse = sfMouse_getPosition(w);
    if (change_form_ruber(w, info_menu_home, mouse.y, mouse.x) == 1)
        return 1;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        edit_size_ruber(w, info_menu_home, mouse.y, mouse.x);
        if (info_menu_home->info_display.choose_rubber == 0) {
            update_image_rubber(w, info_menu_home, mouse.y, mouse.x);
        } else {
            periph_tools_rubber_circle(w, info_menu_home, mouse.y, mouse.x);
        }
        return 1;
    } else {
        return 0;
    }
}
