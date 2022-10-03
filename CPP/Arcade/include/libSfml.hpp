/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** libSfml
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include "IDisplay.hpp"
#include "IGame.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Event/Event.hpp"
#include <bits/stdc++.h>

namespace Arcade {
	class LibSfml : public IDisplay
	{
		public:
			LibSfml();
			~LibSfml() override;
	
			void init() override;
			void stop() override;
			std::string getLibName() const override;
			void display(std::vector<std::unique_ptr<IComponent>> &components) override; // Display with components
			std::vector<std::unique_ptr<IEvent>> &getEvents() override;
            void clear() override;
		private:
            std::vector<std::unique_ptr<IEvent>> events = {};
			sf::RenderWindow *window;
			sf::Font font;
			sf::Text text;
			sf::Event event;
			// sf::Music music;
            const std::unordered_map<int, int> KEYCODES_TRANSLATION = {
                    {sf::Keyboard::Escape, 0},
                    {sf::Keyboard::Left, 1},
                    {sf::Keyboard::Right, 2},
                    {sf::Keyboard::Down, 3},
                    {sf::Keyboard::Up, 4},
                    {sf::Keyboard::Space, 5},
                    {sf::Keyboard::Enter, 6},
                    {sf::Keyboard::A, 7},
                    {sf::Keyboard::B, 8},
                    {sf::Keyboard::C, 9},
                    {sf::Keyboard::D, 10},
                    {sf::Keyboard::E, 11},
                    {sf::Keyboard::F, 12},
                    {sf::Keyboard::G, 13},
                    {sf::Keyboard::H, 14},
                    {sf::Keyboard::I, 15},
                    {sf::Keyboard::J, 16},
                    {sf::Keyboard::K, 17},
                    {sf::Keyboard::L, 18},
                    {sf::Keyboard::M, 19},
                    {sf::Keyboard::N, 20},
                    {sf::Keyboard::O, 21},
                    {sf::Keyboard::P, 22},
                    {sf::Keyboard::Q, 23},
                    {sf::Keyboard::R, 24},
                    {sf::Keyboard::S, 25},
                    {sf::Keyboard::T, 26},
                    {sf::Keyboard::U, 27},
                    {sf::Keyboard::V, 28},
                    {sf::Keyboard::W, 29},
                    {sf::Keyboard::X, 30},
                    {sf::Keyboard::Y, 31},
                    {sf::Keyboard::Z, 32},
                    {sf::Mouse::Left, 33}
            };
	};
}

#endif /* !LIBSFML_HPP_ */