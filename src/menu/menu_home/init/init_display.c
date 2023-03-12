/*
** EPITECH PROJECT, 2022
** init_display.c
** File description:
** Function : init_display
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

void init_malloc_display(i_m_h *info_menu_home)
{
    info_menu_home->info_display.bouton =
        malloc(sizeof(sfRectangleShape*) * 10);
    info_menu_home->info_display.txt =
        malloc(sizeof(sfText*) * 17);
    for (int n = 0; n < 15; n++)
        info_menu_home->info_display.txt[n] =
            malloc(sizeof(sfText*));
    for (int n = 0; n < 10; n++)
        info_menu_home->info_display.bouton[n] =
            malloc(sizeof(sfRectangleShape*));
    info_menu_home->info_display.tmp_color = sfBlue;
}

static sfText* init_txt_title(sfText *text, sfVector2f position, char *str,
    int size)
{
    text = sfText_create();
    sfFont *font = sfFont_createFromFile("./res/policy/default.ttf");
    sfText_setString(text, str);
    sfText_setPosition(text, position);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    return text;
}

void load_display(i_m_h *info_menu_home)
{
    info_menu_home->info_display.bouton[0] = init_bar(info_menu_home, 1,
        (sfVector2f){800, 670}, (sfVector2f){570, 230});
    info_menu_home->info_display.bouton[1] = init_bar(info_menu_home, 2,
        (sfVector2f){350, 440}, (sfVector2f){600, 330});
    info_menu_home->info_display.bouton[2] = init_bar(info_menu_home, 2,
        (sfVector2f){350, 440}, (sfVector2f){990, 330});
    info_menu_home->info_display.bouton[5] = init_bar(info_menu_home, 2,
        (sfVector2f){740, 90}, (sfVector2f){600, 780});
    info_menu_home->info_display.txt[0] = init_txt_title
        (info_menu_home->info_display.txt[0], (sfVector2f){700, 250},
            "Choose Your Background", 50);
    info_menu_home->info_display.txt[1] = init_txt_title
        (info_menu_home->info_display.txt[1], (sfVector2f){630, 700},
            "1920 x 1080p White", 35);
    info_menu_home->info_display.txt[2] = init_txt_title
        (info_menu_home->info_display.txt[2], (sfVector2f){1025, 700},
            "1920 x 1080p Black", 35);
}

void init_text_menu(i_m_h *info_menu_home)
{
    sfText *text_1 = sfText_create();
    sfFont *font = sfFont_createFromFile("./res/policy/default.ttf");
    sfText_setString(text_1, "Select an image file");
    sfText_setPosition(text_1, (sfVector2f){800, 800});
    sfText_setFont(text_1, font);
    sfText_setCharacterSize(text_1, 40);
    sfText_setColor(text_1, sfWhite);
    info_menu_home->info_display.txt[8] = text_1;

    sfText *text = sfText_create();
    sfFont *font_2 = sfFont_createFromFile("./res/policy/default.ttf");
    sfText_setString(text, "Enter the path of the image in the terminal");
    sfText_setPosition(text, (sfVector2f){618, 800});
    sfText_setFont(text, font_2);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfWhite);
    info_menu_home->info_display.txt[9] = text;
}

void init_display(i_m_h *info_menu_home)
{
    init_malloc_display(info_menu_home);
    load_display(info_menu_home);
    init_text_menu(info_menu_home);
    sfRectangleShape* rectangle_01 = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle_01, (sfVector2f){620, 350});
    sfRectangleShape_setFillColor(rectangle_01, sfWhite);
    sfRectangleShape_setSize(rectangle_01, (sfVector2f){310, 300});
    info_menu_home->info_display.bouton[3] = rectangle_01;
    sfRectangleShape* rectangle_02 = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle_02, (sfVector2f){1010, 350});
    sfRectangleShape_setFillColor(rectangle_02, sfBlack);
    sfRectangleShape_setSize(rectangle_02, (sfVector2f){310, 300});
    info_menu_home->info_display.bouton[4] = rectangle_02;
}
