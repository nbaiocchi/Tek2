/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** C4008
*/

#include "../include/Components/C4008.hpp"

C4008::C4008()
{
    for (int i = 0; i != 17; i += 1) {
        this->_pins[i] = std::make_shared<Pin>();
        this->_pins[i]->set_pin_value(nts::UNDEFINED, i);
        this->computed[i] = std::make_shared<Pin>();
        this->computed[i]->set_pin_value(nts::UNDEFINED, i);
    }
}

C4008::~C4008()
{

}

nts::Tristate C4008::compute(std::size_t pin)
{
    if (pin > 16) {
        throw Errors("Wrong pin value entered");
    }
    switch (pin)
    {
    case 10:
        compute_s1(this->compute(7), this->compute(6), this->compute(9));
        return (_pins[10]->get_pin_value());
        break;
    case 11:
        compute_s2(this->compute(5), this->compute(4));
        return (_pins[11]->get_pin_value());
        break;
    case 12:
        compute_s3(this->compute(3), this->compute(2));
        return (_pins[12]->get_pin_value());
        break;
    case 13:
        compute_s4(this->compute(1), this->compute(15));
        return (_pins[13]->get_pin_value());
        break;
    case 14:
        compute_co(this->compute(1), this->compute(15));
        return (_pins[14]->get_pin_value());
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

void C4008::compute_s1(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    _pins[10]->set_pin_value(Gates::XOR(Gates::XOR(a, b), c), 10);

    nts::Tristate ab = Gates::AND(a, b);
    nts::Tristate ac = Gates::AND(a, c);
    nts::Tristate bc = Gates::AND(b, c);

    computed[10]->set_pin_value(Gates::OR(Gates::OR(ab, ac), bc), 10);
}

void C4008::compute_s2(nts::Tristate a, nts::Tristate b)
{
    compute_s1(this->compute(7), this->compute(6), this->compute(9));

    nts::Tristate ab = Gates::AND(a, b);
    nts::Tristate ac = Gates::AND(a, computed[10]->get_pin_value());
    nts::Tristate bc = Gates::AND(b, computed[10]->get_pin_value());

    computed[11]->set_pin_value(Gates::OR(Gates::OR(ab, ac), bc), 11);

    _pins[11]->set_pin_value(Gates::XOR(Gates::XOR(a, b), computed[10]->get_pin_value()), 11);
}

void C4008::compute_s3(nts::Tristate a, nts::Tristate b)
{
    compute_s2(this->compute(5), this->compute(4));

    nts::Tristate ab = Gates::AND(a, b);
    nts::Tristate ac = Gates::AND(a, computed[11]->get_pin_value());
    nts::Tristate bc = Gates::AND(b, computed[11]->get_pin_value());

    computed[12]->set_pin_value(Gates::OR(Gates::OR(ab, ac), bc), 12);

    _pins[12]->set_pin_value(Gates::XOR(Gates::XOR(a, b), computed[11]->get_pin_value()), 12);
}

void C4008::compute_s4(nts::Tristate a, nts::Tristate b)
{
    compute_s3(this->compute(3), this->compute(2));

    nts::Tristate ab = Gates::AND(a, b);
    nts::Tristate ac = Gates::AND(a, computed[12]->get_pin_value());
    nts::Tristate bc = Gates::AND(b, computed[12]->get_pin_value());

    computed[13]->set_pin_value(Gates::OR(Gates::OR(ab, ac), bc), 13);

    _pins[13]->set_pin_value(Gates::XOR(Gates::XOR(a, b), computed[12]->get_pin_value()), 13);
}

void C4008::compute_co(nts::Tristate a, nts::Tristate b)
{
    compute_s4(this->compute(1), this->compute(15));
    nts::Tristate carry = computed[13]->get_pin_value();

    nts::Tristate ab = Gates::AND(a, b);
    nts::Tristate ac = Gates::AND(a, carry);
    nts::Tristate bc = Gates::AND(b, carry);

    _pins[14]->set_pin_value(Gates::OR(Gates::OR(ab, ac), bc), 14);
}

void C4008::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void C4008::dump() const
{    
    std::cout << "[Dump] C4008" << std::endl;
    for (size_t i = 1; i != 14; i += 1) {
        std::cout << "[Pin " + std::to_string(i) + "] ";
        std::cout << this->_pins.at(i)->get_pin_value() << std::endl;
    }
}

void C4008::simulate(std::size_t tick)
{
    (void)tick;
}

std::shared_ptr<Pin> C4008::getPin(int index)
{
    return (this->_pins[index]);
}
void C4008::setName(std::string name)
{
    _name = name;
};
std::string C4008::getName() const
{
    return (_name);
};