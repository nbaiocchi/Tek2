/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <string>
#include <iostream>
#include <filesystem>
// #include "../Errors/Errors.hpp"

// Namespace Arcade to organise the code
//
namespace Arcade {

    struct Rect {
        int x = 0;
        int y = 0;
        int width = 0;
        int height = 0;
    };
    /**
     * @brief IComponent class
     * 
     */
    class IComponent {
        public:
            /**
             * @brief enum to differentiate object than sound and text at the display
             * 
             */
            enum Type {
                OBJECT,
                SOUND,
                TEXT
            };
            virtual ~IComponent() = default;
            /**
             * @brief Get the Id object
             * 
             * @return std::size_t 
             */
            [[nodiscard]] virtual std::size_t getId() const = 0;
            /**
             * @brief Get the Type object
             * 
             * @return Type 
             */
            [[nodiscard]] virtual Type getType() const = 0;
            /**
             * @brief Get the File object
             * 
             * @return std::string 
             */
            [[nodiscard]] virtual std::string getFile() const = 0;
            /**
             * @brief Get X position (OBJECT/TEXT)
             * 
             * @return int 
             */
            [[nodiscard]] virtual int getX() const = 0;
            /**
             * @brief Get Y position (OBJECT/TEXT)
             * 
             * @return int 
             */
            [[nodiscard]] virtual int getY() const = 0;
            /**
             * @brief Get the Width object
             * 
             * @return int 
             */
            [[nodiscard]] virtual int getWidth() const = 0;
            /**
             * @brief Get the Height object
             * 
             * @return int 
             */
            [[nodiscard]] virtual int getHeight() const = 0;
            /**
             * @brief Get the Rect object
             * 
             * @return Rect 
             */
            [[nodiscard]] virtual Rect getRect() const = 0;
            /**
             * @brief Get the Text object
             * 
             * @return std::string 
             */
            [[nodiscard]] virtual std::string getText() const = 0;
            /**
             * @brief set x position (OBJECT/TEXT)
             * 
             * @param x 
             */
            virtual void setX(std::size_t const x) = 0;
            /**
             * @brief set x position (OBJECT/TEXT)
             * 
             * @param y 
             */
            virtual void setY(std::size_t const y) = 0;
            /**
             * @brief Set the Text object
             * 
             * @param text 
             */
            virtual void setText(std::string const text) = 0;
            /**
             * @brief Set the Rect object
             * 
             * @param rect 
             */
            virtual void setRect(Rect const rect) = 0;
    };
}

#endif /* !ICOMPONENT_HPP */
