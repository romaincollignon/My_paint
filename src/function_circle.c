/*
** EPITECH PROJECT, 2022
** function_circle.c
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

#include "../include/struct_all.h"
#include "my.h"

void suite_draw_circle_r(i_m_h *info_menu_home, int i, int j, int r)
{
    if (i * i + j * j <= r * r) {
        setpixel_ruber(info_menu_home,
            (sfVector2i) {(float) (info_menu_home->info_display.last_x),
                (info_menu_home->info_display.last_y)},
            (sfVector2i) {(float) (i), (j)},
            sfSprite_getScale(info_menu_home->info_display.fond_default));
    }
}

void draw_circle_r(i_m_h *info_menu_home, int x, int y, int r)
{
    info_menu_home->info_display.last_x = x;
    info_menu_home->info_display.last_y = y;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            suite_draw_circle_r(info_menu_home, i, j, r);
        }
    }
    sfTexture_updateFromImage(info_menu_home->info_display.tmp_textu,
        info_menu_home->info_display.image_default, 0, 0);
    sfSprite_setTexture(info_menu_home->info_display.fond_default,
        info_menu_home->info_display.tmp_textu, NULL);
}

void suite_draw_circle_p(i_m_h *info_menu_home, int i, int j, int r)
{
    if (i * i + j * j <= r * r) {
        setpixel_paint(info_menu_home,
            (sfVector2i) {(float) (
                info_menu_home->info_display.last_x / info_menu_home->rad_x_w),
            (info_menu_home->info_display.last_y / info_menu_home->rad_y_w)},
            (sfVector2i) {(float) (i), (j)},
            sfSprite_getScale(info_menu_home->info_display.fond_default));
    }
}

void draw_circle_p(i_m_h *info_menu_home, int x, int y, int r)
{
    info_menu_home->info_display.last_x = x;
    info_menu_home->info_display.last_y = y;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            suite_draw_circle_p(info_menu_home, i, j, r);
        }
    } sfTexture_updateFromImage(info_menu_home->info_display.tmp_textu,
        info_menu_home->info_display.image_default, 0, 0);
    sfSprite_setTexture(info_menu_home->info_display.fond_default,
        info_menu_home->info_display.tmp_textu, NULL);
}
