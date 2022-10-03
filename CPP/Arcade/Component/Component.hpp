/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Component
*/

#include "../include/IComponent.hpp"

namespace Arcade {
    class Component : public IComponent
    {
        public :
            Component(std::size_t id, Type, std::string file, int x, int y, int width, int height, std::string text, Arcade::Rect rect);
            [[nodiscard]] std::size_t getId() const override;   // Get component ID
            [[nodiscard]] Type getType() const override;   // Get component type
            [[nodiscard]] std::string getFile() const override;    // Get file associated with component
            [[nodiscard]] int getX() const override;   // Get X position (OBJECT/TEXT)
            [[nodiscard]] int getY() const override;   // Get Y position (OBJECT/TEXT)
            [[nodiscard]] int getWidth() const override;   // Get width (OBJECT/TEXT)
            [[nodiscard]] int getHeight() const override;   // Get height (OBJECT/TEXT)
            [[nodiscard]] Rect getRect() const override;   // Get animated sprite rect (OBJECT) #THROW if no rect
            [[nodiscard]] std::string getText() const override;    // Get text (TEXT)

            void setX(std::size_t const x) override;
            void setY(std::size_t const y) override;
            void setText(std::string const text) override;
            void setRect(Rect const rect) override;
        private :
            std::size_t _id;
            Type _type;
            std::string _file;
            int _x;
            int _y;
            int _width;
            int _height;
            std::string _text;
            Rect _rect;
    };
}