/*
** EPITECH PROJECT, 2022
** init_home.c
** File description:
** Function : init_home
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

#include "../../../../include/struct_all.h"
#include "my.h"

static void init_malloc(i_m_h *info_menu_home)
{
    info_menu_home->font_txt_default = malloc(sizeof(sfFont*));
    info_menu_home->txt_file = malloc(sizeof(sfText*));
    info_menu_home->txt_edition = malloc(sizeof(sfText*));
    info_menu_home->txt_help = malloc(sizeof(sfText*));
    info_menu_home->txt_reset = malloc(sizeof(sfText*));
    info_menu_home->bar_up = malloc(sizeof(sfRectangleShape*));
    info_menu_home->bar_left = malloc(sizeof(sfRectangleShape*));
    info_menu_home->bouton = malloc(sizeof(sfRectangleShape*) * 6);
    for (int n = 0; n < 5; n++)
        info_menu_home->bouton[n] = malloc(sizeof(sfRectangleShape*));
    info_menu_home->bouton_tools = malloc(sizeof(sfRectangleShape*) * 10);
    info_menu_home->icons_tools = malloc(sizeof(sfSprite*) * 10);
    for (int n = 0; n < 10; n++) {
        info_menu_home->bouton_tools[n] = malloc(sizeof(sfRectangleShape*));
        info_menu_home->icons_tools[n] = malloc(sizeof(sfSprite*));
    } info_menu_home->click_bouton_tools = 0;
    info_menu_home->image_color = malloc(sizeof(sfSprite*));
    info_menu_home->info_display.image_default =
        malloc(sizeof(sfImage*));
}

sfRectangleShape* init_bar(i_m_h *info_menu_home, int pos,
    sfVector2f size, sfVector2f position)
{
    if (pos == 1) {
        sfColor color_bar = {24, 23, 27, 255};
        sfRectangleShape* rectangle = sfRectangleShape_create();
        sfRectangleShape_setPosition(rectangle, position);
        sfRectangleShape_setFillColor(rectangle, color_bar);
        sfRectangleShape_setSize(rectangle, size);
        return rectangle;
    } else {
        sfColor color_boutton = {34, 33, 37, 255};
        sfRectangleShape* rectangle = sfRectangleShape_create();
        sfRectangleShape_setPosition(rectangle, position);
        sfRectangleShape_setFillColor(rectangle, color_boutton);
        sfRectangleShape_setSize(rectangle, size);
        return rectangle;
    }
}

sfText* init_txt(i_m_h *info_menu_home, char *txt, int x, int y)
{
    sfText *text = sfText_create();
    sfVector2f pos_txt = {x, y};
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, pos_txt);
    sfText_setFont(text, info_menu_home->font_txt_default);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfWhite);
    return text;
}

void init_button(i_m_h *info_menu_home)
{
    info_menu_home->bouton[0] = init_bar(info_menu_home, 2,
        (sfVector2f){70, 35}, (sfVector2f){10, 10});
    info_menu_home->bouton[1] = init_bar(info_menu_home, 2,
        (sfVector2f){125, 35}, (sfVector2f){90, 10});
    info_menu_home->bouton[2] = init_bar(info_menu_home, 2,
        (sfVector2f){84, 35}, (sfVector2f){225, 10});
    info_menu_home->bouton[3] = init_bar(info_menu_home, 2,
        (sfVector2f){95, 35}, (sfVector2f){1810, 10});
    info_menu_home->bouton_tools[6] = init_bar(info_menu_home, 2,
        (sfVector2f){150, 400}, (sfVector2f){400, 400});
    info_menu_home->bouton_tools[7] = init_bar(info_menu_home, 1,
        (sfVector2f){380, 260}, (sfVector2f){140, 490});
}

void init_struct_menu_home(i_m_h *info_menu_home)
{
    info_menu_home->info_display.coldown = malloc(sizeof(sfClock*));
    info_menu_home->info_display.coldown = sfClock_create();
    init_malloc(info_menu_home);
    info_menu_home->click_bouton_menu = -1;
    info_menu_home->font_txt_default =
        sfFont_createFromFile("./res/policy/default.ttf");
    info_menu_home->txt_file = init_txt(info_menu_home, "FILE", 20, 7);
    info_menu_home->txt_edition = init_txt(info_menu_home, "EDITION", 100, 7);
    info_menu_home->txt_help = init_txt(info_menu_home, "HELP", 235, 7);
    info_menu_home->txt_reset = init_txt(info_menu_home, "LEAVE", 1820, 7);
    init_button(info_menu_home);
    info_menu_home->bar_up = init_bar(info_menu_home, 1,
        (sfVector2f){2000, 55}, (sfVector2f){0, 0});
    info_menu_home->bar_left = init_bar(info_menu_home, 1,
        (sfVector2f){100, 560}, (sfVector2f){0, 180});
    suite_init_struct_menu_home(info_menu_home);
    init_display(info_menu_home);
    init_menu_tools(info_menu_home);
    init_menu(info_menu_home);
    info_menu_home->rad_x_w = 1.0; info_menu_home->rad_y_w = 1.0;
}
