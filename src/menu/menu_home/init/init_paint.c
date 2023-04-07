/*
** EPITECH PROJECT, 2022
** init_paint.c
** File description:
** Function : init_paint
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

static void suite_init_paint(i_m_h *info_menu_home, i_g *info_game)
{
    sfImage *img;
    if (info_game->choose_paint == 1 && info_game->custom_paint != 1) {
        img = sfImage_createFromFile("./res/fond_paint/black_1920x1080.jpg");
        info_menu_home->info_display.color_rubber = sfBlack;
    } if (info_game->choose_paint == 2 && info_game->custom_paint != 1) {
        img = sfImage_createFromFile("./res/fond_paint/white_1920x1080.jpg");
        info_menu_home->info_display.color_rubber = sfWhite;
    } if (info_game->custom_paint == 1) {
        img = info_menu_home->info_display.image_default;
        info_menu_home->info_display.color_rubber = sfWhite;
    } sfTexture *textu = sfTexture_createFromImage(img, NULL);
    sfSprite* tmp_sprite = sfSprite_create();
    sfSprite_setTexture(tmp_sprite, textu, sfFalse);
    sfSprite_setPosition(tmp_sprite, (sfVector2f){180, 130});
    info_menu_home->info_display.scale = 0.74;
    sfSprite_setScale(tmp_sprite, (sfVector2f){0.74, 0.74});
    info_menu_home->info_display.image_default = img;
    info_menu_home->info_display.tmp_textu = textu;
    info_menu_home->info_display.fond_default = tmp_sprite;
    info_game->choose_paint = 3;
}

void init_menu_paint(i_m_h *info_menu_home)
{
    info_menu_home->info_display.menu_tools[4] = init_bar(info_menu_home, 1,
        (sfVector2f){60, 330}, (sfVector2f){110, 200});
    info_menu_home->info_display.menu_tools[5] = init_bar(info_menu_home, 2,
        (sfVector2f){10, 260}, (sfVector2f){135, 220});
    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle, (sfVector2f){120, 222});
    sfRectangleShape_setFillColor(rectangle, sfWhite);
    sfRectangleShape_setSize(rectangle, (sfVector2f){40, 5});
    info_menu_home->info_display.menu_tools[6] = rectangle;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./res/policy/default.ttf");
    sfText_setString(text,
        int_pass_char(info_menu_home->info_display.size_paint));
    sfText_setPosition(text, (sfVector2f){125, 490});
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    info_menu_home->info_display.txt[4] = text;
}

void malloc_form_paint(i_m_h *info_menu_home)
{
    info_menu_home->info_display.coldown_paint = malloc(sizeof(sfClock*));
    info_menu_home->info_display.coldown_paint = sfClock_create();
    info_menu_home->info_display.icon_paint = malloc(sizeof(sfSprite*) * 2);
    info_menu_home->info_display.icon_paint[0] = malloc(sizeof(sfSprite*));
    info_menu_home->info_display.icon_paint[1] = malloc(sizeof(sfSprite*));
    info_menu_home->info_display.choose_paint = 0;
    info_menu_home->info_display.form_paint = malloc(sizeof(sfRectangleShape*)
        * 2);
    info_menu_home->info_display.form_paint[0] =
        malloc(sizeof(sfRectangleShape*));
    info_menu_home->info_display.form_paint[1] =
        malloc(sizeof(sfRectangleShape*));
    info_menu_home->info_display.form_paint[0] =
    init_bar(info_menu_home, 1, (sfVector2f){60, 60}, (sfVector2f){110, 545});
    info_menu_home->info_display.form_paint[1] =
    init_bar(info_menu_home, 2, (sfVector2f){50, 50}, (sfVector2f){115, 550});
}

void init_form_paint(i_m_h *info_menu_home)
{
    malloc_form_paint(info_menu_home);
    sfImage *img_1 = sfImage_createFromFile("./res/icons_geo/carre.png");
    sfTexture *textu_1 = sfTexture_createFromImage(img_1, NULL);
    sfSprite* tmp_sprite_1 = sfSprite_create();
    sfSprite_setTexture(tmp_sprite_1, textu_1, sfFalse);
    sfSprite_setPosition(tmp_sprite_1, (sfVector2f){120, 555});
    sfSprite_setScale(tmp_sprite_1, (sfVector2f){0.08, 0.08});
    info_menu_home->info_display.icon_paint[0] = tmp_sprite_1;
    sfImage *img_2 = sfImage_createFromFile("./res/icons_geo/cercle.png");
    sfTexture *textu_2 = sfTexture_createFromImage(img_2, NULL);
    sfSprite* tmp_sprite_2 = sfSprite_create();
    sfSprite_setTexture(tmp_sprite_2, textu_2, sfFalse);
    sfSprite_setPosition(tmp_sprite_2, (sfVector2f){120, 555});
    sfSprite_setScale(tmp_sprite_2, (sfVector2f){0.08, 0.08});
    info_menu_home->info_display.icon_paint[1] = tmp_sprite_2;
}

void init_paint(i_m_h *info_menu_home, i_g *info_game)
{
    info_menu_home->info_display.fond_default =
        malloc(sizeof(sfSprite*));
    info_menu_home->info_display.tmp_textu =
        malloc(sizeof(sfTexture*));
    suite_init_paint(info_menu_home, info_game);
    info_menu_home->info_display.size_paint = 20;
    init_menu_paint(info_menu_home);
    init_form_paint(info_menu_home);
}
