/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <csignal>
#include "Components/IComponent.hpp"
#include "Utils/Utils.hpp"

static bool stop_loop;

class Circuit {
    public:
        Circuit(const std::string filename);
        ~Circuit();

        void exit();
        void display();
        void simulate();
        static void signalHandler(int)
        {
            stop_loop = true;  
        }
        void loop();
        void dump();
        void setLinks();
        void setValue(std::string name, std::string value);
        void handle_cmd(std::string);
        
    protected:
    private:
        std::map<std::string, std::shared_ptr<nts::IComponent>> all_chips;
        Factory _factory;
        void parser(const std::string filename);
        void take_map(std::string content);
        size_t _tick;
        void take_links(std::string content);
};

#endif /* !CIRCUIT_HPP_ */
