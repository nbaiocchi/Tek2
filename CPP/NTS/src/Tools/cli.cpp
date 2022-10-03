/*
** EPITECH PROJECT, 2022
** input
** File description:
** a
*/

#include "Errors/Errors.hpp"
#include "Utils/Utils.hpp"

void utils::SplitString(std::string &s, std::vector<std::string> &v, char spliter)
{
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
	std::string temp = "";
	for(size_t i=0;i<s.length();++i){
		
		if(s[i]==spliter){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
	}
	v.push_back(temp);
	
}

bool utils::in_array(const std::string &value, const std::vector<std::string> &array)
{
    return std::find(array.begin(), array.end(), value) != array.end();
}

bool utils::handle_input(std::string str, size_t nb_equal, const std::vector<std::string> all_cmd)
{
    std::vector<std::string> line;
    const std::vector<std::string> all_state = {"0", "1", "U"};

    if (nb_equal > 1) {
        throw Errors("Not right amount of equal sign");
    }
    if (nb_equal != 1) {
        return (false);
    }
    SplitString(str, line, '=');
    if (line.size() != 2) {
        throw Errors("Not right amount of arguments");
    }
    if (in_array(line[0], all_cmd)) {
        throw Errors("Wrong first parameter");
    }
    if (in_array(line[1], all_state) == false) {
        throw Errors("Wrong state");
    }
    return (true);
    
}

void utils::is_correct_arg(std::string &str)
{
    const std::vector<std::string> all_cmd = {"exit", "display", "simulate", "loop", "dump"};
    if (str.empty()) {
        return;
    }
    
    size_t nb_equal = std::count(str.begin(), str.end(), '=');
    if (handle_input(str, nb_equal, all_cmd) == true)
        return;
    
    if (in_array(str, all_cmd) == false) {
        std::cout << "Not correct command\n";
    }
}

bool utils::sanitize(std::vector<std::string> &command)
{
    std::string line;
    std::cout << "> ";
    std::getline(std::cin, line);
    if (std::cin.eof()) {
        return (true);
    }
    SplitString(line, command, '=');
    is_correct_arg(line);  
    return (false); 
}