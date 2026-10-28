#include "styling.hpp"

#include <filesystem>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

std::unordered_map<std::string, std::string> get_global_styles() {
    std::unordered_map<std::string, std::string> styles;
    fs::path globalStylesPath("styling/global");

    for (const auto& styleFilePath: fs::recursive_directory_iterator(globalStylesPath)) {
        if (!styleFilePath.is_regular_file()) {
            continue;
        }
        if (styleFilePath.is_directory()) {
            continue;
        }

        std::ifstream styleFile(styleFilePath.path());
        std::stringstream styleBuffer;
        styleBuffer << styleFile.rdbuf();
        std::string style = styleBuffer.str();
        styles[styleFilePath.path().stem().string()] = style;
    }

    return styles;
}

std::unordered_map<std::string, std::string> get_qss_styles(std::string filePath) {
    std::unordered_map<std::string, std::string> styles;

    fs::path stylesPath(filePath);

    for (const auto& styleFilePath: fs::directory_iterator(stylesPath)) {
        if (!styleFilePath.is_regular_file()) {
            continue;
        }
        if (styleFilePath.is_directory()) {
            continue;
        }

        std::ifstream styleFile(styleFilePath.path());
        std::stringstream styleBuffer;
        styleBuffer << styleFile.rdbuf();
        std::string style = styleBuffer.str();
        styles[styleFilePath.path().stem().string()] = style;
    }

    return styles;
}