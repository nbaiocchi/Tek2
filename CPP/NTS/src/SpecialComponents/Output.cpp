/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim->bengrine
** File description:
** Input
*/

#include "SpecialComponents/Output.hpp"

void Output::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate Output::compute(std::size_t pin)
{
    (void)pin;
    if (this->getPin(1)->getNext()) {
        size_t p = this->getPin(1)->getiPin();
        this->set_pin_value(this->getPin(1)->getNext()->compute(p)); // Compute le pin lié
        return (this->getPin(1)->get_pin_value());
    }
    return (this->getPin(1)->get_pin_value());
}

void Output::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void Output::dump() const
{
    std::cout << "[Dump] Output : " << this->getName() <<  " ";
    std::cout << "[Pin : " << std::to_string(this->pin->get_pin_value()) << " \n"; 
}

void Output::set_pin_value(nts::Tristate state)
{
    this->pin->set_pin_value(state, 1);
}

std::string Output::get_value()
{
    if (this->pin->get_pin_value() == nts::UNDEFINED) {
        return "U";
    } else if (this->pin->get_pin_value() == nts::TRUE) {
        return "1";
    } else
        return "0";
}