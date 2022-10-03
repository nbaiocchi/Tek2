/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Pacman
*/

#ifndef Pacman_HPP_
#define Pacman_HPP_

#include "IGame.hpp"
#include "../Component/Component.hpp"
#include "../Event/Event.hpp"

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
            int pos_x = 0;
            int pos_y = 0;

	};
}

#endif /* !Pacman_HPP_ */
