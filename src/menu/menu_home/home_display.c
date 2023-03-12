/*
** EPITECH PROJECT, 2022
** menu_home_display.c
** File description:
** Function : menu_home_display
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

void display_display(sfRenderWindow *window, i_g *info_game,
    i_m_h *info_menu_home)
{
    if (info_game->choose_paint == 3) {
        sfRenderWindow_drawSprite(window,
            info_menu_home->info_display.fond_default, NULL);
    } else {
        for (int n = 0; n < 6; n++)
            sfRenderWindow_drawRectangleShape(window,
                info_menu_home->info_display.bouton[n], NULL);
        for (int n = 0; n < 3; n++)
            sfRenderWindow_drawText(window,
                info_menu_home->info_display.txt[n], NULL);
        if (info_game->choose_paint == 4)
            sfRenderWindow_drawText(window,
                info_menu_home->info_display.txt[9], NULL);
        else
            sfRenderWindow_drawText(window,
                info_menu_home->info_display.txt[8], NULL);
    }
}

void suite_all_display(sfRenderWindow *w, i_m_h *info_menu_home)
{
    if (info_menu_home->click_bouton_tools == 4) {
        sfRenderWindow_drawRectangleShape(w,
            info_menu_home->bouton_tools[7], NULL);
        sfRenderWindow_drawSprite(w, info_menu_home->image_color, NULL);
    } if (info_menu_home->click_bouton_tools == 5) {
        for (int n = 7; n < 10; n++)
            sfRenderWindow_drawRectangleShape(w,
                info_menu_home->info_display.menu_tools[n], NULL);
        sfRenderWindow_drawText(w, info_menu_home->info_display.txt[5], NULL);
        sfRenderWindow_drawText(w, info_menu_home->info_display.txt[6], NULL);
    }
}

void all_display(sfRenderWindow *w, i_m_h *info_menu_home)
{
    if (info_menu_home->click_bouton_tools == 1) {
        for (int n = 4; n < 7; n++)
            sfRenderWindow_drawRectangleShape(w,
                info_menu_home->info_display.menu_tools[n], NULL);
        sfRenderWindow_drawText(w, info_menu_home->info_display.txt[4], NULL);
    } if (info_menu_home->click_bouton_tools == 3) {
        for (int n = 0; n < 2; n++)
            sfRenderWindow_drawRectangleShape(w,
                info_menu_home->info_display.form_rubber[n], NULL);
        sfRenderWindow_drawSprite(w, info_menu_home->info_display.icon_rubber[
            info_menu_home->info_display.choose_rubber], NULL);
        for (int n = 1; n < 4; n++)
            sfRenderWindow_drawRectangleShape(w,
                info_menu_home->info_display.menu_tools[n], NULL);
        sfRenderWindow_drawText(w, info_menu_home->info_display.txt[3], NULL);
    }
    suite_all_display(w, info_menu_home);
}

void suite_display_home(sfRenderWindow *w, i_m_h *info_menu_home)
{
    sfRenderWindow_drawRectangleShape(w,
        info_menu_home->bouton_tools[9], NULL);
    sfRectangleShape_setFillColor(info_menu_home->bouton_tools[8],
        info_menu_home->info_display.tmp_color);
    sfRenderWindow_drawRectangleShape(w,
        info_menu_home->bouton_tools[8], NULL);
}

void menu_home_display(sfRenderWindow *window, i_g *info_game,
    i_m_h *info_menu_home)
{
    display_display(window, info_game, info_menu_home);
    sfRenderWindow_drawRectangleShape(window, info_menu_home->bar_up, NULL);
    sfRenderWindow_drawRectangleShape(window, info_menu_home->bar_left, NULL);
    for (int n = 0; n < 4; n++)
        sfRenderWindow_drawRectangleShape(window, info_menu_home->bouton[n],
            NULL);
    for (int n = 0; n < 6; n++) {
        sfRenderWindow_drawRectangleShape(window,
            info_menu_home->bouton_tools[n], NULL);
        sfRenderWindow_drawSprite(window, info_menu_home->icons_tools[n], NULL);
    } sfRenderWindow_drawText(window, info_menu_home->txt_file, NULL);
    sfRenderWindow_drawText(window, info_menu_home->txt_edition, NULL);
    sfRenderWindow_drawText(window, info_menu_home->txt_help, NULL);
    sfRenderWindow_drawText(window, info_menu_home->txt_reset, NULL);
    suite_display_home(window, info_menu_home);
    all_display(window, info_menu_home);
    menu_up_display(window, info_menu_home);
}
