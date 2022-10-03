/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** C4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "IComponent.hpp"
#include "Pins/Pin.hpp"
#include "../../include/Gates/Gates.hpp"

class C4069 : public nts::IComponent
{
    public:
        C4069();
        ~C4069();
        void updateLinks() {};
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() override {return "4069";};
        void set_pin_value(nts::Tristate state) override {(void)state;};
        std::string get_value() override {return "C4069Test";};
        std::shared_ptr<Pin> getPin(int index);
        void setName(std::string name) override;
        std::string getName() const override;
    private:
        std::string _name;
        std::map<size_t, std::shared_ptr<Pin>> _pins;
        
};

#endif /* !C4069_HPP_ */
