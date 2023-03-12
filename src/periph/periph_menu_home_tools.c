/*
** EPITECH PROJECT, 2022
** periph_menu_basic.c
** File description:
** Function : cherch_perif
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>

#include "../../include/struct_all.h"
#include "my.h"

void suite_press_tool(sfRenderWindow *w, i_m_h *info_menu_home, sfEvent act)
{
    int zone_05[4] = {10, 80, 560, 635};
    int zone_06[4] = {10, 80, 650, 720};
    int zone_07[4] = {10, 80, 740, 810};
    if (verif_zone(zone_05, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 4;
    if (verif_zone(zone_06, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 5;
    if (verif_zone(zone_07, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 6;
}

void press_tool(sfRenderWindow *w, i_m_h *info_menu_home, sfEvent act)
{
    if (info_menu_home->info_display.change_tools == 0)
        return display_error_zoom(w, info_menu_home);
    int zone_01[4] = {10, 80, 205, 275};
    int zone_02[4] = {10, 80, 295, 365};
    int zone_03[4] = {10, 80, 385, 450};
    int zone_04[4] = {10, 80, 470, 545};
    if (verif_zone(zone_01, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 0;
    if (verif_zone(zone_02, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 1;
    if (verif_zone(zone_03, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 2;
    if (verif_zone(zone_04, w) == 1)
        if (act.type == sfEvtMouseButtonPressed)
            info_menu_home->click_bouton_tools = 3;
    suite_press_tool(w, info_menu_home, act);
}

void verif_pass_mouse_tools(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfVector2f tmp_scal =
        sfSprite_getScale(info_menu_home->info_display.fond_default);
    one_tool(w, info_menu_home);
    two_tool(w, info_menu_home);
    three_tool(w, info_menu_home);
    four_tool(w, info_menu_home);
    five_tool(w, info_menu_home);
    six_tool(w, info_menu_home);
    sfColor color_pres = {14, 13, 17, 255};
    sfRectangleShape_setFillColor(
        info_menu_home->bouton_tools[info_menu_home->click_bouton_tools],
            color_pres);
}
