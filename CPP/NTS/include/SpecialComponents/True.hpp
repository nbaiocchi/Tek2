/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Input.hpp"

class True : public Input {
    public:
        True() {pin->set_pin_value(nts::TRUE, 1); pin->set_Temp_state(nts::TRUE);};
        ~True() {};
        void dump() const override;
        std::string get_value() override;
        nts::Tristate compute(std::size_t pin) override;
        std::string getType() override {return "true";};
    protected:
    private:
        std::shared_ptr<Pin> pin = std::make_shared<Pin>();
        
};

#endif /* !TRUE_HPP_ */
