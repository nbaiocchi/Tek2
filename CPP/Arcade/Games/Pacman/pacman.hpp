/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Pacman
*/

#ifndef Pacman_HPP_
#define Pacman_HPP_

#include "../../include/IGame.hpp"
#include "../../Component/Component.hpp"
#include "../../Event/Event.hpp"

namespace Arcade {
	class Pacman : public IGame
	{
		public:
		Pacman();
		~Pacman() override;

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
		private:
            std::vector<std::unique_ptr<IComponent>> all_comps;
            IEvent *event = nullptr;
            void set_map();
            std::vector<std::string> _map;
            int idPac = 0;
            std::vector <std::pair<int, int>> wall;
            std::vector <int> pacGum;
            bool check_coli_up(int, int);
            bool check_coli_down(int, int);
            bool check_coli_left(int, int);
            bool check_coli_right(int, int);
            void check_pacgum(int, int);
	};
}

#endif /* !Pacman_HPP_ */
