/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Clock
*/

#include "SpecialComponents/Clock.hpp"

void Clock::dump() const
{
    std::cout << "[Dump] Clock : " << this->getName() <<  " ";
    std::cout << "[Pin : " << std::to_string(this->pin->get_pin_value()) << "]\n";
}

std::string Clock::get_value()
{
    if (this->pin->get_pin_value() == nts::UNDEFINED) {
        return "U";
    } else if (this->pin->get_pin_value() == nts::TRUE) {
        return "1";
    } else
        return "0";
}

nts::Tristate Clock::compute(std::size_t pin)
{
    (void)pin;
    nts::Tristate _prev = this->getPin(1)->get_pin_value();
    nts::Tristate _new = Gates::NOT(_prev);
    this->set_pin_value(_new);
    return(_prev);
}