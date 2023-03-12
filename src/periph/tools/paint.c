/*
** EPITECH PROJECT, 2022
** paint.c
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

void update_image(sfWindow *w, i_m_h *info_menu_home, int pos_y, int pos_x)
{
    int zone_01[4] = {185, 10000, 130, 10000};
    if (verif_zone(zone_01, w) == 0)
        return;
    info_menu_home->info_display.last_y = pos_y;
    info_menu_home->info_display.last_x = pos_x;
    float scale = info_menu_home->info_display.scale;
    draw_circle_p(info_menu_home,
        pos_x,
        pos_y,
        info_menu_home->info_display.size_paint);
    sfTexture_updateFromImage(info_menu_home->info_display.tmp_textu,
        info_menu_home->info_display.image_default, 0, 0);
    sfSprite_setTexture(info_menu_home->info_display.fond_default,
        info_menu_home->info_display.tmp_textu, NULL);
}

void edit_size_paint(sfWindow *w, i_m_h *info_menu_home, int pos_y,
    int pos_x)
{
    int zone_01[4] = {110, 170, 210, 470};
    if (verif_zone(zone_01, w) == 0)
        return;
    sfVector2u size_w = sfWindow_getSize(w);
    float height = size_w.y;
    float radio_y = height / 1029;
    info_menu_home->info_display.size_paint = (pos_y - (207 * radio_y)) * 2;
    sfRectangleShape_setPosition(info_menu_home->info_display.menu_tools[6],
        (sfVector2f){120, (pos_y / radio_y)});
    sfText_setString(info_menu_home->info_display.txt[4],
        int_pass_char(info_menu_home->info_display.size_paint));
}

int periph_tools_paint(sfWindow *w, i_g *info_game, i_m_h *info_menu_home,
    sfEvent act)
{
    if (info_game->choose_paint != 3 ||
        info_menu_home->click_bouton_tools != 1) {
        info_menu_home->info_display.start_paint = 0;
        return 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        info_menu_home->info_display.start_paint = 1;
        sfVector2i mouse = sfMouse_getPosition(w);
        edit_size_paint(w, info_menu_home, mouse.y, mouse.x);
        update_image(w, info_menu_home, mouse.y, mouse.x);
        return 1;
    } else {
        info_menu_home->info_display.start_paint = 0;
        info_menu_home->info_display.last_y = -1;
        info_menu_home->info_display.last_x = -1;
        return 0;
    }
}
