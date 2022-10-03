/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** False
*/

#include "SpecialComponents/False.hpp"

void False::dump() const
{
    std::cout << "[Dump] False : " << this->getName() <<  " ";
    std::cout << "[Pin : " << std::to_string(this->pin->get_pin_value()) << "]\n";
}

std::string False::get_value()
{
    return "1";
}

nts::Tristate False::compute(std::size_t pin)
{
    (void)pin;
    return (nts::Tristate::FALSE);
}