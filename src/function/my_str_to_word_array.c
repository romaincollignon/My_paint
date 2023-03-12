/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_getnbr(char const *str);
int mini_printf(const char *format, ...);

int calc_height(char *file)
{
    int n = 0;
    int height = 1;
    while (file[n] != '\0') {
        if (file[n] == ' ')
            height++;
        n++;
    }
    return height;
}

int calc_length(char *file)
{
    int n = 0;
    int length = 1;
    int a = 2;
    while (file[n] != ' ') {
        a++;
        n++;
    }
    while (file[a] != ' ') {
        length++;
        a++;
    }
    return length;
}

char **no_espace(char *b_tab)
{
    char **result = malloc(sizeof(char *) * 2);
    result[0] = malloc(sizeof(char) * my_strlen(b_tab));
    result[0] = b_tab;
    result[1] = malloc(sizeof(char) * 8);
    result[1] = NULL;
    return result;
}

char **my_str_to_word_array(char *b_tab)
{
    int nb_line = calc_height(b_tab) - 1;
    if (nb_line == 0)
        return no_espace(b_tab);
    int size = calc_length(b_tab);
    char **tab = malloc(sizeof(char *) * (nb_line + 1));
    int i = 0;
    int a = 0;
    tab[a] = malloc(sizeof(char ) * size);
    for (int n = 0; b_tab[n] != '\0'; n++) {
        if (b_tab[n] == ' ') {
            tab[a][i] = '\0';
            i = 0;
            a++;
            tab[a] = malloc(sizeof(char ) * (size + 1));
        } else {
            tab[a][i] = b_tab[n];
            i++;
        }
    } tab[a] = NULL;
    return tab;
}
