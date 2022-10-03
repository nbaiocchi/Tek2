/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** C4001
*/

#include "../include/Components/C4001.hpp"

C4001::C4001()
{
    for (int i = 0; i != 15; i += 1) {
        this->_pins[i] = std::make_shared<Pin>();
        this->_pins[i]->set_pin_value(nts::UNDEFINED, i);
    }
}

C4001::~C4001()
{

}

nts::Tristate C4001::compute(std::size_t pin)
{
    if (pin > 14) {
        throw Errors("Wrong pin value entered");
    }
    // std::cout << "PIN : " << std::to_string(pin) << std::endl;
    switch (pin)
    {
    case 3:
        _pins[3]->set_pin_value(Gates::NOR(this->compute(1), this->compute(2)), 3);
        return (_pins[3]->get_pin_value());
        break;
    case 4:
        _pins[4]->set_pin_value(Gates::NOR(this->compute(5), this->compute(6)), 4);
        return (_pins[4]->get_pin_value());
        break;
    case 10:

        _pins[10]->set_pin_value(Gates::NOR(this->compute(8), this->compute(9)), 10);
        return (_pins[10]->get_pin_value());
        break;
    case 11:
        _pins[11]->set_pin_value(Gates::NOR(this->compute(12), this->compute(13)), 11);
        return (_pins[11]->get_pin_value());
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

void C4001::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void C4001::dump() const
{    
    std::cout << "[Dump] C4001 : " << this->getName() << " \n";
    for (size_t i = 1; i != 15; i += 1) {
        std::cout << "[Pin " + std::to_string(i) + "] ";
        std::cout << this->_pins.at(i)->get_pin_value() << std::endl;
    }
}

void C4001::simulate(std::size_t tick)
{
    (void)tick;
}

std::shared_ptr<Pin> C4001::getPin(int index)
{
    return (this->_pins[index]);
}
void C4001::setName(std::string name)
{
    _name = name;
};
std::string C4001::getName() const
{
    return (_name);
};