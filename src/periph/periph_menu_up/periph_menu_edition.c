/*
** EPITECH PROJECT, 2022
** periph_menu_edition.c
** File description:
** Function : periph_menu_edition
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

void open_menu_edition(i_m_h *info_menu_home)
{
    if ((sfClock_getElapsedTime
        (info_menu_home->info_menu.time_edition).microseconds > 100000)) {

        if (info_menu_home->info_menu.choose_menu == 2)
            info_menu_home->info_menu.choose_menu = 0;
        else
            info_menu_home->info_menu.choose_menu = 2;
        sfClock_restart(info_menu_home->info_menu.time_edition);
    }
}

int periph_menu_edition(sfRenderWindow* w, i_m_h *info_menu_home, sfEvent act)
{
    int zone_edition[4] = {90, 220, 15, 50}; sfColor col_de = {34, 33, 37, 255};
    sfColor color_pas = {54, 53, 57, 255}; sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_edition, w) == 0 &&
        info_menu_home->info_menu.choose_menu != 2) return 0;
    if (verif_zone(zone_edition, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            open_menu_edition(info_menu_home);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            (sfClock_getElapsedTime
            (info_menu_home->info_menu.time_edition).microseconds < 100000)) {
            sfRectangleShape_setFillColor(info_menu_home->bouton[1], color_cli);
            sfClock_restart(info_menu_home->info_menu.time_edition); return 1;
        } else
            sfRectangleShape_setFillColor(info_menu_home->bouton[1], color_pas);
    } else {
        if (info_menu_home->info_menu.choose_menu != 2)
            sfRectangleShape_setFillColor(info_menu_home->bouton[1],
                col_de);
    } return 0;
}
