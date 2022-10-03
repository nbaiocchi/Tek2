/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Menu
*/

#include "Menu.hpp"

typedef void *(*Loader)();

using namespace Arcade;

Menu::Menu()
{
}
Menu::~Menu()
{
}
Menu::Tristate Menu::getType(std::string filepath)
{
    void *libhandle = dlopen(filepath.c_str(), RTLD_LAZY);
    unsigned char (*function)()  = (unsigned char (*)()) dlsym(libhandle, "getLibType");
    char *error;
    if (((error = dlerror()) != NULL) || filepath == "./lib/arcade_menu.so") {
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
std::string Menu::sanitize_lib_name(std::string filepath)
{
    filepath = filepath.erase(0, 6);
    return filepath;
}
void Menu::init()
{
    std::string path = "./lib";
    int y_game = 20;
    int y_graphic = 20;
    size_t id = 0;

    Rect rect;
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::TEXT, "../Font/EquinoxRegular.ttf", 40, 25, 20 , 10, "Please enter your Name : ", rect));
    id += 1;
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/MenuBackground", 0, 0, 100 , 100, "sprite", rect));
    id += 1;
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/final_blue_line", 15, 23, 12 , 1, "sprite", rect));
    id += 1;
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/final_red_line", 65, 23, 12 , 1, "sprite", rect));
    id += 1;
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path();
        Tristate state = getType(filename);
        if (state == Tristate::GAME) {
            this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::TEXT, "../Font/EquinoxRegular.ttf", 15, y_game, 20 , 10, sanitize_lib_name(filename), rect));
            y_game += 10;
        } else if (state == Tristate::GRAPHIC) {
            this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::TEXT, "../Font/EquinoxRegular.ttf", 65, y_graphic, 20 , 10, sanitize_lib_name(filename), rect));
            y_graphic += 10;
        }
        id += 1;
    }
    
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::TEXT, "../Font/EquinoxRegular.ttf", 45, 10, 20 , 10, "ARCADE", rect));
    id += 1;
}
void Menu::stop()
{
}

std::string Menu::getGameName() const
{
    return "menu";
}
std::vector<std::unique_ptr<IComponent>> & Menu::getComponents()
{
    all_comps[0]->setText("Please enter your Name : " + _playername);
    return (all_comps);
}
void Menu::sendEvents(std::vector<std::unique_ptr<IEvent>> &events)
{
    for (size_t i = 0; i != events.size(); i += 1) {
        if (events[i]->getKey() == KEYBOARD::Enter) {
            Pos b;
            this->event = new Arcade::Event(KEYBOARD::Enter, b, all_comps[game_choice + 2]->getText());
        }
        handle_enter_events(events[i]);
        handle_mouse_events(events[i]);
        handle_name_selection(events[i]);
    }
}

void Menu::handle_enter_events(std::unique_ptr<IEvent> &key)
{
    
    if (key->getKey() == KEYBOARD::Enter)
    {
        int y_red;
        int y_blue;
        std::string game;
        std::string lib;
        for (size_t i = 0; i != all_comps.size(); i += 1)
        {
            if (all_comps[i]->getFile() == "./Sprite/final_red_line")
            {
                y_red = all_comps[i]->getY() - 3;
            }
            if (all_comps[i]->getFile() == "./Sprite/final_blue_line")
            {
                y_blue = all_comps[i]->getY() - 3;
            }
        }

        for (size_t i = 0; i != all_comps.size(); i += 1)
        {
            if (all_comps[i]->getX() == 15 && all_comps[i]->getY() == y_blue) {
                game =  all_comps[i]->getText();
            }
            if (all_comps[i]->getX() == 65 && all_comps[i]->getY() == y_red) {
                lib =  all_comps[i]->getText();
            }
        }
        Pos b;
        this->event = new Arcade::Event(KEYBOARD::Enter, b, "./lib/" + lib + "|" + "./lib/" + game);
    }
}

void Menu::handle_name_selection(std::unique_ptr<IEvent> &key)
{
    if (ALPHABET_EVENT.count((KEYBOARD)key->getKey())) {
        _playername += ALPHABET_EVENT.find((KEYBOARD)key->getKey())->second;
    }
}

void Menu::set_lib_border(int key)
{
    for (size_t i = 0; i != all_comps.size(); i += 1)
    {
        if (all_comps[i]->getFile() == "./Sprite/final_red_line")
        {
            all_comps[i]->setY(key + 3);
        }
    }
}

void Menu::set_game_border(int key)
{
    for (size_t i = 0; i != all_comps.size(); i += 1)
    {
        if (all_comps[i]->getFile() == "./Sprite/final_blue_line")
        {
            all_comps[i]->setY(key + 3);
        }
    }
}

void Menu::handle_mouse_events(std::unique_ptr<IEvent> &key)
{
    
    if (key->getKey() == KEYBOARD::MouseLeft)
    {
        
        int x_key = key->getMousePos().x;
        int y_key = key->getMousePos().y;

        for (size_t i = 0; i != all_comps.size(); i += 1)
        {
            int x_comp = all_comps[i]->getX();
            int y_comp = all_comps[i]->getY();
            int width_comp = all_comps[i]->getWidth();
            int height_comp = all_comps[i]->getHeight();
            if ( (x_key >= x_comp && (x_key <= x_comp + width_comp)) && (y_key >= y_comp && (y_key <= y_comp + height_comp)) && all_comps[i]->getText() != "sprite") {
                if (all_comps[i]->getX() == 65)
                    set_lib_border(all_comps[i]->getY());
                else if (all_comps[i]->getX() == 15)
                    set_game_border(all_comps[i]->getY());
            }
        }     
    }
}

IEvent *Menu::getEvent()
{
    return (event);
} // Get event, null if no event
void Menu::sendDisplayLibs(std::vector<std::string> const libs)
{
    (void)libs;
}
void Menu::sendGameLibs(std::vector<std::string> const libs)
{
    (void)libs;
}
void Menu::setPlayerName(std::string const name)
{
    _playername = name;
}
std::string Menu::getPlayerName() const
{
    return (_playername);
}
