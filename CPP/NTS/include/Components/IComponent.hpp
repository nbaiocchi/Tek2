/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#ifndef IComponent_H_
#define IComponent_H_

#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include "Errors/Errors.hpp"
#include <memory>

class Pin;

namespace nts {
    enum  Tristate {
    TRUE = true,
    FALSE = false,
    UNDEFINED = (-true),
    INIT = 2,
};
    class IComponent {
        public:
            virtual ~IComponent() {};
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::string getType() = 0;
            virtual void set_pin_value(nts::Tristate) = 0;
            virtual std::string get_value() = 0;
            virtual std::shared_ptr<Pin> getPin(int index) = 0;
            virtual void updateLinks() = 0;
            virtual void setName(std::string name) = 0;
            virtual std::string getName() const = 0;
        protected:
        private:
            
    };
}

class Factory {
    public:
        Factory();
        ~Factory();
        std::shared_ptr<nts::IComponent>createComponent(const std::string &type);
    protected:
    private:
        std::shared_ptr<nts::IComponent>create4001() const;
        std::shared_ptr<nts::IComponent>create4011() const;
        std::shared_ptr<nts::IComponent>create4030() const;
        std::shared_ptr<nts::IComponent>create4069() const;
        std::shared_ptr<nts::IComponent>create4071() const;
        std::shared_ptr<nts::IComponent>create4081() const;
        std::shared_ptr<nts::IComponent>create4008() const;

        std::shared_ptr<nts::IComponent>createInput() const;
        std::shared_ptr<nts::IComponent>createOutput() const;
        std::shared_ptr<nts::IComponent>createClock() const;
        std::shared_ptr<nts::IComponent>createTrue() const;
        std::shared_ptr<nts::IComponent>createFalse() const;
};


#endif /* !IComponent_H_ */
