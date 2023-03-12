/*
** EPITECH PROJECT, 2022
** load_file_img.c
** File description:
** Function : load_file_img
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
#include "../../../include/my.h"

static char *get_cmd(i_g *info_game)
{
    size_t line = 0;
    char *buffer = NULL;
    if (getline(&buffer, &line, stdin) == -1) {
        info_game->env = 0;
    }
    return buffer;
}

static int verif_leave(i_g *info_game, char *file)
{
    if (my_strlen(file) != 6)
        return 0;
    if (my_strlen(file) == 6 && file[0] == '-' && file[1] == '-' &&
    file[2] == 'e' && file[3] == 'x' && file[4] == 'i' && file[5] == 't'
    && file[6] == '\0'){
        info_game->env = 0;
        mini_printf("\n%s%s%s  👋 Goodbye 👋\n\n", CDEF, CBLD, CGRN);
        return 1;
    }
    return 0;
}

static int verif_error(i_g *info_game, i_m_h *info_menu_home, char *file)
{
    file[(my_strlen(file) - 1)] = '\0';
    if (verif_leave(info_game, file) == 1)
        return 1;
    mini_printf("%s%s", CBLD, CRED);
    info_menu_home->info_display.image_default = sfImage_createFromFile(file);
    if (info_menu_home->info_display.image_default != NULL) {
        mini_printf("\n%s✅ %sSuccessful loading%s ✅\n\n\n\n\n\n\n\n\n\n",
            CDEF, CGRN, CDEF);
        info_game->custom_paint = 1;
        info_game->choose_paint = 1;
        return 1;
    } else {
        mini_printf(CCYN CBLD);
        mini_printf("\n\nPlease write the path of your image:\n  ➡ ");
        mini_printf(CDEF CBLU);
    }
    return 0;
}

void load_file_img(i_g *info_game, i_m_h *info_menu_home)
{
    mini_printf(CDEF CBLK CBLD);
    mini_printf("TIPS ➡ %s%s(write \"--exit\" or 'control + d' for exit)\n",
        CDEF, CBLK);
    mini_printf(CDEF CCYN CBLD);
    mini_printf("Please write the path of your image:\n  ➡ ");
    mini_printf(CDEF CBLU);
    while (1) {
        char *tmp_file = get_cmd(info_game);
        if (info_game->env == 0)
            break;
        if (verif_error(info_game, info_menu_home, tmp_file) == 1)
            break;
    }
    mini_printf(CDEF);
}
