/*
** EPITECH PROJECT, 2022
** function.c
** File description:
** Function : get_position
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

#include "../include/struct_all.h"
#include "my.h"

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;
    vector.y = y;
    vector.x = x;
    return vector;
}

void setpixel_ruber(i_m_h *info_menu_home, sfVector2i v, sfVector2i add,
    sfVector2f scale)
{
    sfImage *img = info_menu_home->info_display.image_default;
    sfColor color = info_menu_home->info_display.color_rubber;
    sfVector2u size = sfImage_getSize(img);
    v.x = (v.x - 180) / scale.x;
    v.y = (v.y - 130) / scale.y;
    v.x += add.x;
    v.y += add.y;
    if (v.x >= size.x)
        return;
    if (v.y >= size.y)
        return;
    sfImage_setPixel(img, v.x, v.y, color);
}

void setpixel_paint(i_m_h *info_menu_home, sfVector2i v, sfVector2i add,
    sfVector2f scale)
{
    sfImage *img = info_menu_home->info_display.image_default;
    sfColor color = info_menu_home->info_display.tmp_color;
    sfVector2u size = sfImage_getSize(img);
    v.x = (v.x - 180) / scale.x;
    v.y = (v.y - 130) / scale.y;
    v.x += add.x;
    v.y += add.y;
    if (v.x >= size.x)
        return;
    if (v.y >= size.y)
        return;
    sfImage_setPixel(img, v.x, v.y, color);
}

void calc_r_windo(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfVector2u size_w = sfWindow_getSize(w);
    float width = size_w.x;
    float height = size_w.y;
    float radio_x = width / 1920;
    float radio_y = height / 1029;
    info_menu_home->rad_x_w = radio_x;
    info_menu_home->rad_y_w = radio_y;
}

sfColor my_getpixel(sfRenderWindow *w, sfImage *img, sfVector2i mouse)
{
    sfVector2u size_w = sfWindow_getSize(w);
    float width = size_w.x;
    float height = size_w.y;
    float radio_x = width / 1920;
    float radio_y = height / 1029;

    float tmp_x = (mouse.x - (150 * radio_x)) / 0.6;
    float tmp_y = (mouse.y - (500 * radio_y)) / 0.6;

    tmp_x /= radio_x;
    tmp_y /= radio_y;
    return sfImage_getPixel(img, (int)tmp_x, (int)tmp_y);
}
