/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "../include/IEvent.hpp"

namespace Arcade {
    class Event : public IEvent
    {
        public:
            Event(size_t key, Pos pos);
            Event(size_t key, Pos pos, std::string data);
            ~Event() override;

            [[nodiscard]] std::size_t getKey() const override;   // Get key
            void setKey(std::size_t key) override;   // Set key
            [[nodiscard]] Pos getMousePos() const override;  // Get mouse pos
            [[nodiscard]] std::string getData() const override;    // Get event text data
        protected:
        private:
            size_t _key;
            Pos _pos{};
            std::string _data;
    };
}

#endif /* !EVENT_HPP_ */
