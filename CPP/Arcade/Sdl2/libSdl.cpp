/*
** EPITECH PROJECT, 2022
** ExempleDL
** File description:
** libSdl
*/

#include "../include/Core.hpp"
#include "../include/libSdl.hpp"

const int WIDTH = 900;
const int HEIGHT = 901;
const int MAX_WIDTH = 1920;
const int MAX_HEIGHT = 1080;
const int X_GAP = 510;
const int Y_GAP = 90;

Arcade::LibSdl::LibSdl()
{
}

Arcade::LibSdl::~LibSdl()
{
}

void Arcade::LibSdl::clear()
{
    SDL_RenderClear(this->renderer);
}

void Arcade::LibSdl::display(std::vector<std::unique_ptr<IComponent>> &components)
{

    for (size_t i = 0; i != components.size(); i += 1) {
        if (components[i]->getType() == Arcade::IComponent::OBJECT && components[i]->getWidth() == 100 && components[i]->getHeight() == 100) {
            rect.x = components[i]->getX() * MAX_WIDTH / 100;
            rect.y = components[i]->getY() * MAX_HEIGHT / 100;
            rect.w = components[i]->getWidth() * MAX_WIDTH / 100;
            rect.h = components[i]->getHeight() * MAX_HEIGHT / 100;
            SDL_RenderCopy(renderer, all_texture.at(components[i]->getFile() + ".png"), NULL, &rect);
        } else if (components[i]->getType() == Arcade::IComponent::OBJECT) {
            rect.x = components[i]->getX() * WIDTH / 100 + X_GAP;
            rect.y = components[i]->getY() * HEIGHT / 100 + Y_GAP;
            rect.w = components[i]->getWidth() * WIDTH / 100;
            rect.h = components[i]->getHeight() * HEIGHT / 100;
            SDL_RenderCopy(renderer, all_texture.at(components[i]->getFile() + ".png"), NULL, &rect);
        } else if (components[i]->getType() == Arcade::IComponent::TEXT) {
            int h = 100;
            int w = 50;
            int x = components[i]->getX() * WIDTH / 100 + X_GAP;
            int y = components[i]->getY() * HEIGHT / 100 + Y_GAP;
            surface = TTF_RenderText_Solid(this->font, components[i]->getText().c_str(), White);
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_QueryTexture(texture, NULL, NULL, &h, &w);
            rect = {x, y, h, w};
            SDL_RenderCopy(renderer, texture, NULL, &rect);
        } else {
            // sound
        }
    }
    SDL_RenderPresent(renderer);
    // SDL_FreeSurface(surface);
    // SDL_DestroyTexture(texture);
    // SDL_RenderPresent(this->renderer);
};

void Arcade::LibSdl::init()
{
    SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
    // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    // this->music = Mix_LoadMUS("./Sound/music.mp3");
    // Mix_PlayMusic(music, -1);
	this->window = nullptr;
	this->window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_FULLSCREEN);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (!this->window) {
		std::cout << "Cant create Window" << std::endl;
		exit(0);
	}
    this->font = TTF_OpenFont("Font/EquinoxRegular.ttf", 20);
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);

    std::string path = "./Sprite";

    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        std::string fn = entry.path();
        if (fn.substr(fn.find_last_of(".") + 1) == "png") {
            surface = IMG_Load(fn.c_str());
            all_surface.insert( std::pair<std::string, SDL_Surface *>(fn, surface));
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            all_texture.insert( std::pair<std::string, SDL_Texture *>(fn, texture));
        }
    }

};
void Arcade::LibSdl::stop()
{
    TTF_CloseFont(font);
    SDL_DestroyWindow(this->window);
	TTF_Quit();
	SDL_Quit();
};

std::string Arcade::LibSdl::getLibName() const
{
    return "arcade_sdl2.so";
};

std::vector<std::unique_ptr<Arcade::IEvent>> &Arcade::LibSdl::getEvents()
{
	SDL_Event event;
    Arcade::Pos tmp;

    this->events.clear();
    while (SDL_PollEvent(&event)) {
		switch (event.type) {
		    case SDL_KEYDOWN:
                if (KEYCODES_TRANSLATION.count(event.key.keysym.scancode)) {
                    SDL_GetMouseState(&tmp.x,&tmp.y);
                    this->events.push_back(std::make_unique<Arcade::Event>(KEYCODES_TRANSLATION.find(event.key.keysym.scancode)->second, tmp));
                } 
            case SDL_MOUSEBUTTONDOWN: // if the event is mouse click
                SDL_GetMouseState(&tmp.x,&tmp.y);
                tmp.x = (tmp.x - X_GAP) * 100 / 900;
                tmp.y = (tmp.y - Y_GAP)* 100 / 901;
                this->events.push_back(std::make_unique<Arcade::Event>(KEYCODES_TRANSLATION.find(SDL_MOUSEBUTTONDOWN)->second, tmp));
            break;
		}
	}
    return this->events;
};