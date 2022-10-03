/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Pacman
*/

#include "pacman.hpp"

Arcade::Pacman::Pacman()
{

}

Arcade::Pacman::~Pacman()
{

}

void Arcade::Pacman::init()
{
    this->_map.push_back("xxxxxxxxxxxxxxxxxxxxxxxxx");
    this->_map.push_back("x...........x...........x");
    this->_map.push_back("x.xxx.xxxxx.x.xxxxx.xxx.x");
    this->_map.push_back("x.xxx.xxxxx.x.xxxxx.xxx.x");
    this->_map.push_back("x....0......x......0....x");
    this->_map.push_back("x.xxx.xxxxx.x.xxxxx.xxx.x");
    this->_map.push_back("x.x x.x   x.x.x   x.x x.x");
    this->_map.push_back("x.xxx.xxxxx.x.xxxxx.xxx.x");
    this->_map.push_back("x.......................x");
    this->_map.push_back("x.xxx.xxxxxxxxxxxxx.xxx.x");
    this->_map.push_back("x.......................x");
    this->_map.push_back("xxxxxxx.x.xx xx.x.xxxxxxx");
    this->_map.push_back("..........x   x..........");
    this->_map.push_back("xxxxxxx.x.x   x.x.xxxxxxx");
    this->_map.push_back("x.......x.xxxxx.x.......x");
    this->_map.push_back("x.xxxxx...........xxxxx.x");
    this->_map.push_back("x.......x.xxxxx.x.......x");
    this->_map.push_back("x.xxxxxxx.xxxxx.xxxxxxx.x");
    this->_map.push_back("x........0.....0........x");
    this->_map.push_back("x.xxxxxxxxx.x.xxxxxxxxx.x");
    this->_map.push_back("x.x       x.x.x       x.x");
    this->_map.push_back("x.x       x.x.x       x.x");
    this->_map.push_back("x.xxxxxxxxx.x.xxxxxxxxx.x");
    this->_map.push_back("x.......................x");
    this->_map.push_back("xxxxxxxxxxxxxxxxxxxxxxxxx");
    size_t id = 0;
    Rect rect;
    
    std::size_t x = 0;
    std::size_t y = 0;
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/Pacman_Background", 0, 0, 100 , 100, "sprite", rect));
    id += 1;
    for(std::size_t i = 0; i < _map.size(); ++i) {
        for (std::size_t j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == 'x') {
                this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/wall", x, y, 4, 4, "wall", rect));
                wall.push_back({x, y});
            }
            if (_map[i][j] == '0') {
                this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/boost", x, y, 4, 4, "pacgum", rect));
            }
            if (_map[i][j] == '.') {
                this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/pacgum", x, y, 4, 4, "boost", rect));
                pacGum.push_back(all_comps.size() - 1);
            }
            x += 4;
            id += 1;
        }
        x = 0;
        y += 4;
    }
    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/pac", 49, 61, 2, 3, "sprite", rect));
    this->idPac = all_comps.size() - 1;
}

void Arcade::Pacman::stop()
{
    
}

void Arcade::Pacman::set_map()
{

}

std::string Arcade::Pacman::getGameName() const
{
    return "pacman";
}

std::vector<std::unique_ptr<Arcade::IComponent>> &Arcade::Pacman::getComponents()
{
    return (all_comps);
}

void Arcade::Pacman::sendEvents(std::vector<std::unique_ptr<IEvent>> &events)
{
    int x = all_comps[idPac]->getX();
    int y = all_comps[idPac]->getY();


    for (size_t i = 0; i != events.size(); i += 1) {
        if (events[i]->getKey() == KEYBOARD::Up) {
            if (check_coli_up(x, y))
                all_comps[idPac]->setY(y - 1);
        }
        if (events[i]->getKey() == KEYBOARD::Down) {
            if (check_coli_down(x, y))
                all_comps[idPac]->setY(y + 1);
        }
        if (events[i]->getKey() == KEYBOARD::Left) {
            if (check_coli_left(x, y))
                all_comps[idPac]->setX(x - 1);
            if (x < 1) {
                all_comps[idPac]->setX(99);
            }
        }
        if (events[i]->getKey() == KEYBOARD::Right) {
            if (check_coli_right(x, y))
                all_comps[idPac]->setX(x + 1);
            if (x > 99) {
                all_comps[idPac]->setX(1);
            }
        }
    }
    check_pacgum(x, y);
}

void Arcade::Pacman::check_pacgum(int x, int y)
{
    Rect rect;
    rect.x = 77;

    for (size_t w = 0; w != all_comps.size(); ++w)
    {
        if (all_comps[w]->getFile() == "./Sprite/pacgum")
        {
            int gum_x = all_comps[w]->getX();
            int gum_y = all_comps[w]->getY();

            if (abs(gum_x - x + 1) <= 2 && abs(gum_y - y + 1)  <= 2)
            {
                all_comps[w]->setRect(rect);
                
            }
            
        }    
    }
}

bool Arcade::Pacman::check_coli_up(int x, int y)
{
    for (auto &w: wall) {
        if ((x > w.first && x < w.first + 4 && y <= w.second + 4 && y >= w.second) ||
            (x + 2 > w.first && x + 2 < w.first + 4 && y <= w.second + 4 && y >= w.second)) {
            return false;
        }
    }
    return true;
}

bool Arcade::Pacman::check_coli_down(int x, int y)
{
    for (auto &w: wall) {
        if ((x > w.first && x < w.first + 4 && y + 3 <= w.second + 4 && y + 3 >= w.second) ||
            (x + 2 > w.first && x + 2 < w.first + 4 && y + 3 <= w.second + 4 && y + 3 >= w.second)) {
            return false;
        }
    }
    return true;
}

bool Arcade::Pacman::check_coli_left(int x, int y)
{
    for (auto &w: wall) {
        if ((x >= w.first && x <= w.first + 4 && y + 3 < w.second + 4 && y + 3 > w.second) ||
            (x >= w.first && x <= w.first + 4 && y < w.second + 4 && y > w.second)) {
            return false;
        }
    }
    return true;
}

bool Arcade::Pacman::check_coli_right(int x, int y)
{
    for (auto &w: wall) {
        if ((x + 2 >= w.first && x + 2 <= w.first + 4 && y + 3 < w.second + 4 && y + 3 > w.second) ||
            (x + 2 >= w.first && x + 2 <= w.first + 4 && y < w.second + 4 && y > w.second)) {
            return false;
        }
    }
    return true;
}

Arcade::IEvent *Arcade::Pacman::getEvent()
{
    return (event);
}

void Arcade::Pacman::sendDisplayLibs(std::vector<std::string> libs)
{
    (void)libs; 
}

void Arcade::Pacman::sendGameLibs(std::vector<std::string> libs)
{
    (void)libs;
}

void Arcade::Pacman::setPlayerName(std::string name)
{
    (void)name;
}

std::string Arcade::Pacman::getPlayerName() const
{
    return "";
}

// extern "C" {
//     void *LoadLib() {
//         Arcade::Pacman *a = new Arcade::Pacman();
//         return(a);
//     }
// }