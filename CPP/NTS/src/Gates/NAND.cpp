/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** AND
*/

#include "../../include/Gates/Gates.hpp"

nts::Tristate Gates::NAND(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::TRUE && b == nts::TRUE) {
        return nts::FALSE;
    }
    if ((a == nts::TRUE && b == nts::UNDEFINED) || (a == nts::UNDEFINED && b == nts::TRUE) || (a == nts::UNDEFINED && b == nts::UNDEFINED)) {
        return nts::UNDEFINED;
    }
    return nts::TRUE;
}