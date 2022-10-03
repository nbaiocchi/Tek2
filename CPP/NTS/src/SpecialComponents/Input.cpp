/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Input
*/

#include "SpecialComponents/Input.hpp"

void Input::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate Input::compute(std::size_t pin)
{
    (void)pin;
    return (this->getPin(1)->get_pin_value());
}

void Input::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void Input::dump() const
{
    std::cout << "[Dump] Input : " << this->getName() <<  " ";
    std::cout << "[Pin : " << std::to_string(this->pin->get_pin_value()) << "]\n"; 
}

void Input::set_pin_value(nts::Tristate state)
{
    this->pin->set_Temp_state(state);
}

std::string Input::get_value()
{
    if (this->pin->get_pin_value() == nts::UNDEFINED) {
        return "U";
    } else if (this->pin->get_pin_value() == nts::TRUE) {
        return "1";
    } else
        return "0";
}