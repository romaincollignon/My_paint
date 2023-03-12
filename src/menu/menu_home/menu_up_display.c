/*
** EPITECH PROJECT, 2022
** display_menu_up.c
** File description:
** Function : display_menu_up
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

#include "../../../include/struct_all.h"
#include "my.h"

void menu_up_display_help(sfRenderWindow *window, i_m_h *info_menu_home)
{
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pres = {14, 13, 17, 255};
    if (info_menu_home->info_menu.choose_menu == 3) {
        if (info_menu_home->info_menu.choose_menu == 3) {
            sfRectangleShape_setFillColor(info_menu_home->bouton[2],
                color_pres);
        }
        for (int n = 0; n < 7; n++)
            sfRenderWindow_drawRectangleShape(window,
                info_menu_home->info_menu.rect_help[n], NULL);
        for (int n = 0; n < 6; n++)
            sfRenderWindow_drawText(window,
                info_menu_home->info_menu.text_m_help[n], NULL);
    }
}

void menu_up_display_file(sfRenderWindow *window, i_m_h *info_menu_home)
{

    int zone_file_new[4] = {15, 83, 65, 95};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pres = {14, 13, 17, 255};
    if (info_menu_home->info_menu.choose_menu == 1) {
        if (info_menu_home->info_menu.choose_menu == 1) {
            sfRectangleShape_setFillColor(info_menu_home->bouton[0],
                color_pres);
        }
        for (int n = 0; n < 4; n++)
            sfRenderWindow_drawRectangleShape(window,
                info_menu_home->info_menu.rect_file[n], NULL);
        for (int n = 0; n < 3; n++)
            sfRenderWindow_drawText(window,
                info_menu_home->info_menu.text_m_file[n], NULL);
    }
}

void menu_up_display_edition(sfRenderWindow *window, i_m_h *info_menu_home)
{

    int zone_file_new[4] = {15, 83, 65, 95};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pres = {14, 13, 17, 255};
    if (info_menu_home->info_menu.choose_menu == 2) {
        if (info_menu_home->info_menu.choose_menu == 2) {
            sfRectangleShape_setFillColor(info_menu_home->bouton[1],
                color_pres);
        }
        for (int n = 0; n < 6; n++)
            sfRenderWindow_drawRectangleShape(window,
                info_menu_home->info_menu.rect_edition[n], NULL);
        for (int n = 0; n < 5; n++)
            sfRenderWindow_drawText(window,
                info_menu_home->info_menu.text_m_edition[n], NULL);
    }
}

void menu_up_display(sfRenderWindow *window, i_m_h *info_menu_home)
{
    menu_up_display_file(window, info_menu_home);
    menu_up_display_edition(window, info_menu_home);
    menu_up_display_help(window, info_menu_home);
    return;
}
