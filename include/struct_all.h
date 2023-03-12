/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H

    typedef struct info_game {
        int env;
        int display;
        int choose_paint;
        int custom_paint;
    } i_g;

    typedef struct info_display {
        sfRectangleShape **bouton;
        sfText **txt;
        char *open_img;
        sfImage *image_default;
        sfTexture *tmp_textu;
        sfSprite *fond_default;
        float scale;
        sfColor tmp_color;
        sfColor color_rubber;
        sfRectangleShape **menu_tools;
        sfImage *image_color;
        int start_paint;
        float last_y;
        float last_x;
        int size_rubber;
        int choose_rubber;
        sfSprite **icon_rubber;
        sfRectangleShape **form_rubber;
        int size_paint;
        int change_tools;
        sfClock *coldown;
    } i_d;

    typedef struct info_menu {
        sfClock *time_file;
        int choose_menu;
        sfText *text_look_t;
        sfText **text_m_file;
        sfRectangleShape **rect_file;
        int one_click_file;

        sfClock *time_edition;
        sfText **text_m_edition;
        sfRectangleShape **rect_edition;

        sfClock *time_help;
        sfText **text_m_help;
        sfText *text_lo_t_h;
        sfRectangleShape **rect_help;
    } i_m;

    typedef struct info_menu_home {
        sfFont *font_txt_default;
        sfText *txt_file;
        sfText *txt_edition;
        sfText *txt_layer;
        sfText *txt_help;
        sfText *txt_reset;
        sfRectangleShape **bouton;
        int click_bouton_menu;
        sfRectangleShape **bouton_tools;
        sfSprite **icons_tools;
        sfSprite *image_color;
        int click_bouton_tools;
        sfRectangleShape *bar_up;
        sfRectangleShape *bar_left;
        float rad_x_w;
        float rad_y_w;
        i_d info_display;
        i_m info_menu;
    } i_m_h;


    typedef struct info_menu_loading {
        sfClock *time;
        sfFont *Font_txt_01;
        sfText *txt_load;
        sfText *txt_wait;
        sfText *txt_leave;
        sfRectangleShape *contour;
        sfRectangleShape *bar_load;
    } i_m_l;

#endif /* !STRUCT_MENU_H */
