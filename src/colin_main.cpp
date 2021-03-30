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

std::string Colin::SetColor(u32 r, u32 g, u32 b) noexcept {
    return this->color    +
        std::to_string(r) +
        ";"               +
        std::to_string(g) +
        ";"               +
        std::to_string(b) +
        "m";
}

std::string Colin::SetFgColor(u32 r, u32 g, u32 b) noexcept {
    return "\033[38;2;"      +
           std::to_string(r) +
           ";"               +
           std::to_string(g) +
           ";"               +
           std::to_string(b) +
           "m";
}


void Colin::Newline() {
    if(this->line < this->infos.size()) {
        std::cout << "   " << this->infos[this->line];

        switch(this->line) {
            case InfoType::Name: {

                break;
            }

            case InfoType::Rgb: {
                std::cout          <<
                    this->pink     +
                    "rgb"          +
                    this->reset    +
                    "("
                    "\033[0;31m"   <<
                    this->r        <<
                    ", \033[0;32m" <<
                    this->g        <<
                    ", \033[0;34m" <<
                    this->b        <<
                    this->reset    +
                    ")";

                break;
            }

            case InfoType::Hex: {
                std::cout << this->hex;

                break;
            }

            case InfoType::Cmyk: {
                std::cout <<
                    "("
                    "\033[0;31m"           +
                    std::get<0>(this->cmyk)+
                    this->reset            +
                    ", \033[0;32m"         +
                    std::get<1>(this->cmyk)+
                    ", \033[0;34m"         +
                    std::get<2>(this->cmyk)+
                    ", "                   +
                    this->pink             +
                    std::get<3>(this->cmyk)+
                    ")";

                break;
            }

            case InfoType::Hsl: {
                std::cout <<
                    "("
                    "\033[0;31m"           +
                    std::get<0>(this->hsl)+
                    this->reset            +
                    ", \033[0;32m"         +
                    std::get<1>(this->hsl)+
                    ", \033[0;34m"         +
                    std::get<2>(this->hsl)+
                    ")";

                break;
            }

            case InfoType::Hsv: {
                std::cout <<
                          "("
                          "\033[0;31m"           +
                          std::get<0>(this->hsv) +
                          this->reset            +
                          ", \033[0;32m"         +
                          std::get<1>(this->hsv) +
                          ", \033[0;34m"         +
                          std::get<2>(this->hsv) +
                          ")";

                break;
            }

            case InfoType::Ascii: {

                break;
            }

            case InfoType::Esc: {

                break;
            }
        }

        ++this->line;
    }

    std::cout << '\n';
}

void Colin::Init(Color color) noexcept {
    this->r = color.r;
    this->g = color.g;
    this->b = color.b;

    this->color_data = SetColor(color.r, color.g, color.b);

    this->infos[Name] = "\033[38;2;"  +
            std::to_string(this->r)+
            ";"                    +
            std::to_string(this->g)+
            ";"                    +
            std::to_string(this->b)+
            "m"                    +
            "color\033[0m: ";

    this->infos[Hex]  = this->red     +
            "hex  : "               +
            this->orange           +
            this->hex;

    this->infos[Cmyk]  = this->orange  +
            "cmyk : "              +
            this->yellow;

    this->infos[Hsl]   = this->yellow  +
            "hsl  : "               +
            this->green;

    this->infos[Hsv]   = this->green   +
            "hsv  : "               +
            this->blue;

    this->infos[Ascii] = this->blue    +
            "ascii: "               +
            this->purple            +
            "work-in-progress";

    this->infos[Esc]   =this->purple+
            "esc  : "               +
            this->pink              +
            "work-in-progress";

    this->hex = this->converter.ToHex (this->r, this->g, this->b);
    this->cmyk= this->converter.ToCMYK(this->r, this->g, this->b);
    this->hsl = this->converter.ToHSL (this->r, this->g, this->b);
    this->hsv = this->converter.ToHSV (this->r, this->g, this->b);
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

    this->Newline();
}

void Colin::PrintBox() noexcept {
    unsigned i, line;
    bool     split;

    for(i = 0; i <= 5; i++) {
        TABLE_LIGHT_GRAY()
    }

    this->Newline();

    for(i = 0; i <= 5; i++) {
        TABLE_WHITE     ()
    }

    this->Newline();

    for(i = 0, split = false; i < 6; i++) {
        PrintColorBox(split);
        split = !split;
    }

    for(unsigned i = 0; i <= 5; i++) {
        TABLE_LIGHT_GRAY()
    }

    this->Newline();

    for(unsigned i = 0; i <= 5; i++) {
        TABLE_WHITE()
    }

    this->Newline();
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