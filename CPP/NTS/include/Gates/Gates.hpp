/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "../Components/IComponent.hpp"

namespace Gates {
    nts::Tristate OR(nts::Tristate first, nts::Tristate second);
    nts::Tristate AND(nts::Tristate first, nts::Tristate second);
    nts::Tristate NOR(nts::Tristate first, nts::Tristate second);
    nts::Tristate NAND(nts::Tristate first, nts::Tristate second);
    nts::Tristate XOR(nts::Tristate first, nts::Tristate second);
    nts::Tristate XNOR(nts::Tristate first, nts::Tristate second);
    nts::Tristate NOT(nts::Tristate first);
}

#endif /* !GATES_HPP_ */
