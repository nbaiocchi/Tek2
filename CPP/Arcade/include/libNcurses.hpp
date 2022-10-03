/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** libNcurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include "IDisplay.hpp"
#include <ncurses.h>
#include "../Event/Event.hpp"
#include <bits/stdc++.h>

const int NCURSE_ESCAPE = 27;
const int NCURSE_UP = 259;
const int NCURSE_DOWN = 258;
const int NCURSE_RIGHT = 261;
const int NCURSE_LEFT = 260;
const int NCURSE_RETURN = 10;
const int NCURSE_SPACE = 32;
const int NCURSE_ENTER = 13;

namespace Arcade {
	class libNcurses : public IDisplay
	{
		public:
			libNcurses();
			~libNcurses() override;

			void init() override;
	        void stop() override;
	        std::string getLibName() const override;
	        void display(std::vector<std::unique_ptr<IComponent>> &components) override; // Display with components
	        std::vector<std::unique_ptr<IEvent>> &getEvents() override;
            void clear() override;
	    private:
				std::vector<std::unique_ptr<IEvent>> events = {};
				WINDOW *window;

				const std::unordered_map<int, int> KEYCODES_TRANSLATION = {
                    {NCURSE_ESCAPE, 0},
                    {NCURSE_LEFT, 1},
                    {NCURSE_RIGHT, 2},
                    {NCURSE_DOWN, 3},
                    {NCURSE_UP, 4},
                    {NCURSE_SPACE, 5},
                    {NCURSE_RETURN, 6},
                    {'a', 7},
                    {'b', 8},
                    {'c', 9},
                    {'d', 10},
                    {'e', 11},
                    {'f', 12},
                    {'g', 13},
                    {'h', 14},
                    {'i', 15},
                    {'j', 16},
                    {'k', 17},
                    {'l', 18},
                    {'m', 19},
                    {'n', 20},
                    {'o', 21},
                    {'p', 22},
                    {'q', 23},
                    {'r', 24},
                    {'s', 25},
                    {'t', 26},
                    {'u', 27},
                    {'v', 28},
                    {'w', 29},
                    {'x', 30},
                    {'y', 31},
                    {'z', 32},
                    {-50, 33} //harcode because no equivalent
            	};
	};
}


#endif /* !LIBNCURSES_HPP_ */

