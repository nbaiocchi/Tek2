/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "IComponent.hpp"
#include "Pins/Pin.hpp"
#include "../../include/Gates/Gates.hpp"

class C4008 : public nts::IComponent
{
    public:
        C4008();
        ~C4008();
        void updateLinks() {};
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() override {return "4008";};
        void set_pin_value(nts::Tristate state) override {(void)state;};
        std::string get_value() override {return "C4008Test";};
        std::shared_ptr<Pin> getPin(int index);
        void setName(std::string name) override;
        std::string getName() const override;
    private:
        std::string _name;
        std::map<size_t, std::shared_ptr<Pin>> _pins;
        std::map<size_t, std::shared_ptr<Pin>> computed;
        void compute_s1(nts::Tristate a, nts::Tristate b, nts::Tristate c);
        void compute_s2(nts::Tristate a, nts::Tristate b);
        void compute_s3(nts::Tristate a, nts::Tristate b);
        void compute_s4(nts::Tristate a, nts::Tristate b);
        void compute_co(nts::Tristate a, nts::Tristate b);
        
};

#endif /* !C4008_HPP_ */
