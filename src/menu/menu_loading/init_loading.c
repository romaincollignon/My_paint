/*
** EPITECH PROJECT, 2022
** init_menu_basic.c
** File description:
** Function : init_menu_basic
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

static void init_malloc(i_m_l *info_menu_loading)
{
    info_menu_loading->time = malloc(sizeof(sfClock*));
    info_menu_loading->Font_txt_01 = malloc(sizeof(sfFont*));
    info_menu_loading->txt_load = malloc(sizeof(sfText*));
    info_menu_loading->txt_wait = malloc(sizeof(sfText*));
    info_menu_loading->txt_leave = malloc(sizeof(sfText*));
    info_menu_loading->contour = malloc(sizeof(sfRectangleShape*));
    info_menu_loading->bar_load = malloc(sizeof(sfRectangleShape*));
}

static sfText* init_txt_load(i_m_l *info_menu_loading, char *txt,
    int x, int y)
{
    sfVector2f pos_txt = {x, y};
    sfText *text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, pos_txt);
    sfText_setFont(text, info_menu_loading->Font_txt_01);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfWhite);
    return text;
}

static sfText* init_tips(i_m_l *info_menu_loading, char *txt,
    int x, int y)
{
    sfVector2f pos_txt = {x, y};
    sfText *text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, pos_txt);
    sfText_setFont(text, info_menu_loading->Font_txt_01);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfWhite);
    return text;
}

void init_load(i_m_l *info_menu_loading, int pos)
{
    if (pos == 1){
        sfVector2f size = {710, 30};
        sfRectangleShape* rectangle = sfRectangleShape_create();
        sfRectangleShape_setPosition(rectangle, (sfVector2f){225, 500});
        sfRectangleShape_setFillColor(rectangle, sfTransparent);
        sfRectangleShape_setOutlineThickness(rectangle, (float)3);
        sfRectangleShape_setOutlineColor(rectangle, sfWhite);
        sfRectangleShape_setSize(rectangle, size);
        info_menu_loading->contour = rectangle;
    } if (pos == 2) {
        sfVector2f size = {1, 20};
        sfRectangleShape* rectangle = sfRectangleShape_create();
        sfRectangleShape_setPosition(rectangle, (sfVector2f){232, 505});
        sfRectangleShape_setFillColor(rectangle, sfWhite);
        sfRectangleShape_setOutlineColor(rectangle, sfWhite);
        sfRectangleShape_setSize(rectangle, size);
        info_menu_loading->bar_load = rectangle;
    }
}

void init_struct_menu_load(i_m_l *info_menu_loading)
{
    init_malloc(info_menu_loading);
    info_menu_loading->Font_txt_01 =
        sfFont_createFromFile("./res/policy/Play_Pretend.otf");
    info_menu_loading->txt_load = init_txt_load(info_menu_loading,
        "Loading...", 430, 450);
    info_menu_loading->txt_wait =
        init_txt_load(info_menu_loading, "Please Wait.", 430, 530);
    info_menu_loading->txt_leave =
        init_tips(info_menu_loading, "Press (ECHAP) for leave.", 1450, 975);
    info_menu_loading->time = sfClock_create();
    init_load(info_menu_loading, 1);
    init_load(info_menu_loading, 2);
}
