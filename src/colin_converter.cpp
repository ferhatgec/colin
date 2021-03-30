//
// Created by ferhatgec on 3/30/21.
//

#include <string>
#include "../include/colin_converter.hpp"

std::string Colin_Converter::ToHex(u32 r, u32 g, u32 b) noexcept {
    return "#" + std::to_string((r << 16) | (g << 8) | b);
}