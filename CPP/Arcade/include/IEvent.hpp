/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IEvent
*/

#ifndef IEVENT_HPP
#define IEVENT_HPP

#include <string>

namespace Arcade {
    struct Pos {
        int x;
        int y;
    };
    class IEvent {
        public:
            virtual ~IEvent() = default;

            /**
             * @brief Get the Key object
             * 
             * @return std::size_t 
             */
            [[nodiscard]] virtual std::size_t getKey() const = 0;
            /**
             * @brief Set the Key object
             * 
             * @param key 
             */
            virtual void setKey(std::size_t key) = 0;
            /**
             * @brief Get the Mouse Pos object
             * 
             * @return Pos 
             */
            [[nodiscard]] virtual Pos getMousePos() const = 0;
            /**
             * @brief Get the Data object
             * 
             * @return std::string 
             */
            [[nodiscard]] virtual std::string getData() const = 0;
    };
}

#endif /* !ICOMPONENT_HPP */
