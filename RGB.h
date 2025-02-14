#ifndef RGB_H
#define RGB_H
#include <iostream>
#include "defs.h"

class RGB{
    private:
        int red, green, blue;
    public:
        RGB(int red, int green, int blue);
        RGB();
        int getRed();
        int getGreen();
        int getBlue();

        void setRed(int red);
        void setGreen(int green);
        void setBlue(int blue);

        CuColour getColour();
        void setCuColour(CuColour colour);

        const static RGB WHITE();
        const static RGB RED();
        const static RGB GREEN();
        const static RGB BLUE();
        const static RGB BLACK();
};

#endif

