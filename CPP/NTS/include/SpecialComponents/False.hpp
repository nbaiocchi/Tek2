/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Input.hpp"

class False : public Input {
    public:
        False() {pin->set_pin_value(nts::FALSE, 1);};
        ~False() {};
        void dump() const override;
        std::string get_value() override;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override {return "false";};
    protected:
    private:
        std::shared_ptr<Pin> pin = std::make_shared<Pin>();
};

#endif /* !FALSE_HPP_ */
