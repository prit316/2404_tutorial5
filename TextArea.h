#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include <iostream>
#include "defs.h"
#include "RGB.h"

class TextArea {
private:
    Rectangle dimensions;
    std::string text;
    std::string id;
    RGB fill;
    RGB border;

public:
    TextArea(int x, int y, int width, int height, const std::string& id, 
             const std::string& label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

    TextArea(const Rectangle& rect, const std::string& id, 
             const std::string& label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

   
    Rectangle getDimensions() const;
    std::string getText() const;
    std::string getId() const;
    RGB getFill() const;
    RGB getBorder() const;

 
    void setText(const std::string& newText);
    void setFill(const RGB& newFill);
    void setBorder(const RGB& newBorder);


    bool overlaps(const TextArea& ta) const;

  
    void print() const;
};

#endif
