/*
** EPITECH PROJECT, 2022
** color.c
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

void getpixel(i_m_h *info_menu_home, sfVector2i v, sfVector2f scale)
{
    sfImage *img = info_menu_home->info_display.image_default;
    sfVector2u size = sfImage_getSize(img);
    v.x = (v.x - 180) / scale.x;
    v.y = (v.y - 130) / scale.y;
    if (v.x >= size.x)
        return;
    if (v.y >= size.y)
        return;
    info_menu_home->info_display.tmp_color = sfImage_getPixel(img,
        (v.x / info_menu_home->rad_x_w),
        (v.y / info_menu_home->rad_y_w));
}

void periph_tools_pipette(sfWindow *w, i_m_h *info_menu_home)
{
    if (info_menu_home->click_bouton_tools != 2)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i mouse = sfMouse_getPosition(w);
        int zone_01[4] = {185, 10000, 130, 10000};
        if (verif_zone(zone_01, w) == 0)
            return;
        getpixel(info_menu_home, mouse,
            sfSprite_getScale(info_menu_home->info_display.fond_default));
    }
}
