/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Input.hpp"

class Clock : public Input {
    public:
        Clock() {pin->set_pin_value(nts::UNDEFINED, 1);};
        ~Clock() {};
        void dump() const override;
        std::string get_value() override;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override {return "clock";};
        std::shared_ptr<Pin> getPin(int index)
        {
            if (index != 1)
                throw Errors("Wrong input pin");
            return (this->pin);
        }
    protected:
    private:
};

#endif /* !CLOCK_HPP_ */
