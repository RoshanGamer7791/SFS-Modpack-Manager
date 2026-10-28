#ifndef SFSMPM_STYLING_HPP
#define SFSMPM_STYLING_HPP

#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> get_global_styles();
std::unordered_map<std::string, std::string> get_qss_styles(std::string filePath);

#endif // SFSMPM_STYLING_HPP