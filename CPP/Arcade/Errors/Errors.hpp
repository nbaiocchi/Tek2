/*
** EPITECH PROJECT, 2022
** input
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <regex>
#include <map>

class Errors : public std::exception
{
    std::string _msg;
public:
    Errors(const std::string& msg) : _msg(msg){}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
}; 

#endif /* !ERRORS_HPP_ */

