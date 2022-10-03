/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Nibbler
*/

#include "arcade_nibbler.hpp"

namespace Arcade {
    Nibbler::Nibbler()
    {
        snake = {
                {11 * BLOCK_WIDTH, 7 * BLOCK_HEIGHT, "./Sprite/head"},
                {11 * BLOCK_WIDTH, 8 * BLOCK_HEIGHT, "./Sprite/body"},
                {11 * BLOCK_WIDTH, 9 * BLOCK_HEIGHT, "./Sprite/body"},
                {11 * BLOCK_WIDTH, 10 * BLOCK_HEIGHT, "./Sprite/body"}};
        direction = {0, -BLOCK_HEIGHT};
    }

    Nibbler::~Nibbler()
    = default;

    void Nibbler::init()
    {
        srand(time(nullptr));
        int food = 0;
        std::string path = "./lib";
        std::size_t x = 0;
        std::size_t y = 0;
        Rect rect;

        this->_map.emplace_back("xxxxxxxxxxxxxxxxxxxx");
        this->_map.emplace_back("x          x       x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x xx x   xxx   xxx x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("xxxx           x   x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x       x          x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x      xxx xxx     x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x        xxx       x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x                  x");
        this->_map.emplace_back("x        xxx       x");
        this->_map.emplace_back("x        xxx       x");
        this->_map.emplace_back("xxxxxxxxxxxxxxxxxxxx");

        this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/NibblerBackground", 0, 0, 100 , 100, "sprite", rect));

        id += 1;
        for(auto & i : _map) {
            for (char j : i) {
                if (j == 'x') {
                    wall.emplace_back(x, y);
                    this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/wall", x, y, BLOCK_WIDTH, BLOCK_HEIGHT, "wall", rect));
                } else {
                    empty.emplace_back(x, y);
                }
                x += BLOCK_WIDTH;
            }
            x = 0;
            y += BLOCK_HEIGHT;
            id += 1;
        }
        this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::TEXT, "../Font/EquinoxRegular.ttf", 120, 20, 800 , 100, "Please enter your Name :", rect));
        this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::TEXT, "../Font/EquinoxRegular.ttf", 120, 70, 800 , 200, "Points :" + std::to_string(POINTS), rect));

        do {
            food = rand() % empty.size();
        } while (empty[food].first != (std::size_t) 11 * BLOCK_WIDTH && empty[food].second < (std::size_t)7 * BLOCK_HEIGHT && empty[food].second > (std::size_t)10 * BLOCK_HEIGHT);
        this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT, "./Sprite/food", empty[food].first, empty[food].second, BLOCK_WIDTH, BLOCK_HEIGHT, "food", rect));
        MAP_SIZE = this->all_comps.size();
        this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT,
                                                              snake[0].file,
                                                              snake[0].pos_x,
                                                              snake[0].pos_y,
                                                              BLOCK_WIDTH,
                                                              BLOCK_HEIGHT,
                                                              "sprite", rect));
        for (std::size_t i = 1; i < snake.size(); i += 1) {
            this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT,
                                                                  snake[i].file,
                                                                  snake[i].pos_x,
                                                                  snake[i].pos_y,
                                                                  BLOCK_WIDTH,
                                                                  BLOCK_HEIGHT,
                                                                  "sprite", rect));
        }
        last_move = std::chrono::system_clock::now();
    }

    void Nibbler::stop()
    {
    }

    std::string Nibbler::getGameName() const
    {
        return "Nibbler";
    }

    std::vector<std::unique_ptr<IComponent>> & Nibbler::getComponents()
    {
        std::size_t x = all_comps[MAP_SIZE]->getX();
        std::size_t y = all_comps[MAP_SIZE]->getY();

        if ((float)(std::chrono::system_clock::now() - last_move).count() / (float)(CLOCKS_PER_SEC * 1000) > MOVE_PER_SECOND) {
            if (checkWall(std::pair<std::size_t, std::size_t>
                                  {x + direction.movex, y + direction.movey}) &&
                checkSnake(std::pair<std::size_t, std::size_t>
                                   {x + direction.movex, y + direction.movey})) {
                moveSnake();
                all_comps[MAP_SIZE]->setX(x + direction.movex);
                all_comps[MAP_SIZE]->setY(y + direction.movey);
                checkIfSnakeOnFood();
                last_move = std::chrono::system_clock::now();
            } else {
                this->restartGame();
                this->init();
            }
        }
        return (all_comps);
    }

    void Nibbler::sendEvents(std::vector<std::unique_ptr<IEvent>> &events)
    {
        for (size_t i = 0; i != events.size(); i += 1) {
            if (events[i]->getKey() == KEYBOARD::Up)
                    direction = {0, -BLOCK_HEIGHT};
            if (events[i]->getKey() == KEYBOARD::Down)
                    direction = {0, BLOCK_HEIGHT};
            if (events[i]->getKey() == KEYBOARD::Left)
                    direction = {-BLOCK_WIDTH, 0};
            if (events[i]->getKey() == KEYBOARD::Right)
                    direction = {BLOCK_WIDTH, 0};
        }
    }

    IEvent *Nibbler::getEvent()
    {
        return (event);
    } // Get event, null if no event
    void Nibbler::sendDisplayLibs(std::vector<std::string> const libs)
    {
        (void)libs;
    }

    void Nibbler::sendGameLibs(std::vector<std::string> const libs)
    {
        (void)libs;
    }

    void Nibbler::setPlayerName(std::string const name)
    {
        _playername = name;
    }
    std::string Nibbler::getPlayerName() const
    {
        return (_playername);
    }

    void Nibbler::moveSnake() {
        for (int j = MAP_SIZE + snake.size() - 1; j > MAP_SIZE; j -= 1) {
            all_comps[j]->setX(all_comps[j - 1]->getX());
            all_comps[j]->setY(all_comps[j - 1]->getY());
        }
    }

    bool Nibbler::checkWall(std::pair<size_t, size_t> val) const {
        for (std::size_t i = 0; i < wall.size(); i += 1) {
            if (wall[i].first == val.first && wall[i].second == val.second) {
                return false;
            }
        }
        return true;
    }

    bool Nibbler::checkSnake(std::pair<size_t, size_t> val) const {
        for (std::size_t i = snake.size() - 1; i < snake.size() + 1; i -= 1) {
            if ((std::size_t)all_comps[MAP_SIZE + i]->getX() == val.first && (std::size_t)all_comps[MAP_SIZE + i]->getY() == val.second) {
                return false;
            }
        }
        return true;
    }

    void Nibbler::extendSnake() {

        Rect rect;

        int pos_x = all_comps[MAP_SIZE + snake.size() - 1]->getX();
        int pos_y = all_comps[MAP_SIZE + snake.size() - 1]->getY();
        std::size_t len = snake.size();

        if (checkWall(std::pair<std::size_t, std::size_t>
        {pos_x + BLOCK_WIDTH, pos_y}) &&
        checkSnake(std::pair<std::size_t, std::size_t>
        {pos_x + BLOCK_WIDTH, pos_y})) {

            snake.push_back({pos_x + BLOCK_WIDTH, pos_y,"./Sprite/body"});

        } else if (checkWall(std::pair<std::size_t, std::size_t>
        {pos_x - BLOCK_WIDTH, pos_y}) &&
        checkSnake(std::pair<std::size_t, std::size_t>
        {pos_x - BLOCK_WIDTH, pos_y})) {

            snake.push_back({pos_x - BLOCK_WIDTH, pos_y, "./Sprite/body"});

        } else if (checkWall(std::pair<std::size_t, std::size_t>
        {pos_x, pos_y + BLOCK_HEIGHT}) &&
        checkSnake(std::pair<std::size_t, std::size_t>
        {pos_x, pos_y + BLOCK_HEIGHT})) {

            snake.push_back({pos_x, pos_y + BLOCK_HEIGHT, "./Sprite/body"});

        } else if (checkWall(std::pair<std::size_t, std::size_t>
        {pos_x, pos_y - BLOCK_HEIGHT}) &&
        checkSnake(std::pair<std::size_t, std::size_t>
        {pos_x, pos_y - BLOCK_HEIGHT})) {

            snake.push_back({pos_x, pos_y - BLOCK_HEIGHT, "./Sprite/body"});

        }
        if (len != snake.size()) {
            this->all_comps.push_back(std::make_unique<Component>(id, IComponent::Type::OBJECT,
                                                                  snake[snake.size() - 1].file,
                                                                  snake[snake.size() - 1].pos_x,
                                                                  snake[snake.size() - 1].pos_y,
                                                                  BLOCK_WIDTH,
                                                                  BLOCK_HEIGHT,
                                                                  "sprite", rect));
        }
    }

    void Nibbler::checkIfSnakeOnFood() {
        int food = 0;
        if (all_comps[MAP_SIZE]->getX() == all_comps[MAP_SIZE - 1]->getX() &&
        all_comps[MAP_SIZE]->getY() == all_comps[MAP_SIZE - 1]->getY()) {
            POINTS += 1;
            extendSnake();
            all_comps[MAP_SIZE - 2]->setText("Points: " + std::to_string(POINTS));
            do {
                food = rand() % empty.size();
            } while (!checkSnake(std::pair<std::size_t, std::size_t>(empty[food].first, empty[food].second)));
            all_comps[MAP_SIZE - 1]->setX(empty[food].first);
            all_comps[MAP_SIZE - 1]->setY(empty[food].second);
        }
    }

    void Nibbler::restartGame() {
        all_comps.clear();
        wall.clear();
        empty.clear();
        _map.clear();
        POINTS = 0;
        id = 0;
        snake = {
                {11 * BLOCK_WIDTH, 7 * BLOCK_HEIGHT, "./Sprite/head"},
                {11 * BLOCK_WIDTH, 8 * BLOCK_HEIGHT, "./Sprite/body"},
                {11 * BLOCK_WIDTH, 9 * BLOCK_HEIGHT, "./Sprite/body"},
                {11 * BLOCK_WIDTH, 10 * BLOCK_HEIGHT, "./Sprite/body"}};
        direction = {0, -BLOCK_HEIGHT};
    }
}
