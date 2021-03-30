// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef COLIN_COLIN_MAIN_HPP
#define COLIN_COLIN_MAIN_HPP

#include <iostream>
#include <string>
#include <vector>

#include "defs/colin_defs.hpp"

class Color {
public:
    u32 r, g, b;
};

enum InfoType : const u8 {
    Name = 1,
    Rgb  = 3,
    Hex,
    Cmyk,
    Hsl,
    Hsv
};

class Colin {
    // Table unicode character
    const std::string table_item = "░░";

    // Table background color
    const std::string color = "\033[48;2;";

    std::string color_data = color;

    // Table colors
    const std::string light_gray = SetColor(171, 171, 171);
    const std::string white      = SetColor(255, 255, 255);

    const std::string reset      = "\033[0m";

    std::vector<std::string> infos = {
            ""       ,
            "-----"  ,
            "\033[0;31mr\033[0;32mg\033[0;34mb\033[0m  : ",
            "hex  : ",
            "cmyk : ",
            "hsl  : ",
            "hsv  : "
    };

    unsigned line = 0;

    u32 r = 0, g = 0, b = 0;
public:
    Colin() = default;
    ~Colin()= default;

    std::string SetColor(u32 r, u32 g, u32 b) noexcept;

    void        Newline ();

    void Init           (Color color)         noexcept;

    void PrintColorBox  (bool split)          noexcept;
    void PrintBox       ()                    noexcept;
};

#endif //COLIN_COLIN_MAIN_HPP
