/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP
#define IGAME_HPP

#include <vector>
#include <memory>
#include <string>

#include "IComponent.hpp"
#include "IEvent.hpp"

namespace Arcade {
    /**
     * @brief IGame class
     * 
     */
    class IGame {
        public:
            virtual ~IGame() = default;
            /**
             * @brief Init all elements needed to load the game
             * 
             */
            virtual void init() = 0;
            /**
             * @brief Stop the game and free all
             * 
             */
            virtual void stop() = 0;
            /**
             * @brief Get the Game Name object
             * 
             * @return std::string 
             */
            [[nodiscard]] virtual std::string getGameName() const = 0;
            /**
             * @brief Get the Components object
             * 
             * @return std::vector<std::unique_ptr<IComponent>>& 
             */
            virtual std::vector<std::unique_ptr<IComponent>> &getComponents() = 0;
            /**
             * @brief send events from game to the core
             * 
             * @param events 
             */
            virtual void sendEvents(std::vector<std::unique_ptr<IEvent>> &events) = 0;
            /**
             * @brief Get all the Events 
             * 
             * @return IEvent* 
             */
            virtual IEvent *getEvent() = 0;
            /**
             * @brief send display libs
             * 
             * @param libs 
             */
            virtual void sendDisplayLibs(std::vector<std::string> libs) = 0;
            /**
             * @brief send the actual lib game
             * 
             * @param libs 
             */
            virtual void sendGameLibs(std::vector<std::string> libs) = 0;
            /**
             * @brief Set the Player Name object
             * 
             * @param name 
             */
            virtual void setPlayerName(std::string name) = 0;
            /**
             * @brief Get the Player Name object
             * 
             * @return std::string 
             */
            [[nodiscard]] virtual std::string getPlayerName() const = 0;
    };
}

#endif /* !IGAME_HPP */
