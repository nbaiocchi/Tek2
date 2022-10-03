/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** core
*/

#include "../include/Core.hpp"

typedef void *(*Loader)();

Arcade::Core::Core(const std::string& libPath)
{
    Loader func2;
    this->libHandle = dlopen(libPath.c_str(), RTLD_LAZY);
    if (this->libHandle == nullptr) {
        throw Errors("The shared library cannot be opened.");
    }
    auto func = (Loader) dlsym(this->libHandle, "getLibType");
    if (func() == nullptr) {
        func2 = (Loader) dlsym(this->libHandle, "getDisplayInstance");
    }
    else {
        func2 = (Loader) dlsym(this->libHandle, "getGameInstance");
    }

    if ((dlerror()) != nullptr) {
        throw Errors("The shared library cannot be opened.");
    }
    graphic = static_cast<Arcade::IDisplay *>(func2());
    graphic->init();
    // game

    Loader func3;
    this->libHandle = dlopen("./lib/arcade_menu.so", RTLD_LAZY);
    if (this->libHandle == nullptr) {
        throw Errors("The shared library cannot be opened.");
    }
    auto func_ = (Loader) dlsym(this->libHandle, "getLibType");
    if (func_() == nullptr) {
        func3 = (Loader) dlsym(this->libHandle, "getDisplayInstance");
    }
    else {
        func3 = (Loader) dlsym(this->libHandle, "getGameInstance");
    }

    if ((dlerror()) != nullptr) {
        throw Errors("The shared library cannot be opened.");
    }
    game = static_cast<Arcade::IGame *>(func3());
    game->init();
}

Arcade::Core::~Core()
{
    dlclose(this->libHandle);
}

Arcade::Core::Tristate Arcade::Core::getType(const std::string& filepath)
{
    void *libhandle = dlopen(filepath.c_str(), RTLD_LAZY);
    unsigned char (*function)()  = (unsigned char (*)()) dlsym(libhandle, "getLibType");
    char *error;
    if (((error = dlerror()) != nullptr) || filepath == "./lib/arcade_menu.so") {
        return (Tristate::INVALID);
    }
    int check = function();
    if (check == 1) {
        dlclose(libhandle);
        return Tristate::GAME;
    }
    dlclose(libhandle);
    return (Tristate::GRAPHIC);
}

void Arcade::Core::fill()
{
    std::string path = "./lib";

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        Rect rect;
        std::string filename = entry.path();
        Tristate state = getType(filename);
        if (state == Tristate::GAME) {
            all_games.push_back(filename);
        } else if (state == Tristate::GRAPHIC) {
            all_graphicals.push_back(filename);
        }
    }
}

void Arcade::Core::launchMenu()
{
    this->fill();
    while (this->handleEvents(graphic->getEvents())) {
        graphic->clear();
        graphic->display(this->game->getComponents());
        if (game->getGameName() == "menu") { 
            check_change_game();
        }
    }
}

void Arcade::Core::switch_lib_key(size_t key)
{
    if (key == keyBinding::K) { // prev game
        switch_libs("./lib/arcade_menu.so");
    }

    if (key == keyBinding::O) { // prev game
        if (ac_game != 0)
            ac_game -= 1;
        else
            ac_game = all_games.size() - 1;
        switch_libs(all_games[ac_game]);
    }
    if (key == keyBinding::P) { // next game
        if (ac_game == all_games.size() - 1)
            ac_game = 0;
        else
            ac_game += 1;
        switch_libs(all_games[ac_game]);
    }
    if (key == keyBinding::L) { // prev graphic
        if (ac_graphic != 0)
            ac_graphic -= 1;
        else
            ac_graphic = all_graphicals.size() - 1;
        switch_libs(all_graphicals[ac_graphic]);
    }
    if (key == keyBinding::M) { // next graphic
        if (ac_graphic == all_graphicals.size() - 1)
            ac_graphic = 0;
        else
            ac_graphic += 1;
        switch_libs(all_graphicals[ac_graphic]);
    }
}

bool Arcade::Core::handleEvents(std::vector<std::unique_ptr<Arcade::IEvent>> &events)
{
    for (size_t i = 0; i != events.size(); i += 1) {
        if (events[i]->getKey() == keyBinding::QUIT) {
            return false;
        }
        if (game->getGameName() != "menu")
            switch_lib_key(events[i]->getKey());
    }
    game->sendEvents(events);
    return true;
}

std::vector<std::string> Arcade::Core::getNewLibs(std::string s)
{
    std::vector<std::string> v;
	std::string temp = "";
	for(size_t i=0;i<s.length();++i){
		
		if(s[i]=='|'){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	v.push_back(temp);
	return (v);
}

void Arcade::Core::switch_libs(const std::string& filepath)
{
    char *error;
    Loader func2;
    this->libHandle = dlopen(filepath.c_str(), RTLD_LAZY);
    if (this->libHandle == nullptr) {
        throw Errors("The shared library cannot be opened.");
    }
    auto func = (Loader) dlsym(this->libHandle, "getLibType");
    if ((error = dlerror()) != nullptr) {
            throw Errors("The shared library cannot be opened.");
        }
    if (func() == 0) {
        func2 = (Loader) dlsym(this->libHandle, "getDisplayInstance");
        if ((error = dlerror()) != nullptr) {
            throw Errors("The shared library cannot be opened.");
        }
        graphic->stop();
        graphic = static_cast<Arcade::IDisplay *>(func2());
        graphic->init();
    }
    else {
        func2 = (Loader) dlsym(this->libHandle, "getGameInstance");
        if ((error = dlerror()) != nullptr) {
            throw Errors("The shared library cannot be opened.");
        }
        game->stop();
        game = static_cast<Arcade::IGame *>(func2());
        game->init();
    }
}

void Arcade::Core::check_change_game()
{
    if (game->getEvent()) {
        new_Lib_Game = game->getEvent()->getData();
        std::string prev_lib_game = "./lib/" + graphic->getLibName() + "|" + "./lib/" + game->getGameName();
        if (getNewLibs(new_Lib_Game)[0] != getNewLibs(prev_lib_game)[0])
        {
            switch_libs(getNewLibs(new_Lib_Game)[0]);
        }
        if (getNewLibs(new_Lib_Game)[1] != getNewLibs(prev_lib_game)[1])
        {
            switch_libs(getNewLibs(new_Lib_Game)[1]);
        }
    }
}