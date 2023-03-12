/*
** EPITECH PROJECT, 2022
** pipette.c
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

void periph_tools_color(sfWindow *w, i_m_h *info_menu_home)
{
    calc_r_windo(w, info_menu_home);
    if (info_menu_home->click_bouton_tools != 4)
        return;
    int zone_01[4] = {153, 510, 503, 730};
    if (verif_zone(zone_01, w) == 0)
        return;
    sfVector2i mouse = sfMouse_getPosition(w);
    sfColor color_tmp = my_getpixel(w, info_menu_home->info_display.image_color,
        mouse);
    sfRectangleShape_setPosition(info_menu_home->info_display.menu_tools[0],
        (sfVector2f){(mouse.x + 20) / (info_menu_home->rad_x_w),
        (mouse.y + 20) / (info_menu_home->rad_y_w)});
    sfRectangleShape_setFillColor(info_menu_home->info_display.menu_tools[0],
        color_tmp);
    sfRenderWindow_drawRectangleShape(w,
        info_menu_home->info_display.menu_tools[0], NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        info_menu_home->info_display.tmp_color = color_tmp;
    }
}
