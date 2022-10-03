/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** libManagement
*/

#include "../include/LibManagement.hpp"
#include "../include/libSfml.hpp"

extern "C"
{
    unsigned char getLibType()
    {
        return (0);
    }
}

extern "C"
{
    Arcade::IGame *getGameInstance()
    {
        return (NULL);
    }
}

extern "C"
{
    Arcade::IDisplay *getDisplayInstance()
    {
        return (new Arcade::LibSfml());
    }
}

extern "C"
{
    void destroyInterface(void *interface)
    {
        delete (Arcade::LibSfml *) interface;
    }
}
