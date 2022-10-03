/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** libManagement
*/

#include "../../include/LibManagement.hpp"
#include "arcade_nibbler.hpp"

extern "C"
{
    unsigned char getLibType()
    {
        return (1);
    }
}

extern "C"
{
    Arcade::IGame *getGameInstance()
    {
        return (new Arcade::Nibbler());
    }
}

extern "C"
{
    Arcade::IDisplay *getDisplayInstance()
    {
        return (NULL);
    }
}

extern "C"
{
    void destroyInterface(void *interface)
    {
        delete (Arcade::Nibbler *) interface;
    }
}
