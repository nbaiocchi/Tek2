/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** AND
*/

#include "../../include/Gates/Gates.hpp"

nts::Tristate Gates::NOR(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::FALSE && b == nts::FALSE) {
        return nts::TRUE;
    }
    if ((a == nts::FALSE && b == nts::UNDEFINED) || (a == nts::UNDEFINED && b == nts::FALSE) || (a == nts::UNDEFINED && b == nts::UNDEFINED)) {
        return nts::UNDEFINED;
    }
    return nts::FALSE;
}
