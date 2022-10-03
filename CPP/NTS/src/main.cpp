/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** tt
*/

#include "include.hpp"

int main(int ac, char **av)
{
    try 
    {
        if (ac != 2)
            throw Errors("not correct arguments");
        Circuit all(av[1]);
        all.simulate();
        while (1) {
            std::vector<std::string> command;
            if (utils::sanitize(command))
                return (0);
            if (command[0] == "exit")
                return (0);
            if (command.size() == 1)
                all.handle_cmd(command[0]);
            else
                all.setValue(command[0], command[1]);
        }
    }
    catch (Errors &e)
    {
        std::cout << e.what() << std::endl;
        return (84);
    }
    return 0;
}

