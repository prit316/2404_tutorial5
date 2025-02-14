#include "TextArea.h"


TextArea::TextArea(int x, int y, int width, int height, const std::string& id, 
                   const std::string& label, RGB fill, RGB border) {
    this->dimensions = {x, y, width, height};
    this->id = id;
    this->text = label;
    this->fill = fill;
    this->border = border;
}


TextArea::TextArea(const Rectangle& rect, const std::string& id, 
                   const std::string& label, RGB fill, RGB border) {
    this->dimensions = rect;
    this->id = id;
    this->text = label;
    this->fill = fill;
    this->border = border;
}


Rectangle TextArea::getDimensions() const { return this->dimensions; }
std::string TextArea::getText() const { return this->text; }
std::string TextArea::getId() const { return this->id; }
RGB TextArea::getFill() const { return this->fill; }
RGB TextArea::getBorder() const { return this->border; }

void TextArea::setText(const std::string& newText) { this->text = newText; }
void TextArea::setFill(const RGB& newFill) { this->fill = newFill; }
void TextArea::setBorder(const RGB& newBorder) { this->border = newBorder; }


bool TextArea::overlaps(const TextArea& ta) const {
    return this->dimensions.overlaps(ta.dimensions);
}

void TextArea::print() const {
    std::cout << "TextArea id: " << this->id << "\n"
              << "Preferred location: " << this->dimensions.x << ", " << this->dimensions.y << "\n"
              << "Size: " << this->dimensions.width << ", " << this->dimensions.height << "\n"
              << "Text: " << this->text << "\n";
}
