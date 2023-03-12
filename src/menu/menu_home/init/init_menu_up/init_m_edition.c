/*
** EPITECH PROJECT, 2022
** init_m_edition.c
** File description:
** Function : init_m_edition
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

void malloc_m_edition(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.rect_edition =
            malloc(sizeof(sfRectangleShape*) * 10);
    for (int n = 0; n < 10; n++)
        info_menu_home->info_menu.rect_edition[n] =
            malloc(sizeof(sfRectangleShape*));

    info_menu_home->info_menu.text_m_edition =
            malloc(sizeof(sfText*) * 10);
    for (int n = 0; n < 10; n++)
        info_menu_home->info_menu.text_m_edition[n] =
            malloc(sizeof(sfText*));
}

void init_rect_edition(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.rect_edition[0] = init_bar(info_menu_home, 1,
        (sfVector2f){100, 200}, (sfVector2f){105, 55});
    info_menu_home->info_menu.rect_edition[1] = init_bar(info_menu_home, 3,
        (sfVector2f){90, 30}, (sfVector2f){110, 60});
    info_menu_home->info_menu.rect_edition[2] = init_bar(info_menu_home, 3,
        (sfVector2f){90, 35}, (sfVector2f){110, 95});
    info_menu_home->info_menu.rect_edition[3] = init_bar(info_menu_home, 3,
        (sfVector2f){90, 35}, (sfVector2f){110, 135});
    info_menu_home->info_menu.rect_edition[4] = init_bar(info_menu_home, 3,
        (sfVector2f){90, 35}, (sfVector2f){110, 175});
    info_menu_home->info_menu.rect_edition[5] = init_bar(info_menu_home, 3,
        (sfVector2f){90, 35}, (sfVector2f){110, 215});
}

void init_text_edition(i_m_h *info_menu_home)
{
    info_menu_home->info_menu.text_m_edition[0] =
        init_txt_menu(info_menu_home->info_menu.text_m_edition[0],
            (sfVector2f){125, 60}, "PAINT", 24);
    info_menu_home->info_menu.text_m_edition[1] =
        init_txt_menu(info_menu_home->info_menu.text_m_edition[1],
            (sfVector2f){115, 95}, "PIPETTE", 24);
    info_menu_home->info_menu.text_m_edition[2] =
        init_txt_menu(info_menu_home->info_menu.text_m_edition[2],
            (sfVector2f){117, 135}, "ERASER", 24);
    info_menu_home->info_menu.text_m_edition[3] =
        init_txt_menu(info_menu_home->info_menu.text_m_edition[3],
            (sfVector2f){117, 175}, "COLOR", 24);
    info_menu_home->info_menu.text_m_edition[4] =
        init_txt_menu(info_menu_home->info_menu.text_m_edition[4],
            (sfVector2f){120, 215}, "ZOOM", 24);
    return;
}

void init_m_edition(i_m_h *info_menu_home)
{
    malloc_m_edition(info_menu_home);
    init_rect_edition(info_menu_home);
    init_text_edition(info_menu_home);
    info_menu_home->info_menu.time_edition = malloc(sizeof(sfClock*));
    info_menu_home->info_menu.time_edition = sfClock_create();
    return;
}
