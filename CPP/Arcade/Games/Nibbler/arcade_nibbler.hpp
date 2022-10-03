/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Nibbler
*/

#include "../../include/IGame.hpp"
#include "../../Component/Component.hpp"
#include "../../Event/Event.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <chrono>

namespace Arcade
{
    class Nibbler : public IGame {
        public :
            struct Block {
            int pos_x=0;
            int pos_y=0;
            std::string file;
        };

            struct Direction {
                int movex = 0;
                int movey = 0;
            };

            Nibbler();
            ~Nibbler() override;

            void init() override;
            void stop() override;
            [[nodiscard]] std::string getGameName() const override;
            std::vector<std::unique_ptr<IComponent>> &getComponents() override;
            void sendEvents(std::vector<std::unique_ptr<IEvent>> &events) override;
            IEvent *getEvent() override; // Get event, null if no event
            void sendDisplayLibs(std::vector<std::string> libs) override;
            void sendGameLibs(std::vector<std::string> libs) override;
            void setPlayerName(std::string name) override;
            [[nodiscard]] std::string getPlayerName() const override;
            [[nodiscard]] bool checkWall(std::pair<size_t, size_t> val) const;
            [[nodiscard]] bool checkSnake(std::pair<size_t, size_t> val) const;
            void extendSnake();
            void moveSnake();
            void checkIfSnakeOnFood();
            void restartGame();
            enum KEYBOARD {
                    Escape,
                    Left,
                    Right,
                    Down,
                    Up,
                    Space,
                    Enter,
                    A,
                    B,
                    C,
                    D,
                    E,
                    F,
                    G,
                    H,
                    I,
                    J,
                    K,
                    L,
                    M,
                    N,
                    O,
                    P,
                    Q,
                    R,
                    S,
                    T,
                    U,
                    V,
                    W,
                    X,
                    Y,
                    Z
            };
        private :
            const int BLOCK_WIDTH = 5;
            const int BLOCK_HEIGHT = 5;
            const float MOVE_PER_SECOND = 0.2;
            int POINTS = 0;
            int MAP_SIZE = 0;
            int id = 0;
            std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> last_move;
            std::vector<std::unique_ptr<IComponent>> all_comps;
            std::string _playername;
            IEvent *event{};
            std::vector<std::string> _map;
            std::vector <Block> snake;
            std::vector <std::pair<std::size_t, std::size_t>> wall;
            Direction direction;
            std::vector <std::pair<std::size_t, std::size_t>> empty;

    };
}
