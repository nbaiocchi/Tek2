/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#ifndef TEST_ARCADE
#define TEST_ARCADE

#include <vector>
#include <dlfcn.h>
#include <map>
#include <ncurses.h>
#include <dirent.h>
#include <fstream>
#include <unistd.h>
#include <unistd.h>
#include <iostream>
#include "IDisplay.hpp"
#include "IEvent.hpp"
#include "IGame.hpp"
#include <string>
#include <stdio.h>
#include <string.h>
#include "../Errors/Errors.hpp"

namespace Arcade {
    class Core
    {
        public :
            Core(const std::string&);
            ~Core();
            void launchMenu();
            bool handleEvents(std::vector<std::unique_ptr<Arcade::IEvent>> &events);
            void check_change_game();
            void switch_libs(const std::string& filepath);
            void fill();
            std::vector<std::string> getNewLibs(std::string s);
            void switch_lib_key(size_t key);
            enum keyBinding {
                QUIT = 0, ARROW_LEFT, ARROW_RIGHT, ARROW_DOWN, ARROW_UP, SPACE, ENTER,
                A, B, C, D, E, F, G, H, I, J, K, L, M,
                N, O, P, Q, R, S, T, U, V, W, X, Y, Z, MouseClick
            };
            enum Tristate {
                GAME,
                GRAPHIC,
                INVALID
            };
            Tristate getType(const std::string& filepath);
    
        private:
            Arcade::IDisplay *graphic;
            Arcade::IGame *game{};
            std::string new_Lib_Game = "";
            std::size_t ac_game = 0;
            std::size_t ac_graphic = 0;
            std::vector<std::string> all_games;
            std::vector<std::string> all_graphicals;
            void *libHandle;
    };
}
#endif