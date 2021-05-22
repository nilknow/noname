#include "Console.hpp"

Console *Console::_instance;

Console::Console() {
    loadFont();
}

void Console::showOutput() {
    std::cout << *_content << std::endl;
}
void Console::loadFont() {
//    FT_Library ft;
//    if (FT_Init_FreeType(&ft)) {
//        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
//    }
//    FT_Face face;
//    if (FT_New_Face(ft, "fonts/CenturyGothic.ttf", 0, &face)) {
//        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
//    }
//    FT_Set_Pixel_Sizes(face, 0, 48);//0 means auto
//    if (FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
//        std::cout << "ERROR::FREETYPE: Failed to load Glyph" << std::endl;
//    }
}

void Console::setContent(std::string* content) {
    this->_content = content;
    showOutput();
}

Console* Console::getInstance() {
    if (Console::_instance == nullptr) {
        Console console = Console();
        Console::_instance = &console;
    }
    return Console::_instance;
}
