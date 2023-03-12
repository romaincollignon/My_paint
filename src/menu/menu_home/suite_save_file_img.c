/*
** EPITECH PROJECT, 2022
** suite_save_file_img.c
** File description:
** Function : suite_save_file_img
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
    if (my_strlen(buffer) == 2)
        buffer[1] = '\0';
    return buffer;
}

int verif_tmp_file(char *tmp_file)
{
    if (my_strlen(tmp_file) != 1)
        return 0;
    if ((tmp_file[0] == '1' || tmp_file[0] == '2' || tmp_file[0] == '3'
        || tmp_file[0] == '4') && tmp_file[1] == '\0')
        return 1;
    return 0;
}

char *add_extension(char *file, char *tmp_file)
{
    char *good_file = malloc(sizeof(char) * (my_strlen(file) + 5));
    my_strcpy(good_file, file);
    int n = my_strlen(file) + 1;
    good_file[n - 1] = '.';
    if (tmp_file[0] == '1') {
        good_file[n] = 'p'; good_file[n + 1] = 'n'; good_file[n + 2] = 'g';
    } if (tmp_file[0] == '2') {
        good_file[n] = 'b'; good_file[n + 1] = 'm'; good_file[n + 2] = 'p';
    } if (tmp_file[0] == '3') {
        good_file[n] = 't'; good_file[n + 1] = 'g'; good_file[n + 2] = 'a';
    } if (tmp_file[0] == '4') {
        good_file[n] = 'j'; good_file[n + 1] = 'p'; good_file[n + 2] = 'g';
    } good_file[n + 3] = '\0';
    return good_file;
}

char *extension_file(i_g * info_game, char *file)
{
    int error = 1;
    while (1) {
        mini_printf("\n%s%sPlease select extension :\n", CCYN, CBLD);
        mini_printf("   - png = 1\n   - bmp = 2\n   - tga = 3\n   - jpg = 4\n");
        mini_printf("  ➡ %s%s", CDEF, CBLU);
        char *tmp_file = get_cmd_save(info_game);
        if (info_game->env == 0)
            break;
        error = verif_tmp_file(tmp_file);
        if (error == 0) {
            mini_printf("%s%s%s Error: ", CDEF, CBLD, CRED);
            mini_printf("%s%sPlease write : \"1\", \"2\", \"3\" or \"4\"\n",
                CDEF, CRED);
        } else {
            file = add_extension(file, tmp_file);
            break;
        }
    }
    return file;
}
