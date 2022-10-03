/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "Components/IComponent.hpp"

class Pin
{
    public:
        Pin() : _state(nts::UNDEFINED), Temp_state(nts::UNDEFINED), _next(nullptr) {};
        ~Pin() = default;
        nts::Tristate get_pin_value() const {return _state;};
        void set_pin_value(nts::Tristate status, size_t index)
        {
            _state = status;
            if (_next)
                _next->getPin(i_pin)->set_pin_value(status, index);
        };
        void set_i_pin(size_t nb)
        {
            i_pin = nb;
        };
        void update_input()
        {
            _state = Temp_state;
        }
        void set_Temp_state(nts::Tristate new_State)
        {
            Temp_state = new_State;
        }
        nts::Tristate get_Temp_state()
        {
            return (Temp_state);
        }
        std::shared_ptr<nts::IComponent> getNext() {return (_next);}
        size_t getiPin() {return (i_pin);}
        void setNext(std::shared_ptr<nts::IComponent> next) {_next = next;};
    private:
        nts::Tristate _state;
        nts::Tristate Temp_state;
        std::shared_ptr<nts::IComponent> _next;
        size_t i_pin;
};


#endif /* !PIN_HPP_ */
