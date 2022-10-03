 /*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "IEvent.hpp"
#include "Core.hpp"

namespace Arcade {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;

            /**
             * @brief Init all elements needed to load a lib
             * 
             */
            virtual void init() = 0;
            /**
             * @brief Stop the lib and free all
             * 
             */
            virtual void stop() = 0;
            /**
             * @brief Get the Lib Name object
             * 
             * @return std::string 
             */
            virtual std::string getLibName() const = 0;
            /**
             * @brief display all the components get as param
             * 
             * @param components 
             */
            virtual void display(std::vector<std::unique_ptr<IComponent>> &components) = 0;
            /**
             * @brief Get the Events object
             * 
             * @return std::vector<std::unique_ptr<IEvent>>& 
             */
            virtual std::vector<std::unique_ptr<IEvent>> &getEvents() = 0;
            /**
             * @brief clear window
             * 
             */
            virtual void clear() = 0; // Clear graphicals object list
    };
}

#endif /* !GRAPHIC_HPP_ */
