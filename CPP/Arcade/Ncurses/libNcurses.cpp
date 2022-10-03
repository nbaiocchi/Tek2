/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** libNcurses
*/

#include "../include/Core.hpp"
#include "../include/libNcurses.hpp"

// const int WIDTH = 900 / 16;
// const int HEIGHT = 901 / 16;

Arcade::libNcurses::libNcurses()
{
	
}

Arcade::libNcurses::~libNcurses()
{
	
}

void Arcade::libNcurses::clear()
{
    werase(window);
}

void Arcade::libNcurses::display(std::vector<std::unique_ptr<IComponent>> &components)
{
    int WIDTH;
    int HEIGHT;
    getmaxyx(window, HEIGHT, WIDTH);
    int count = 0;

    for (size_t i = 0; i != components.size(); i += 1) {
        if (components[i]->getRect().x != 0) {
            continue;
        }
        if (components[i]->getType() == Arcade::IComponent::OBJECT) {
            std::ifstream inputfile(components[i]->getFile() + ".txt");
            std::string line;

            if(inputfile.is_open())
            {
                while (inputfile >> line)
                {
                    mvprintw((components[i]->getY() + count) * HEIGHT / 100, components[i]->getX() * WIDTH / 100, line.c_str());
                    count += 2;
                }
                count = 0;
            }

        } else if (components[i]->getType() == Arcade::IComponent::TEXT) {
            mvprintw(components[i]->getY() * HEIGHT / 100, components[i]->getX()  * WIDTH / 100, components[i]->getText().c_str());
        } else {
            // sound
        }
    }
    wrefresh(window);
};

void Arcade::libNcurses::init()
{
    window = initscr();
    wtimeout(window, 0);
    cbreak();
    keypad(window, TRUE);
	noecho();
    curs_set(FALSE);
    nodelay(window, TRUE);
    mousemask(BUTTON1_PRESSED | BUTTON2_PRESSED, NULL);
};

void Arcade::libNcurses::stop()
{
    keypad(window, false);
    endwin();
};

std::string Arcade::libNcurses::getLibName() const
{
    return "arcade_ncurses.so";
};

std::vector<std::unique_ptr<Arcade::IEvent>> &Arcade::libNcurses::getEvents()
{
    nodelay(window, TRUE);
	int input = getch();
    Arcade::Pos tmp;
    MEVENT event;
    int WIDTH;
    int HEIGHT;
    getmaxyx(window, HEIGHT, WIDTH);
    tmp.x = 0;
    tmp.y = 1;
    timeout(-1);

    this->events.clear();
    switch (input)
    {
        case KEY_MOUSE:
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_PRESSED)
                {
                    tmp.x = event.x * 100 / WIDTH;
                    tmp.y = event.y * 100 / HEIGHT + 10; //harcode because decalage
                    std::cout << tmp.x << " | " << tmp.y << std::endl;
                    this->events.push_back(std::make_unique<Arcade::Event>(33, tmp));
                }
            }
        break;
    }
    if (KEYCODES_TRANSLATION.count(input)) {
        this->events.push_back(std::make_unique<Arcade::Event>(KEYCODES_TRANSLATION.find(input)->second, tmp));
    }
    return (this->events);
};