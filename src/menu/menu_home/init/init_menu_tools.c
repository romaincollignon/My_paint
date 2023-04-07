/*
** EPITECH PROJECT, 2022
** init_menu_tools.c
** File description:
** Function : init_menu_tools
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

void suite_init_rubber_choose_form(i_m_h *info_menu_home)
{
    sfImage *img_1 = sfImage_createFromFile("./res/icons_geo/carre.png");
    sfTexture *textu_1 = sfTexture_createFromImage(img_1, NULL);
    sfSprite* tmp_sprite_1 = sfSprite_create();
    sfSprite_setTexture(tmp_sprite_1, textu_1, sfFalse);
    sfSprite_setPosition(tmp_sprite_1, (sfVector2f){120, 705});
    sfSprite_setScale(tmp_sprite_1, (sfVector2f){0.08, 0.08});
    info_menu_home->info_display.icon_rubber[0] = tmp_sprite_1;
    sfImage *img_2 = sfImage_createFromFile("./res/icons_geo/cercle.png");
    sfTexture *textu_2 = sfTexture_createFromImage(img_2, NULL);
    sfSprite* tmp_sprite_2 = sfSprite_create();
    sfSprite_setTexture(tmp_sprite_2, textu_2, sfFalse);
    sfSprite_setPosition(tmp_sprite_2, (sfVector2f){120, 705});
    sfSprite_setScale(tmp_sprite_2, (sfVector2f){0.08, 0.08});
    info_menu_home->info_display.icon_rubber[1] = tmp_sprite_2;
}

void init_rubber_choose_form(i_m_h *info_menu_home)
{
    info_menu_home->info_display.form_rubber =
        malloc(sizeof(sfRectangleShape*) * 10);
    for (int n = 0; n < 4; n++)
        info_menu_home->info_display.form_rubber[n] =
            malloc(sizeof(sfRectangleShape*));
    info_menu_home->info_display.form_rubber[0] =
    init_bar(info_menu_home, 1, (sfVector2f){60, 60}, (sfVector2f){110, 695});
    info_menu_home->info_display.form_rubber[1] =
    init_bar(info_menu_home, 2, (sfVector2f){50, 50}, (sfVector2f){115, 700});
    info_menu_home->info_display.icon_rubber =
        malloc(sizeof(sfSprite*) * 10);
    for (int n = 0; n < 4; n++)
        info_menu_home->info_display.icon_rubber[n] =
            malloc(sizeof(sfSprite*));
    suite_init_rubber_choose_form(info_menu_home);
}

void init_menu_rubber(i_m_h *info_menu_home)
{
    init_rubber_choose_form(info_menu_home);
    info_menu_home->info_display.menu_tools[1] = init_bar(info_menu_home, 1,
        (sfVector2f){60, 330}, (sfVector2f){110, 350});
    info_menu_home->info_display.menu_tools[2] = init_bar(info_menu_home, 2,
        (sfVector2f){10, 260}, (sfVector2f){135, 370});
    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle, (sfVector2f){120, 400});
    sfRectangleShape_setFillColor(rectangle, sfWhite);
    sfRectangleShape_setSize(rectangle, (sfVector2f){40, 5});
    info_menu_home->info_display.menu_tools[3] = rectangle;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./res/policy/default.ttf");
    info_menu_home->info_display.size_rubber = 65;
    sfText_setString(text,
        int_pass_char(info_menu_home->info_display.size_rubber));
    sfText_setPosition(text, (sfVector2f){125, 640});
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    info_menu_home->info_display.txt[3] = text;
}

void init_menu_magnifier(i_m_h *info_menu_home)
{
    info_menu_home->info_display.menu_tools[7] = init_bar(info_menu_home, 1,
        (sfVector2f){60, 120}, (sfVector2f){110, 635});
    info_menu_home->info_display.menu_tools[8] = init_bar(info_menu_home, 2,
        (sfVector2f){50, 50}, (sfVector2f){115, 640});
    info_menu_home->info_display.menu_tools[9] = init_bar(info_menu_home, 2,
        (sfVector2f){50, 50}, (sfVector2f){115, 700});
        sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./res/policy/default.ttf");
    sfText_setString(text,
        int_pass_char(info_menu_home->info_display.size_paint));
    sfText_setPosition(text, (sfVector2f){125, 480});
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    info_menu_home->info_display.txt[5] =
        init_txt(info_menu_home, "+", 120, 612);
    sfText_setCharacterSize(info_menu_home->info_display.txt[5], 70);
    info_menu_home->info_display.txt[6] =
        init_txt(info_menu_home, "-", 127, 659);
    sfText_setCharacterSize(info_menu_home->info_display.txt[6], 90);
}

void init_menu_tools(i_m_h *info_menu_home)
{
    info_menu_home->info_display.choose_rubber = 0;
    init_menu_rubber(info_menu_home);
    init_menu_magnifier(info_menu_home);
    info_menu_home->info_display.change_tools = 1;
    info_menu_home->info_display.txt[7] =
        init_txt(info_menu_home, "/!\\ Zoom out to the maximum /!\\", 20, 980);
    sfText_setColor(info_menu_home->info_display.txt[7], sfRed);
    return;
}
