/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** True
*/

#include "SpecialComponents/True.hpp"

void True::dump() const
{
    std::cout << "[Dump] True : " << this->getName() <<  " ";
    std::cout << "[Pin : " << std::to_string(this->pin->get_pin_value()) << "]\n";
}

std::string True::get_value()
{
    return "1";
}

nts::Tristate True::compute(std::size_t pin)
{
    (void)pin;
    return (nts::Tristate::TRUE);
}