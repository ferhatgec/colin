// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//
#ifndef COLIN_COLIN_CONVERTER_HPP
#define COLIN_COLIN_CONVERTER_HPP

#include <tuple>
#include "defs/colin_defs.hpp"

class Colin_Converter {
public:
    Colin_Converter() = default;
    ~Colin_Converter()= default;

    float GetMin(float r, float g, float b) noexcept;
    float GetMax(float r, float g, float b) noexcept;

    std::string ToHex (u32 r, u32 g, u32 b) noexcept;
    std::tuple<std::string, std::string, std::string, std::string> ToCMYK(u32 r, u32 g, u32 b) noexcept;
    std::tuple<std::string, std::string, std::string>              ToHSL (u32 r, u32 g, u32 b) noexcept;
    std::tuple<std::string, std::string, std::string>              ToHSV (u32 r, u32 g, u32 b) noexcept;
};

#endif //COLIN_COLIN_CONVERTER_HPP
