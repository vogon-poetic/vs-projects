#ifndef COLORFILLEDCIRCLE_H
#define COLORFILLEDCIRCLE_H

#include "ColorCircle.h"

class ColorFilledCircle : public ColorCircle
{
  public:
    ColorFilledCircle();
    ~ColorFilledCircle();
    void draw();
    void print();
};

#endif