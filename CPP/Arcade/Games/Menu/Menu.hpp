/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Menu
*/

#include "../../include/IGame.hpp"
#include "../../Component/Component.hpp"
#include "../../Event/Event.hpp"
#include <vector>
#include <dlfcn.h>
#include <map>
#include <ncurses.h>
#include <dirent.h>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <bits/stdc++.h>

namespace Arcade
{
    class Menu : public IGame {
        public :
            Menu();
            ~Menu() override;

            void init() override;
            void stop() override;
            [[nodiscard]] std::string getGameName() const override;
            std::vector<std::unique_ptr<IComponent>> &getComponents() override;
            void sendEvents(std::vector<std::unique_ptr<IEvent>> &events);
            IEvent *getEvent() override; // Get event, null if no event
            void sendDisplayLibs(std::vector<std::string> libs) override;
            void sendGameLibs(std::vector<std::string> libs) override;
            void setPlayerName(std::string name) override;
            [[nodiscard]] std::string getPlayerName() const override;
            enum Tristate {
                GAME,
                GRAPHIC,
                INVALID
            };
            Tristate getType(std::string filepath);
            std::string sanitize_lib_name(std::string filepath);
            void handle_mouse_events(std::unique_ptr<IEvent> &key);
            void handle_enter_events(std::unique_ptr<IEvent> &key);
            void handle_name_selection(std::unique_ptr<IEvent> &key);
            void set_lib_border(int y);
            void set_game_border(int y);
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
                    Z,
                    MouseLeft
            };
        private :
            std::vector<std::unique_ptr<IComponent>> all_comps;
            std::string _playername;
            std::size_t game_choice = 0;
            IEvent *event = nullptr;
            const std::unordered_map<KEYBOARD, char> ALPHABET_EVENT =
                    {
                            {A, 'a'},
                            {B, 'b'},
                            {C, 'c'},
                            {D, 'd'},
                            {E, 'e'},
                            {F, 'f'},
                            {G, 'g'},
                            {H, 'h'},
                            {I, 'i'},
                            {J, 'j'},
                            {K, 'k'},
                            {L, 'l'},
                            {M, 'm'},
                            {N, 'n'},
                            {O, 'o'},
                            {P, 'p'},
                            {Q, 'q'},
                            {R, 'r'},
                            {S, 's'},
                            {T, 't'},
                            {U, 'u'},
                            {V, 'v'},
                            {W, 'w'},
                            {X, 'x'},
                            {Y, 'y'},
                            {Z, 'z'}
                    };
    };
}
