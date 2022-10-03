/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
** File description:
** Event
*/

#include "Event.hpp"

#include <utility>

Arcade::Event::Event(size_t key, Pos pos)
{
    this->_key = key;
    this->_pos = pos;
    _data = "NULL";
}

Arcade::Event::Event(size_t key, Pos pos, std::string data)
{
    this->_key = key;
    this->_pos = pos;
    _data = std::move(data);
}

Arcade::Event::~Event()
= default;

std::size_t Arcade::Event::getKey() const
{
    return (_key);
}

void Arcade::Event::setKey(std::size_t const key)
{
    _key = key;
}

Arcade::Pos Arcade::Event::getMousePos() const
{
    return (_pos);
}

std::string Arcade::Event::getData() const {
    return _data;
}
