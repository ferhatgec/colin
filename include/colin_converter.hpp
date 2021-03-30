//
// Created by ferhatgec on 3/30/21.
//

#ifndef COLIN_COLIN_CONVERTER_HPP
#define COLIN_COLIN_CONVERTER_HPP

#include <tuple>
#include "defs/colin_defs.hpp"

class Colin_Converter {
public:
    Colin_Converter() = default;
    ~Colin_Converter()= default;

    std::string ToHex (u32 r, u32 g, u32 b) noexcept;
    std::tuple<std::string, std::string, std::string, std::string> ToCMYK(u32 r, u32 g, u32 b) noexcept;
};

#endif //COLIN_COLIN_CONVERTER_HPP
