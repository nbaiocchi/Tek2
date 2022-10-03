/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-abdelkarim.bengrine
** File description:
** parsers
*/


#include "../../include/Circuit/Circuit.hpp"
#include "Errors/Errors.hpp"
#include "SpecialComponents/Clock.hpp"
#include "SpecialComponents/False.hpp"
#include "SpecialComponents/Input.hpp"
#include "SpecialComponents/Output.hpp"
#include "SpecialComponents/True.hpp"
#include "Components/C4071.hpp"
#include <unistd.h>

void Circuit::take_map(std::string content)
{
    std::smatch matches;
    std::regex chips("(input|output|2716|4001|4004|4008|4011|4013|4017|4030|4040|4069|4071|4081|4094|4512|4515|4801|true|false|clock)\\s*([^\\s#]*)\\s*([^#|\\s]*)");
    std::regex clean("(^[^\\(|#]+)");
    std::istringstream iss(content);

    for (std::string line; std::getline(iss, line); ) {
        if (line[0] == '\0')
            continue;
        if (std::regex_search(line, matches, clean)) {
            line = matches[1].str();
        }
        if (std::regex_search(line, matches, chips)) {
            if (all_chips.find(matches[2]) != all_chips.end() || matches[2].str() == "\0")
                throw Errors("wrong component");
            if (matches[3].str() != "\0")
                throw Errors("test");
            this->all_chips.insert(std::pair<std::string, std::shared_ptr<nts::IComponent>>(matches[2].str(), this->_factory.createComponent(matches[1].str())));
            this->all_chips.at(matches[2].str())->setName(matches[2].str());
        } else {
            throw Errors("incorrect component");
        }
    }
    if (all_chips.empty() == 1)
        throw Errors("no component found");
}

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

void Circuit::take_links(std::string content)
{
    std::smatch matches;
    std::regex link("([^\\s#]*):([^\\s#]*)\\s*([^\\s#]*):([^\\s#]*)\\s*([^\\s#]*)");
    std::regex space("\\s*$");
    std::istringstream iss(content);

    for (std::string line; std::getline(iss, line); ) {
        if (line.empty() || std::all_of(line.begin(), line.end(), [](char c){return std::isspace(c);})) {
            continue;
        }
        if (std::regex_search(line, matches, link)) {
            if (matches[1].str() == "\0" || matches[2].str() == "\0" || matches[3].str() == "\0" || matches[4].str() == "\0") {
                throw Errors("incorrect link value");
            }
            if (is_digits(matches[2].str()) != true || is_digits(matches[4].str()) != true)
                throw Errors("incorrect link name");
            if (all_chips.find(matches[1]) == all_chips.end() || all_chips.find(matches[3]) == all_chips.end() || matches[5].str() != "\0") {
                throw Errors("incorrect link name");
            } else {
                if (this->all_chips.at(matches[1])->getType() == "output") {
                    this->all_chips.at(matches[1])->getPin(std::stoi(matches[2]))->setNext(this->all_chips.at(matches[3]));
                    this->all_chips.at(matches[1])->getPin(std::stoi(matches[2]))->set_i_pin(std::stoi(matches[4]));
                } else {
                    this->all_chips.at(matches[3])->getPin(std::stoi(matches[4]))->setNext(this->all_chips.at(matches[1]));
                    this->all_chips.at(matches[3])->getPin(std::stoi(matches[4]))->set_i_pin(std::stoi(matches[2]));
                }
                
            }      
        } else {
            std::cout << "[" << line << "]" << std::endl;
            throw Errors("incorrect links");
        }
    }
}

std::string cut_cmt(std::string file)
{
    std::istringstream iss(file);
    std::string res;

    for (std::string line; std::getline(iss, line); ) {
        if (line[0] == ' ' && line[1] == '#')
            continue;
        if (line[0] == '#')
            continue;
        if (line[0] == '\n')
            continue;
        res += line;
        res += "\n";
    }
    return res;
}

std::string clean_cmt(std::string file)
{
    char* str = const_cast<char*>(file.c_str());
    std::string res;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i+1] == ' ')
            continue;
        if (str[i] == ' ' && str[i+1] == '\n')
            continue;
        if (str[i] == ' ' && str[i+1] == '\t')
            continue;
        if (str[i] == ' ' && str[i+1] == '\0')
            continue;
        if (str[i] == '\n' && str[i+1] == '\n')
            continue;
        if (str[i] == '\t')
            continue;
        res += str[i];
    }
    return res;
}

void Circuit::parser(const std::string filename)
{
    std::regex chipset(".chipsets:");
    std::regex is_chips(".chipsets:.*([\\s\\S]*?)(.*).links:");
    std::regex is_links(".links:.*([\\s\\S]*)$");
    std::smatch matches;
    std::map<std::string, std::shared_ptr<nts::IComponent>> map;
    std::ifstream inFile;
    std::stringstream strStream;

    if (!access(filename.c_str(), X_OK))
        throw Errors("File is not valid");
    inFile.open(filename);
    if (!inFile) {
        throw Errors("Error while opening file");
    }
    strStream << inFile.rdbuf();
    std::string tmp = strStream.str();
    std::string test = clean_cmt(tmp);
    std::string file = cut_cmt(test);
    std::istringstream iss(file);
    if (std::regex_search(file, matches, is_chips)) {
        take_map(matches[1].str());
    } else
        throw Errors("incorrect format");
    if (std::regex_search(file, matches, is_links)) {
        take_links(matches[1].str());
    } else
        throw Errors("incorrect format");
}