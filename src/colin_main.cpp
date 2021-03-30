// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include "../include/colin_main.hpp"

#define TABLE_LIGHT_GRAY()  \
    std::cout            << \
        this->light_gray << \
        this->table_item << \
        this->white      << \
        this->table_item << \
        this->reset;

#define TABLE_WHITE()       \
    std::cout            << \
        this->white      << \
        this->table_item << \
        this->light_gray << \
        this->table_item << \
        this->reset;

#define TABLE_COLOR()       \
    std::cout            << \
        this->color_data << \
        this->table_item << \
        this->reset;

#define NEWLINE()           \
    std::cout            << \
        '\n';

std::string Colin::SetColor(u32 r, u32 g, u32 b) noexcept {
    return this->color    +
        std::to_string(r) +
        ";"               +
        std::to_string(g) +
        ";"               +
        std::to_string(b) +
        "m";
}

void Colin::Init(Color color) noexcept {
    this->color_data = SetColor(color.r, color.g, color.b);
}

void Colin::PrintColorBox(bool split) noexcept {
    if(split) {
        TABLE_LIGHT_GRAY()
    }
    else {
        TABLE_WHITE     ()
    }

    for(unsigned i = 0; i <= 7; i++) {
        TABLE_COLOR()
    }

    if(!split) {
        TABLE_LIGHT_GRAY()
    }
    else {
        TABLE_WHITE     ()
    }

    NEWLINE             ()
}

void Colin::PrintBox() noexcept {
    unsigned i;
    bool     split;

    for(i = 0; i <= 5; i++) {
        TABLE_LIGHT_GRAY()
    }

    NEWLINE()

    for(i = 0; i <= 5; i++) {
        TABLE_WHITE     ()
    }

    NEWLINE()

    for(i = 0, split = false; i < 6; i++) {
        PrintColorBox(split);
        split = !split;
    }

    for(unsigned i = 0; i <= 5; i++) {
        TABLE_LIGHT_GRAY()
    }

    NEWLINE()

    for(unsigned i = 0; i <= 5; i++) {
        TABLE_WHITE()
    }

    NEWLINE()
}

int main(int argc, char** argv) {
    if(argc < 4) {
        std::cout  <<
            "Fegeya Colin : CLI color info tool"
            "\n"
            "--"
            "\n"   <<
            argv[0]<<
            " {r} {g} {b}"
            "\n"
            "-------"
            "\n"   <<
            argv[0]<<
            " 255 255 255"
            "\n";

        return 1;
    }

    Colin test;

    std::vector<u32> color;

    for(unsigned i = 1; i < argc; i++) {
        color.push_back(std::stoi(argv[i]));
    }

    test.Init(Color{color[0], color[1], color[2]});
    //              ^^^^^^^^  ^^^^^^^^  ^^^^^^^^
    //              r         g         b

    test.PrintBox();

    return 0;
}