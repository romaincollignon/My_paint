/*
** EPITECH PROJECT, 2022
** init_menu_home.c
** File description:
** Function : init_menu_home
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

#include "../../../../include/struct_all.h"
#include "my.h"

static void init_bouton_tools(i_m_h *info_menu_home)
{
    info_menu_home->bouton_tools[0] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 200});
    info_menu_home->bouton_tools[1] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 290});
    info_menu_home->bouton_tools[2] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 380});
    info_menu_home->bouton_tools[3] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 470});
    info_menu_home->bouton_tools[4] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 560});
    info_menu_home->bouton_tools[5] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 650});
    info_menu_home->bouton_tools[6] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 740});
    info_menu_home->bouton_tools[9] = init_bar(info_menu_home, 1,
        (sfVector2f){100, 110}, (sfVector2f){0, 860});
    info_menu_home->bouton_tools[8] = init_bar(info_menu_home, 3,
        (sfVector2f){70, 70}, (sfVector2f){10, 880});
}

static sfSprite* init_icons(char *file, sfVector2f postion, sfVector2f scale)
{
    sfTexture* texture = sfTexture_createFromFile(file, NULL);
    sfSprite* tmp_icons = sfSprite_create();
    sfSprite_setTexture(tmp_icons, texture, sfTrue);
    sfSprite_setPosition(tmp_icons, postion);
    sfSprite_setScale(tmp_icons, scale);
    return tmp_icons;
}

static void init_icons_tools(i_m_h *info_menu_home)
{
    info_menu_home->icons_tools[0] = init_icons("./res/icons/Cursor.png",
        (sfVector2f){13, 203}, (sfVector2f){0.13, 0.13});
    info_menu_home->icons_tools[1] = init_icons("./res/icons/Brush.png",
        (sfVector2f){13, 293}, (sfVector2f){0.13, 0.13});
    info_menu_home->icons_tools[2] = init_icons("./res/icons/pipette.png",
        (sfVector2f){13, 383}, (sfVector2f){0.13, 0.13});
    info_menu_home->icons_tools[3] = init_icons("./res/icons/Rubber.png",
        (sfVector2f){13, 473}, (sfVector2f){0.13, 0.13});
    info_menu_home->icons_tools[4] = init_icons("./res/icons/Blur.png",
        (sfVector2f){13, 563}, (sfVector2f){0.13, 0.13});
    info_menu_home->icons_tools[5] = init_icons("./res/icons/magnifier.png",
        (sfVector2f){13, 653}, (sfVector2f){0.13, 0.13});
    info_menu_home->icons_tools[6] = init_icons("./res/icons/Move.png",
        (sfVector2f){13, 743}, (sfVector2f){0.13, 0.13});
}

void init_rgbcolor(i_m_h *info_menu_home)
{
    info_menu_home->info_display.image_color = malloc(sizeof(sfImage*));
    sfImage *img = sfImage_createFromFile("./res/rgb_color.jpeg");
    sfTexture *textu = sfTexture_createFromImage(img, NULL);
    sfSprite* tmp_sprite = sfSprite_create();
    sfSprite_setTexture(tmp_sprite, textu, sfFalse);
    sfSprite_setPosition(tmp_sprite, (sfVector2f){150, 500});
    sfSprite_setScale(tmp_sprite, (sfVector2f){0.6, 0.6});
    info_menu_home->image_color = tmp_sprite;
    info_menu_home->info_display.image_color = img;
    info_menu_home->info_display.menu_tools =
            malloc(sizeof(sfRectangleShape*) * 15);
    for (int n = 0; n < 15; n++)
        info_menu_home->info_display.menu_tools[n] =
            malloc(sizeof(sfRectangleShape*));
    info_menu_home->info_display.menu_tools[0] = init_bar(info_menu_home, 3,
    (sfVector2f){70, 70}, (sfVector2f){100, 100});
}

void suite_init_struct_menu_home(i_m_h *info_menu_home)
{
    init_bouton_tools(info_menu_home);
    init_icons_tools(info_menu_home);
    sfColor color_pres = {14, 13, 17, 255};
    sfRectangleShape_setFillColor(info_menu_home->bouton_tools[0], color_pres);
    init_rgbcolor(info_menu_home);
}
