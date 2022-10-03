/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** main
*/

#include "include/Core.hpp"

int main(int ac, char **av)
{
    try 
    {
        if (ac != 2) {
            throw Errors("Not right amount of arguments.");
        }
        std::unique_ptr<Arcade::Core> core = std::make_unique<Arcade::Core>(av[1]);
        core->launchMenu();
    }
    catch (Errors &e)
    {
        std::cout << e.what() << std::endl;
        return (84);
    }
    return (0);
}