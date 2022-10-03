/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** Input
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "Components/IComponent.hpp"
#include "Pins/Pin.hpp"

class Output : public nts::IComponent {
    public:
        Output() {pin->set_pin_value(nts::UNDEFINED, 1);};
        ~Output() {};
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() override {return "output";};
        void set_pin_value(nts::Tristate) override;
        /* je n'arrive pas a faire un set_output_value */
        void updateLinks() {};
        std::string get_value() override;
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
    private:
        std::string _name;
        std::shared_ptr<Pin> pin = std::make_shared<Pin>();
};

#endif /* !OUTPUT_HPP_ */
