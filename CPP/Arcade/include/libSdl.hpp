/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** libSfml
*/

#ifndef LIBSDL_HPP_
#define LIBSDL_HPP_

#include "IDisplay.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../Event/Event.hpp"
#include <bits/stdc++.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <map>

namespace Arcade {
	class LibSdl : public IDisplay
	{
		public:
			LibSdl();
			~LibSdl() override;
	
			void init() override;
		    void stop() override;
		    std::string getLibName() const override;
		    void display(std::vector<std::unique_ptr<IComponent>> &components) override; // Display with components
		    std::vector<std::unique_ptr<IEvent>> &getEvents() override;
            void clear() override;
		private:
            std::map<std::string, SDL_Surface*> all_surface;
            std::map<std::string, SDL_Texture*> all_texture;
            SDL_Color White = {255, 255, 255};
            SDL_Surface* surface;
            SDL_Texture* texture;
            SDL_Rect rect = {0, 0, 0, 0};
			std::vector<std::unique_ptr<IEvent>> events = {};
	        SDL_Window *window;
			SDL_Renderer *renderer;
			SDL_Surface *screen;
			TTF_Font* font;
			// Mix_Music *music;
            const std::unordered_map<int, int> KEYCODES_TRANSLATION = {
                    {SDL_SCANCODE_ESCAPE, 0},
                    {SDL_SCANCODE_LEFT, 1},
                    {SDL_SCANCODE_RIGHT, 2},
                    {SDL_SCANCODE_DOWN, 3},
                    {SDL_SCANCODE_UP, 4},
                    {SDL_SCANCODE_SPACE, 5},
                    {SDL_SCANCODE_RETURN, 6},
                    {SDL_SCANCODE_A, 7},
                    {SDL_SCANCODE_B, 8},
                    {SDL_SCANCODE_C, 9},
                    {SDL_SCANCODE_D, 10},
                    {SDL_SCANCODE_E, 11},
                    {SDL_SCANCODE_F, 12},
                    {SDL_SCANCODE_G, 13},
                    {SDL_SCANCODE_H, 14},
                    {SDL_SCANCODE_I, 15},
                    {SDL_SCANCODE_J, 16},
                    {SDL_SCANCODE_K, 17},
                    {SDL_SCANCODE_L, 18},
                    {SDL_SCANCODE_M, 19},
                    {SDL_SCANCODE_N, 20},
                    {SDL_SCANCODE_O, 21},
                    {SDL_SCANCODE_P, 22},
                    {SDL_SCANCODE_Q, 23},
                    {SDL_SCANCODE_R, 24},
                    {SDL_SCANCODE_S, 25},
                    {SDL_SCANCODE_T, 26},
                    {SDL_SCANCODE_U, 27},
                    {SDL_SCANCODE_V, 28},
                    {SDL_SCANCODE_W, 29},
                    {SDL_SCANCODE_X, 30},
                    {SDL_SCANCODE_Y, 31},
                    {SDL_SCANCODE_Z, 32},
                    {SDL_MOUSEBUTTONDOWN, 33}
            };
	};
}
#endif /* !LIBSDL_HPP_ */