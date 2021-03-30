//
// Created by ferhatgec on 3/30/21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "../include/colin_converter.hpp"

float Colin_Converter::GetMin(float r, float g, float b) noexcept {
    float min = r;
    if(g < min) {
        min = g;
    }

    if(b < min) {
        min = b;
    }

    return min;
}

float Colin_Converter::GetMax(float r, float g, float b) noexcept {
    float max = r;

    if(g > max) {
        max = g;
    }

    if(b > max) {
        max = b;
    }

    return max;
}

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

std::tuple<std::string, std::string, std::string> Colin_Converter::ToHSL(u32 r, u32 g, u32 b) noexcept {
    float _r = r,
        _g = g,
        _b = b;

    float h = 0.0f,
        s,
        l,
        min,
        max;

    _r = _r / 255.0f;
    _g = _g / 255.0f;
    _b = _b / 255.0f;

    min = GetMin(_r, _g, _b);
    max = GetMax(_r, _g, _b);

    l   = 50 * (min + max);

    if(min == max) {
        s = h = 0;
    }
    else if(l < 50) {
        s = 100 * (max - min) / (max + min);
    }
    else {
        s = 100 * (max - min) / (2.0f - max - min);
    }

    if(max == _r) {
        h = 60 * (_g - _b) / (max - min);
    }
    else if(max == _g) {
        h = 60 * (_b - _r) / (max - min) + 120;
    }
    else if(max == _b)  {
        h = 60 * (_r - _g) / (max - min) + 240;
    }

    if(h < 0) {
        h = h + 360;
    }


    return std::make_tuple(
            std::to_string(std::lround(h)),
            std::to_string(std::lround(s)),
            std::to_string(std::lround(l)));
}