/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> sokoban
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

int verif_file(void)
{
    char *tab[19] = {"./res/fond/fond_home.png", "./res/fond/fond_start.jpg",
    "./res/fond_paint/black_1920x1080.jpg",
    "./res/fond_paint/white_1920x1080.jpg",
    "./res/icons/Blur.png", "./res/icons/Brush.png", "./res/icons/Cursor.png",
    "./res/icons/magnifier.png", "./res/icons/Move.png",
    "./res/icons/pipette.png", "./res/icons/Rubber.png", "./res/icons/star.png",
    "./res/icons_geo/carre.png", "./res/icons_geo/cercle.png",
    "./res/policy/Bostana.ttf", "./res/policy/CodeNext.ttf",
    "./res/policy/default.ttf", "./res/policy/Play_Pretend.otf",
    "./res/rgb_color.jpeg"};
    for (int n = 0; n < 19; n++) {
        int addre_file = open(tab[n], O_RDONLY);
        if (addre_file == -1) {
            write(2, "Error File !\n", 13);
            close(addre_file);
            return 84;
        }
        close(addre_file);
    } return 0;
}

int second_main(sfRenderWindow* window)
{
    i_g *info_game = malloc(sizeof(i_g));
    init_struct(info_game);
    while (info_game->env != 0) {
        if (info_game->env == -1) menu_loading(info_game, window);
        if (info_game->env == 1) menu_home(info_game, window);
    }
    sfRenderWindow_close(window);

    return 0;
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return 84;
    if (!env || !env[0])
        return 84;
    if (verif_file() == 84)
        return 84;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "PHOTOCHEAP", sfClose |
        sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 300);
    int result_main = second_main(window);
    return result_main;
}
