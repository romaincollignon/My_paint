/*
** EPITECH PROJECT, 2022
** save_file_img.c
** File description:
** Function : save_file_img
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

static char *get_cmd_save(i_g *info_game)
{
    size_t line = 0;
    char *buffer = NULL;
    if (getline(&buffer, &line, stdin) == -1) {
        info_game->env = 0;
    }
    return buffer;
}

static int verif_leave_save(i_g *info_game, char *file)
{
    if (my_strlen(file) == 6 && file[0] == '-' && file[1] == '-' &&
    file[2] == 'e' && file[3] == 'x' && file[4] == 'i' && file[5] == 't'
    && file[6] == '\0'){
        info_game->env = 0;
        mini_printf("\n%s%s%s  👋 Goodbye 👋\n\n", CDEF, CBLD, CGRN);
        return 1;
    }
    if (my_strlen(file) == 7 && file[0] == '-' && file[1] == '-' &&
    file[2] == 'l' && file[3] == 'e' && file[4] == 'a' && file[5] == 'v'
    && file[6] == 'e' && file[7] == '\0'){
        mini_printf("\n%s%s%s -- LEAVE --\n\n", CDEF, CBLD, CGRN);
        return 1;
    }
    return 0;
}

static int verif_name_file(char *str)
{
    int size_str = my_strlen(str);
    int error = 0;
    for (int n = 0; n < size_str; n++) {
        if ((str[n] < 'a' || str[n] > 'z') && (str[n] < 'A' || str[n] > 'Z')
            && str[n] != '-' && str[n] != '_')
            error = 1;
        if (error == 1)
            break;
    }
    if (my_strlen(str) == 0)
        error = 1;
    if (error == 1) {
        mini_printf("%s%s%s Error: ", CDEF, CBLD, CRED);
        mini_printf("%s%sOnly alphabetic characters and the characters '-', \
'_' and of a size of at least one character\n", CDEF, CRED);
        return 0;
    }
    return 1;
}

static int verif_error_save(i_g *info_game, i_m_h *info_menu_home, char *file)
{
    file[(my_strlen(file) - 1)] = '\0';
    if (verif_leave_save(info_game, file) == 1)
        return 1;
    if (verif_name_file(file) == 0)
        return 0;
    file = extension_file(info_game, file);
    mini_printf("%s%s", CBLD, CRED);
    if (sfImage_saveToFile(info_menu_home->info_display.image_default, file) ==
    sfTrue) {
        mini_printf("\n%s✅ %sSuccessful saving%s ✅\n\n\n\n\n\n\n\n\n\n",
            CDEF, CGRN, CDEF);
        info_game->custom_paint = 1;
        info_game->choose_paint = 1;
        return 1;
    }
    return 0;
}

void save_file_img(i_g *info_game, i_m_h *info_menu_home)
{
    mini_printf(CDEF CBLK CBLD);
    mini_printf("TIPS ➡ %s%s(write \"--exit\" or 'control + d' for exit)\n",
        CDEF, CBLK);
    mini_printf("       (write \"--leave\" for leave)\n", CDEF, CBLK);
    mini_printf(CDEF CCYN CBLD);
    mini_printf("Write the file name you want to give to your image:\n  ➡ ");
    mini_printf(CDEF CBLU);
    while (1) {
        char *tmp_file = get_cmd_save(info_game);
        if (info_game->env == 0)
            break;
        if (verif_error_save(info_game, info_menu_home, tmp_file) == 1)
            break;
        mini_printf(CDEF CCYN CBLD);
        mini_printf("\nWrite the file name you want to give \
to your image:\n  ➡ ");
        mini_printf(CDEF CBLU);
    } mini_printf(CDEF);
}
