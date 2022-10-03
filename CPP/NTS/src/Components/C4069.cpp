/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** C4069
*/

#include "../include/Components/C4069.hpp"

C4069::C4069()
{
    for (int i = 0; i != 15; i += 1) {
        this->_pins[i] = std::make_shared<Pin>();
        this->_pins[i]->set_pin_value(nts::UNDEFINED, i);
    }
}

C4069::~C4069()
{

}

nts::Tristate C4069::compute(std::size_t pin)
{
    if (pin > 14) {
        throw Errors("Wrong pin value entered");
    }
    switch (pin)
    {
    case 2:
        _pins[2]->set_pin_value(Gates::NOT(this->compute(1)), 2);
        return (_pins[2]->get_pin_value());
        break;
    case 4:
        _pins[4]->set_pin_value(Gates::NOT(this->compute(3)), 4);
        return (_pins[4]->get_pin_value());
        break;
    case 6:
        _pins[6]->set_pin_value(Gates::NOT(this->compute(5)), 6);
        return (_pins[6]->get_pin_value());
        break;
    case 8:
        _pins[8]->set_pin_value(Gates::NOT(this->compute(9)), 8);
        return (_pins[8]->get_pin_value());
        break;
    case 10:
        _pins[10]->set_pin_value(Gates::NOT(this->compute(11)), 10);
        return (_pins[10]->get_pin_value());
        break;
    case 12:
        _pins[12]->set_pin_value(Gates::NOT(this->compute(13)), 12);
        return (_pins[12]->get_pin_value());
        break;
    default:
        if (this->_pins[pin]->getNext()) {
            size_t p = this->_pins[pin]->getiPin();
            this->_pins[pin]->set_pin_value(this->_pins[pin]->getNext()->compute(p), pin);
            return (_pins[pin]->get_pin_value());
        }
        return (_pins[pin]->get_pin_value());
        break;
    }
    return (nts::FALSE);
}

void C4069::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void C4069::dump() const
{    
    std::cout << "[Dump] C4069 : " << this->getName() << " \n";
    for (size_t i = 1; i != 15; i += 1) {
        std::cout << "[Pin " + std::to_string(i) + "] ";
        std::cout << this->_pins.at(i)->get_pin_value() << std::endl;
    }
}

void C4069::simulate(std::size_t tick)
{
    (void)tick;
}

std::shared_ptr<Pin> C4069::getPin(int index)
{
    return (this->_pins[index]);
}
void C4069::setName(std::string name)
{
    _name = name;
};
std::string C4069::getName() const
{
    return (_name);
};