#ifndef Comms_H
#define Comms_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Utils.h>

typedef struct{
    byte length;
    byte type;
}MessageHeader;

class Comms
{
    private:
         SoftwareSerial _serial;
         byte *pRecieve = nullptr;
         byte *endRecieve = pRecieve - 1;
         bool gotLength = false;
         byte msgBuffer[20];
         MessageHeader *pMainMessage;
    protected:
        void SendMessage(MessageHeader* message);
        bool ReceiveMessage(MessageHeader* message);
        void virtual DispatchMessage(MessageHeader* message) = 0;
    public:
        Comms(uint8_t rx, uint8_t tx);
        void PollMessage();
};

enum MessageTypes
{
    REQUEST_FOR_TEMPERATURE = 1,
    RESPONSE_FOR_TEMPERATURE = 2,
    REQUEST_FOR_COLOR = 3,
    RESPONSE_FOR_COLOR = 4,
    REQUEST_RAW_COLOR = 5,
    RESPONSE_RAW_COLOR = 6,
    REQUEST_FOR_HEIGHT = 7,
    RESPONSE_FOR_HEIGHT = 8,
    REQUEST_BUZZ_ON = 9,
    RESPONSE_BUZZ_ON = 10,
    REQUEST_BUZZ_OFF = 11,
    RESPONSE_BUZZ_OFF = 12,
    REQUEST_ANGULAR_ORIENTATION = 13,
    RESPONSE_ANGULAR_ORIENTATION = 14,
    REQUEST_SERVO_DROP = 15,
    RESPONSE_SERVO_DROP = 16,
};

typedef struct {
  uint16_t r;
  uint16_t g;
  uint16_t b;
} rgbColor;

typedef struct{
   float pitch;
   float roll;
   float yaw;
} AngularOrientation;

typedef struct{
   MessageHeader header;
} TemperatureRequest;

typedef struct{
   MessageHeader header;
} ColorRequest;

typedef struct{
   MessageHeader header;
} RawColorRequest;

typedef struct{
   MessageHeader header;
} HeightRequest;

typedef struct{
   MessageHeader header;
} BuzzRequest;

typedef struct{
   MessageHeader header;
} GyroRequest;

typedef struct{
   MessageHeader header;
   ServoColors servoColor;
}ServoRequest;

// end of requests

// start of responses

typedef struct{
   MessageHeader header;
   float temperature;
} TemperatureResponse;

typedef struct{
   MessageHeader header;
   MainColors color;
} ColorResponse;

typedef struct{
   MessageHeader header;
   rgbColor color;
} RawColorResponse;

typedef struct{
   MessageHeader header;
   int height;
} HeightResponse;

typedef struct{
   MessageHeader header;
} BuzzResponse;

typedef struct{
   MessageHeader header;
   AngularOrientation angularOrientation;
} GyroResponse;

typedef struct{
   MessageHeader header;
   BallStates state;
} ServoResponse;

// end of responses

#endif
