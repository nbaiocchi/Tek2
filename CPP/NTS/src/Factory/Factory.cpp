/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Factory
*/

#include "../../include/Components/all_comps.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

std::shared_ptr<nts::IComponent> Factory::createComponent(const std::string &type)
{
    if (type == "input")
        return (createInput());
    if (type == "output")
        return (createOutput());
    if (type == "true")
        return (createTrue());
    if (type == "false")
        return (createFalse());
    if (type == "clock")
        return (createClock());
    if (type == "4071")
        return (create4071());
    if (type == "4001")
        return (create4001());
    if (type == "4011")
        return (create4011());
    if (type == "4030")
        return (create4030());
    if (type == "4081")
        return (create4081());
    if (type == "4069")
        return (create4069());
    if (type == "4008")
        return (create4008());

    throw Errors("Errors while creating Component");
}

std::shared_ptr<nts::IComponent> Factory::create4001() const
{
    return (std::make_shared<C4001>());
}

std::shared_ptr<nts::IComponent> Factory::create4011() const
{
    return (std::make_shared<C4011>());
}

std::shared_ptr<nts::IComponent> Factory::create4030() const
{
    return (std::make_shared<C4030>());
}

std::shared_ptr<nts::IComponent> Factory::create4069() const
{
    return (std::make_shared<C4069>());
}

std::shared_ptr<nts::IComponent> Factory::create4071() const
{
    return (std::make_shared<C4071>());
}

std::shared_ptr<nts::IComponent> Factory::create4081() const
{
    return (std::make_shared<C4081>());
}

std::shared_ptr<nts::IComponent> Factory::create4008() const
{
    return (std::make_shared<C4008>());
}

std::shared_ptr<nts::IComponent> Factory::createInput() const
{
    return (std::make_shared<Input>());
}

std::shared_ptr<nts::IComponent> Factory::createOutput() const
{
    return (std::make_shared<Output>());
}

std::shared_ptr<nts::IComponent> Factory::createClock() const
{
    return (std::make_shared<Clock>());
}

std::shared_ptr<nts::IComponent> Factory::createTrue() const
{
    return (std::make_shared<True>());
}

std::shared_ptr<nts::IComponent> Factory::createFalse() const
{
    return (std::make_shared<False>());
}


