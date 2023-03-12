/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** Function : init_all
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

#include "../include/struct_all.h"
#include "my.h"

int init_struct(i_g *info_game)
{
    info_game->env = -1;
    info_game->display = -1;
    info_game->choose_paint = -1;
    return 0;
}

sfSprite* init_fond(char *image)
{
    sfTexture* texture = sfTexture_createFromFile(image, NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
