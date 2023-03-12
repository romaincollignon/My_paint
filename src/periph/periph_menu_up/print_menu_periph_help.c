/*
** EPITECH PROJECT, 2022
** print_menu_periph_help.c
** File description:
** Function :
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>

#include "../../../include/struct_all.h"
#include "my.h"

void print_help_1(i_m_h *info_menu_home, int pos)
{
    if ((sfClock_getElapsedTime
        (info_menu_home->info_menu.time_help).microseconds > 100000)) {
        if (info_menu_home->info_menu.choose_menu == 3)
            info_menu_home->info_menu.choose_menu = 0;
        sfClock_restart(info_menu_home->info_menu.time_help);
    } mini_printf("\n\n\n\n%s%s%s  ➡  INFORMATION", CDEF, CBLD, CBLU);
    if (pos == 1) {
        mini_printf(" SAVE / OPEN IMAGE:%s%s\n", CDEF, CCYN);
        mini_printf("To open or save an image, you must go to the top left \
menu \"FILE\" then select \"save\" or \"open\" and follow the \
instructions written in the terminal. For the image opening, you can \
also click on \"new\" in the same menu and you will have a menu which \
will be displayed (the same as when you open the software) then click \
on the button \"select an image file path\".\n");
    }
    if (pos == 2) {
        print_2();
    }
}

void print_2(void)
{
    mini_printf(" PAINT / ERASER:%s%s\n", CDEF, CCYN);
    mini_printf("To access the brush and the eraser you can access them \
via the menu at the top named \"EDITION\" then select the desired \
tools. You can also select this one on the side menu (2nd and 4th \
button).\n Once on the menu you can change the size of each of them \
using the joystick located next to the button. In addition, you can \
change the shape of the eraser below this same controller by clicking \
on it.\n");
}

void print_help_2(i_m_h *info_menu_home, int pos)
{
    if ((sfClock_getElapsedTime
        (info_menu_home->info_menu.time_help).microseconds > 100000)) {
        if (info_menu_home->info_menu.choose_menu == 3)
            info_menu_home->info_menu.choose_menu = 0;
        sfClock_restart(info_menu_home->info_menu.time_help);
    } mini_printf("\n\n\n\n%s%s%s  ➡  INFORMATION", CDEF, CBLD, CBLU);
    if (pos == 1) {
        mini_printf(" SET COLOR:%s%s\n", CDEF, CCYN);
        mini_printf("To modify the color of the brush you can click on the \
menu at the top \"EDITION\" and by selecting \"SET COLOR\" or by \
clicking on the 5th button on the side menu. Then you can click on the \
desired color in the color selection.\n");
    }
    if (pos == 2) {
        mini_printf(" ZOOM:%s%s\n", CDEF, CCYN);
        mini_printf("To zoom you can click on the top menu \"EDITION\" then \
select the \"ZOOM\" button or click on the 6th button of the side menu \
(left). Once opened the menu you can click on \"+\" to zoom in or \
\"-\" to zoom out.\n");
    }
}

void print_help_3(i_m_h *info_menu_home, int pos)
{
    if ((sfClock_getElapsedTime
        (info_menu_home->info_menu.time_help).microseconds > 100000)) {
        if (info_menu_home->info_menu.choose_menu == 3)
            info_menu_home->info_menu.choose_menu = 0;
        sfClock_restart(info_menu_home->info_menu.time_help);
    }
    mini_printf("\n\n\n\n%s%s%s  ➡  INFORMATION", CDEF, CBLD, CBLU);
    if (pos == 1) {
        print_1();
    }
    if (pos == 2) {
        mini_printf(" EXIT:%s%s\n", CDEF, CCYN);
        mini_printf("To exit the program in the software, you can click on the \
cross at the top right, click on the \"LEAVE\" button at the top right \
or press the \"escape\" key (be careful, the key is not functional in \
the terminal and on the top menu).\n If you are in the terminal you \
can type \"--exit\" to exit the program when possible.\n");
    } mini_printf("%s", CDEF);
}

void print_1(void)
{
    mini_printf(" CREDIT:%s%s\n", CDEF, CCYN);
    mini_printf("The software was produced as part of a project in the \
first year at Epitech and produced by: romain.collignon@epitech.eu.\n \
WARNING : Be careful if the \"EDITION\" menu and the \"PAINT\" tool \
menu are opened simultaneously, the click will be disabled on one of \
the two displays.\nThe buttons having the 3 states are the \"EDITION\" and \
\"HELP\" buttons of the top menu.\n");
}
