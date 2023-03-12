/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> MY_HUNTER
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>


int my_power_rec_x(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        return (nb * my_power_rec_x(nb, p - 1));
    }
}

int my_lenint_x(int nbr)
{
    int i = 0;
    while (nbr > 0) {
        nbr = nbr / 10;
        i++;
    }
    return i;
}

char* int_pass_char(int nbr)
{
    int tmp = nbr;
    int dgt = 0;
    while (tmp != 0) {
        tmp /= 10;
        dgt++;
    }
    char* str = (char*) malloc((dgt + 1) * sizeof(char));
    tmp = nbr;
    str[dgt] = '\0';
    for (int i = dgt - 1; i >= 0; i--) {
        str[i] = (tmp % 10) + '0';
        tmp /= 10;
    }
    return str;
}
