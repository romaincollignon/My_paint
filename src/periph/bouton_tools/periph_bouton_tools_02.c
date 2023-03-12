/*
** EPITECH PROJECT, 2022
** periph_bouton_tools_02.c
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

void six_tool(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {10, 80, 650, 720};
    sfEvent event;
    if (verif_zone(zone_01, w) == 1) {
        if (event.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 5;
        else
            sfRectangleShape_setFillColor(info_menu_home->bouton_tools[5],
                color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[5],
        color_default);
    }
}
