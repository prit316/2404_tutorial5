#include "RGB.h"

RGB::RGB(int red, int green, int blue){
    this->red = red;
    this->green = green;
    this->blue = blue; 
}
RGB::RGB() {
    this->red = 255;
    this->green = 255;
    this->blue = 255;
}

int RGB::getRed(){
    return red;
}
int RGB::getGreen(){
    return green;
}
int RGB::getBlue(){
    return blue;
}

void RGB::setRed(int red){
    this->red = red;
}
void RGB::setGreen(int green){
    this->green = green;
}
void RGB::setBlue(int blue){
    this->blue = blue;
}

CuColour RGB::getColour() {
    return (red << 16) | (green << 8) | (blue);
}

void RGB::setCuColour(CuColour colour){
    red = (colour >> 16) & 0xFF;
    green = (colour >> 8) & 0xFF;
    blue = colour & 0xFF;
}
const RGB RGB::WHITE(){
    return RGB(255, 255, 255); 
}
const RGB RGB::GREEN(){
    return RGB(0, 255, 0);
}
const RGB RGB::BLUE(){
    return RGB(0, 0, 255);
}
const RGB RGB::BLACK(){
    return RGB(0, 0, 0);
}