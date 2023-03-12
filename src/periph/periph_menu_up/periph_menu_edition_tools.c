/*
** EPITECH PROJECT, 2022
** periph_menu_edition_tools.c
** File description:
** Function : ALL bouton in menu_edition -> tools
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

void periph_menu_edition_paint(sfRenderWindow* w, i_m_h *info_menu_home)
{
    if (info_menu_home->info_menu.choose_menu != 2)
        return;
    int zone_edition[4] = {115, 200, 60, 95};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_edition, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[1], color_cli);
            info_menu_home->click_bouton_tools = 1;
            return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[1], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_menu.rect_edition[1], color_default);
    }
}

void periph_menu_edition_pipette(sfRenderWindow* w, i_m_h *info_menu_home)
{
    if (info_menu_home->info_menu.choose_menu != 2)
        return;
    int zone_edition[4] = {115, 200, 100, 135};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_edition, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[2], color_cli);
            info_menu_home->click_bouton_tools = 2;
            return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[2], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_menu.rect_edition[2], color_default);
    }
}

void periph_menu_edition_eraser(sfRenderWindow* w, i_m_h *info_menu_home)
{
    if (info_menu_home->info_menu.choose_menu != 2)
        return;
    int zone_edition[4] = {115, 200, 140, 175};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_edition, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[3], color_cli);
            info_menu_home->click_bouton_tools = 3;
            return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[3], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_menu.rect_edition[3], color_default);
    }
}

void periph_menu_edition_color(sfRenderWindow* w, i_m_h *info_menu_home)
{
    if (info_menu_home->info_menu.choose_menu != 2)
        return;
    int zone_edition[4] = {115, 200, 180, 215};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_edition, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[4], color_cli);
            info_menu_home->click_bouton_tools = 4;
            return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[4], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_menu.rect_edition[4], color_default);
    }
}

void periph_menu_edition_zoom(sfRenderWindow* w, i_m_h *info_menu_home)
{
    if (info_menu_home->info_menu.choose_menu != 2)
        return;
    int zone_edition[4] = {115, 200, 220, 255};
    sfColor color_default = {34, 33, 37, 255};
    sfColor color_pass = {54, 53, 57, 255};
    sfColor color_cli = {0, 0, 0, 255};
    if (verif_zone(zone_edition, w) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[5], color_cli);
            info_menu_home->click_bouton_tools = 5;
            return;
        } else {
            sfRectangleShape_setFillColor(
                info_menu_home->info_menu.rect_edition[5], color_pass);
        }
    } else {
        sfRectangleShape_setFillColor(
            info_menu_home->info_menu.rect_edition[5], color_default);
    }
}
