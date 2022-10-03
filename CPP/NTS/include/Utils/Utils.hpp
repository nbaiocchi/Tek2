/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "Components/IComponent.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <regex>
#include <map>

namespace utils
{
    void SplitString(std::string &s, std::vector<std::string> &v, char spliter);
    bool in_array(const std::string &value, const std::vector<std::string> &array);
    bool handle_input(std::string str, size_t nb_equal, const std::vector<std::string> all_cmd);
    void is_correct_arg(std::string &str);
    bool sanitize(std::vector<std::string> &command);
    std::map<std::string, std::shared_ptr<nts::IComponent>> take_map(std::string content);
    std::map<std::string, std::shared_ptr<nts::IComponent>> parser(std::string filename);
}

#endif /* !UTILS_HPP_ */
