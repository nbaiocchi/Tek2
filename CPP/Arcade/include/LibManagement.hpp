/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** LibManagement
*/

#ifndef LIB_MANAGEMENT_HPP
#define LIB_MANAGEMENT_HPP

#include "Core.hpp"

extern "C" unsigned char getLibType();    // 0 = Display | 1 = Game
extern "C" Arcade::IGame *getGameInstance();
extern "C" Arcade::IDisplay *getDisplayInstance();
extern "C" void destroyInterface(void *interface); // Delete interface

#endif /* !LIB_MANEGEMENT_HPP */
