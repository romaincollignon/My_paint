/*
** EPITECH PROJECT, 2022
** init_m_help.c
** File description:
** Function : init_m_help
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

void malloc_m_help(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.rect_help =
            malloc(sizeof(sfRectangleShape*) * 10);
    for (int n = 0; n < 10; n++)
        info_menu_home->info_menu.rect_help[n] =
            malloc(sizeof(sfRectangleShape*));

    info_menu_home->info_menu.text_m_help =
            malloc(sizeof(sfText*) * 10);
    for (int n = 0; n < 10; n++)
        info_menu_home->info_menu.text_m_help[n] =
            malloc(sizeof(sfText*));
    info_menu_home->info_menu.text_lo_t_h = malloc(sizeof(sfText*));
}

void init_m_help_rectang(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.rect_help[0] = init_bar(info_menu_home, 1,
        (sfVector2f){215, 240}, (sfVector2f){155, 55});
    info_menu_home->info_menu.rect_help[1] = init_bar(info_menu_home, 3,
        (sfVector2f){205, 30}, (sfVector2f){160, 60});
    info_menu_home->info_menu.rect_help[2] = init_bar(info_menu_home, 3,
        (sfVector2f){205, 35}, (sfVector2f){160, 95});
    info_menu_home->info_menu.rect_help[3] = init_bar(info_menu_home, 3,
        (sfVector2f){205, 35}, (sfVector2f){160, 135});
    info_menu_home->info_menu.rect_help[4] = init_bar(info_menu_home, 3,
        (sfVector2f){205, 35}, (sfVector2f){160, 175});
    info_menu_home->info_menu.rect_help[5] = init_bar(info_menu_home, 3,
        (sfVector2f){205, 35}, (sfVector2f){160, 215});
    info_menu_home->info_menu.rect_help[6] = init_bar(info_menu_home, 3,
        (sfVector2f){205, 35}, (sfVector2f){160, 255});
    return;
}

void init_m_help_text(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.text_m_help[0] =
        init_txt_menu(info_menu_home->info_menu.text_m_help[0],
            (sfVector2f){170, 60}, "SAVE/OPEN IMAGE", 24);
    info_menu_home->info_menu.text_m_help[1] =
        init_txt_menu(info_menu_home->info_menu.text_m_help[1],
            (sfVector2f){190, 98}, "PAINT/ERASER", 24);
    info_menu_home->info_menu.text_m_help[2] =
        init_txt_menu(info_menu_home->info_menu.text_m_help[2],
            (sfVector2f){203, 138}, "SET COLOR", 24);
    info_menu_home->info_menu.text_m_help[3] =
        init_txt_menu(info_menu_home->info_menu.text_m_help[3],
            (sfVector2f){225, 175}, "ZOOM", 24);
    info_menu_home->info_menu.text_m_help[4] =
        init_txt_menu(info_menu_home->info_menu.text_m_help[4],
            (sfVector2f){222, 215}, "CREDIT", 24);
    info_menu_home->info_menu.text_m_help[5] =
        init_txt_menu(info_menu_home->info_menu.text_m_help[5],
            (sfVector2f){235, 255}, "EXIT", 24);
}

void init_m_help(i_m_h *info_menu_home)
{
    malloc_m_help(info_menu_home);
    init_m_help_rectang(info_menu_home);
    init_m_help_text(info_menu_home);
    info_menu_home->info_menu.time_help = malloc(sizeof(sfClock*));
    info_menu_home->info_menu.time_help = sfClock_create();
    info_menu_home->info_menu.text_lo_t_h =
        init_txt_menu(info_menu_home->info_menu.text_lo_t_h,
            (sfVector2f){15, 985},
                "The information will be displayed in the terminal.", 24);
    return;
}
