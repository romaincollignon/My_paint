/*
** EPITECH PROJECT, 2022
** periph_bouton_tools_01.c
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

void one_tool(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {10, 80, 205, 275};
    sfEvent event;
    if (verif_zone(zone_01, w) == 1) {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[0],
            sfBlack);
        if (event.type == sfEvtMouseButtonPressed) {
            info_menu_home->click_bouton_tools = 0;
        } else {
            sfRectangleShape_setFillColor(info_menu_home->bouton_tools[0],
                color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[0],
        color_default);
    }
}

void two_tool(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {10, 80, 295, 365};
    sfEvent Act;
    if (verif_zone(zone_01, w) == 1) {
        if (Act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 1;
        else
            sfRectangleShape_setFillColor(info_menu_home->bouton_tools[1],
                color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[1],
        color_default);
    }
}

void three_tool(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {10, 80, 385, 450};
    sfEvent event;
    if (verif_zone(zone_01, w) == 1) {
        if (event.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 2;
        else
            sfRectangleShape_setFillColor(info_menu_home->bouton_tools[2],
                color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[2],
        color_default);
    }
}

void four_tool(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {10, 80, 470, 545};
    sfEvent event;
    if (verif_zone(zone_01, w) == 1) {
        if (event.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 3;
        else
            sfRectangleShape_setFillColor(info_menu_home->bouton_tools[3],
                color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[3],
        color_default);
    }
}

void five_tool(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    int zone_01[4] = {10, 80, 560, 635};
    sfEvent event;
    if (verif_zone(zone_01, w) == 1) {
        if (event.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 4;
        else
            sfRectangleShape_setFillColor(info_menu_home->bouton_tools[4],
                color_pass);
    } else {
        sfRectangleShape_setFillColor(info_menu_home->bouton_tools[4],
        color_default);
    }
}
