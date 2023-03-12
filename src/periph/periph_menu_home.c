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

void periph_pipette_color(sfRenderWindow* w, i_m_h *info_menu_home)
{
    periph_tools_pipette(w, info_menu_home);
    periph_tools_color(w, info_menu_home);
}

int perif_menu_home(sfRenderWindow* w, i_g *info_game, i_m_h *info_menu_home)
{
    calc_r_windo(w, info_menu_home); sfEvent ac;
    if (periph_menu_up(w, info_game, info_menu_home, ac) == 1) return 0;
    if (periph_tools_paint(w, info_game, info_menu_home, ac) == 1) return 0;
    if (periph_tools_rubber(w, info_game, info_menu_home, ac) == 1) return 0;
    periph_pipette_color(w, info_menu_home);
    if (periph_tools_magnifier(w, info_game, info_menu_home, ac) == 1) return 0;
    if (info_game->choose_paint == -1) {
        periph_choose_paint(w, info_game, info_menu_home, ac);
    } int zone_01[4] = {180, 1600, 130, 930};
    while (sfRenderWindow_pollEvent(w, &ac)) {
        if (info_game->choose_paint == 3)
            verif_pass_mouse_tools(w, info_menu_home);
        if (ac.type == sfEvtClosed) {
            info_game->env = 0; return 0;
        } if (ac.type == sfEvtKeyPressed && ac.key.code == sfKeyEscape) {
            info_game->env = 0; return 0;
        }
        press_tool(w, info_menu_home, ac);
    } return 0;
}
