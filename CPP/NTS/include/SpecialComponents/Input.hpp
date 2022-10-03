/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Components/IComponent.hpp"
#include "Pins/Pin.hpp"
#include "../Gates/Gates.hpp"

class Input : public nts::IComponent {
    public:
        Input() {pin->set_pin_value(nts::UNDEFINED, 1);};
        ~Input() {};
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() override {return "input";};
        void set_pin_value(nts::Tristate) override;
        std::string get_value() override;
        void updateLinks()
        {
            this->pin->set_pin_value(this->pin->get_Temp_state(), 1);
        };
        std::shared_ptr<Pin> getPin(int index)
        {
            if (index != 1)
                throw Errors("Wrong input pin");
            return (this->pin);
        }
        void setName(std::string name) override
        {
            _name = name;
        };
        std::string getName() const override
        {
            return (_name);
        };
    protected:
        std::shared_ptr<Pin> pin = std::make_shared<Pin>();
        std::string _name;   
    private:
             
};

#endif /* !INPUT_HPP_ */
