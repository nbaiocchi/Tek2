/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** AND
*/

#include "../../include/Gates/Gates.hpp"

nts::Tristate Gates::XOR(nts::Tristate a, nts::Tristate b)
{
    if ((a == nts::FALSE && b == nts::TRUE) || (a == nts::TRUE && b == nts::FALSE)) {
        return nts::TRUE;
    }
    if ((a == nts::FALSE && b == nts::FALSE) || (a == nts::TRUE && b == nts::TRUE)) {
        return nts::FALSE;
    }
    return nts::UNDEFINED;
}