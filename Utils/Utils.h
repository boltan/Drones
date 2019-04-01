#ifndef UTILS_LIB_H
#define UTILS_LIB_H

#include <Arduino.h>

typedef enum {
  MAIN_NONE =  0,
  MAIN_RED =  16711680,
  MAIN_GREEN =  65280,
  MAIN_BLUE =  255,
  MAIN_WHITE =  16777215,
} MainColors;

typedef enum {
    SERVO_RED = 0,
    SERVO_GREEN = 1,
    SERVO_BLUE = 2,
} ServoColors;

typedef enum{
    NOT_LOADED = 0,
    NEED_TO_LOAD = 1,
    LOADED = 2,
    DROPPED = 3,
} BallStates;

class Utils
{
    public:
        static MainColors RGB2MainColor(uint16_t r, uint16_t g, uint16_t b);
    private:
        Utils(){};
};

#endif
