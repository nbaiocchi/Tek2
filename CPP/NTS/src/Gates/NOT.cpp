/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** AND
*/

#include "../../include/Gates/Gates.hpp"

nts::Tristate Gates::NOT(nts::Tristate a)
{
    if (a == nts::TRUE)
        return (nts::FALSE);
    if (a == nts::FALSE)
        return (nts::TRUE);
    return (nts::UNDEFINED);
}