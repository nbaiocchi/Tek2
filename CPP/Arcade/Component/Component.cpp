/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Component
*/

#include "Component.hpp"

#include <utility>

Arcade::Component::Component(std::size_t id, Type type, std::string file, int x, int y, int width, int height, std::string text, Arcade::Rect rect)
{
    _id = id;
    _type = type;
    _file = std::move(file);
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _text = std::move(text);
    _rect = rect;
}

std::size_t Arcade::Component::getId() const
{
    return (_id);
}

Arcade::IComponent::Type Arcade::Component::getType() const
{
    return (_type);
}

std::string Arcade::Component::getFile() const
{
    return (_file);
}

int Arcade::Component::getX() const
{
    return (_x);
}

int Arcade::Component::getY() const
{
    return (_y);
}

int Arcade::Component::getWidth() const
{
    return (_width);
}

int Arcade::Component::getHeight() const
{
    return (_height);
}

Arcade::Rect Arcade::Component::getRect() const
{
    // if (this->getType() != OBJECT)
    //     throw Errors("Invalid Composent");
    return (_rect);
}   // Get animated sprite rect (OBJECT) #THROW if no rect
std::string Arcade::Component::getText() const
{
    return (_text);
} 

void Arcade::Component::setX(std::size_t const x)
{
    _x = x;
}

void Arcade::Component::setY(std::size_t const y)
{
    _y = y;
}

void Arcade::Component::setText(std::string const text)
{
    _text = text;
}

void Arcade::Component::setRect(Rect const rect)
{
    _rect = rect;
}
