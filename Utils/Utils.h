#ifndef UTILS_LIB_H
#define UTILS_LIB_H

#include <Arduino.h>

typedef enum {
  NONE =  0,
  RED =  16711680,
  GREEN =  65280,
  BLUE =  255,
  WHITE =  16777216,
} MainColors;

class Utils
{
    public:
        static MainColors RGB2MainColor(uint16_t r, uint16_t g, uint16_t b);
    private:
        Utils(){};
};

#endif
