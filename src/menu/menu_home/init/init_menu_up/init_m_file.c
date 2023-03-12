/*
** EPITECH PROJECT, 2022
** init_m_file.c
** File description:
** Function : init_m_file
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

#include "../../../../../include/struct_all.h"
#include "my.h"

sfText* init_txt_menu(sfText *text, sfVector2f position, char *str,
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

void malloc_m_file(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.rect_file =
            malloc(sizeof(sfRectangleShape*) * 10);
    for (int n = 0; n < 10; n++)
        info_menu_home->info_menu.rect_file[n] =
            malloc(sizeof(sfRectangleShape*));

    info_menu_home->info_menu.text_m_file =
            malloc(sizeof(sfText*) * 10);
    for (int n = 0; n < 10; n++)
        info_menu_home->info_menu.text_m_file[n] =
            malloc(sizeof(sfText*));
    info_menu_home->info_menu.time_file = malloc(sizeof(sfClock*));
    info_menu_home->info_menu.time_file = sfClock_create();
    info_menu_home->info_menu.text_look_t = malloc(sizeof(sfText*));
}

void suite_init_m_file(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.text_m_file[1] =
        init_txt_menu(info_menu_home->info_menu.text_m_file[0],
            (sfVector2f){20, 95}, "SAVE", 24);
    info_menu_home->info_menu.text_m_file[2] =
        init_txt_menu(info_menu_home->info_menu.text_m_file[0],
            (sfVector2f){17, 135}, "OPEN", 24);
    info_menu_home->info_menu.text_look_t =
        init_txt_menu(info_menu_home->info_menu.text_look_t,
            (sfVector2f){15, 985},
                "Enter the path of the image in the terminal.", 24);
}

void init_m_file(i_m_h *info_menu_home)
{
    malloc_m_file(info_menu_home);
    info_menu_home->info_menu.rect_file[0] = init_bar(info_menu_home, 1,
        (sfVector2f){80, 120}, (sfVector2f){5, 55});
    info_menu_home->info_menu.rect_file[1] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 30}, (sfVector2f){10, 60});
    info_menu_home->info_menu.rect_file[2] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 35}, (sfVector2f){10, 95});
    info_menu_home->info_menu.rect_file[3] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 35}, (sfVector2f){10, 135});
    info_menu_home->info_menu.text_m_file[0] =
        init_txt_menu(info_menu_home->info_menu.text_m_file[0],
            (sfVector2f){20, 60}, "NEW", 24);
    suite_init_m_file(info_menu_home);
}

void init_menu(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.choose_menu = 0;
    init_m_file(info_menu_home);
    init_m_edition(info_menu_home);
    init_m_help(info_menu_home);
}
