/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Circuit
*/

#include "Circuit/Circuit.hpp"

Circuit::Circuit(const std::string filename)
{
    parser(filename);
    this->_tick = -1;
    stop_loop = true;
}

Circuit::~Circuit()
{
}

void Circuit::display()
{
    std::vector<std::string> input;
    std::vector<std::string> output;

    for (const auto& i : this->all_chips) {
        if (i.second.get()->getType() == "input" || i.second.get()->getType() == "clock") {
            input.push_back(i.first);
        } else if (i.second.get()->getType() == "output") {
            output.push_back(i.first);
        }
    }
    std::cout << "tick: " << std::to_string(_tick) << std::endl;
    std::cout << "input(s):\n";
    for (auto i = input.begin(); i != input.end(); ++i) {
        std::cout << "  " << *i << ": " << this->all_chips.at(*i).get()->get_value() << std::endl;
    }
    std::cout << "output(s):\n";
    for (auto i = output.begin(); i != output.end(); ++i) {
        std::cout << "  " << *i << ": " << this->all_chips.at(*i).get()->get_value() << std::endl;
    }
}

void Circuit::setValue(std::string name, std::string value)
{
    std::map<std::string, std::shared_ptr<nts::IComponent>>::iterator itr;

    itr = all_chips.find(name);
    if (itr != all_chips.end() && (all_chips.at(name)->getType() == "input" || all_chips.at(name)->getType() == "clock")) {
        if (value == "U") {
            all_chips.at(name)->set_pin_value(nts::UNDEFINED);
        } else if (value == "0") {
            all_chips.at(name)->set_pin_value(nts::FALSE);
        } else
            all_chips.at(name)->set_pin_value(nts::TRUE);
    } else {
        throw Errors("Component not found");
    }
}

void Circuit::handle_cmd(std::string command)
{
    if (command == "display") {
        this->display();
    } else if (command == "simulate") {
        this->simulate();
    } else if (command == "loop") {
        this->loop();
    } else if (command == "dump") {
        this->dump();
    }
}

void Circuit::dump() 
{
    std::map<std::string, std::shared_ptr<nts::IComponent>>::iterator it;

    for (it = all_chips.begin(); it != all_chips.end(); it++)
    {
        it->second->dump();
    }
}

void Circuit::simulate()
{
    std::map<std::string, std::shared_ptr<nts::IComponent>>::iterator it;

    for (it = all_chips.begin(); it != all_chips.end(); it++)
    {
        if (it->second->getType() == "input" || it->second->getType() == "clock") {
            it->second->updateLinks();
        }
    }

    for (it = all_chips.begin(); it != all_chips.end(); it++)
    {
        if (it->second->getType() == "output") {
            it->second->compute(1);
        }
    }
    this->_tick += 1;
}

void Circuit::loop()
{
    stop_loop = false;
    std::signal(SIGINT, Circuit::signalHandler);
    while (stop_loop == false) {
        simulate();
        display();
    }
}