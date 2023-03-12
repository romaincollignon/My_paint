/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    for (int n = 0; s1[n] != '\0'; n = n + 1) {
        if (s1[n] < s2[n]) {
            result = s1[n] - s2[n];
            return result;
        }
        if (s1[n] > s2[n]) {
            result = s1[n] - s2[n];
            return result;
        }
    }
    return 0;
}
