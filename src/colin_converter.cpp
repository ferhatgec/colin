//
// Created by ferhatgec on 3/30/21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "../include/colin_converter.hpp"


std::string Colin_Converter::ToHex(u32 r, u32 g, u32 b) noexcept {
    std::stringstream stream;
    stream << std::hex << (r << 16 | g << 8 | b);

    return "#" + stream.str();
}

std::tuple<std::string, std::string, std::string , std::string> Colin_Converter::ToCMYK(u32 r, u32 g, u32 b) noexcept {
    float _r = r,
        _g = g,
        _b = b;

    float w, c, m, y, k, max;

    if(_r == 0 && _g == 0 && _b == 0) {
        c   = m = y = 0;
        k  = 100;
    }
    else {
        _r  = _r / 255;
        _g  = _g / 255;
        _b  = _b / 255;

        max    = _r;

        if(_g > max) {
            max = _g;
        }

        if(_b > max) {
            max = _b;
        }

        w   = max;

        c = ((w - _r) / w) * 100;
        m = ((w - _g) / w) * 100;
        y = ((w - _b) / w) * 100;

        k = (1 - w) * 100;
    }

    return std::make_tuple(
            std::to_string(std::lround(c)),
            std::to_string(std::lround(m)),
            std::to_string(std::lround(y)),
            std::to_string(std::lround(k)));
}