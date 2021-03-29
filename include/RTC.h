#ifndef __RTC_H__
#define __RTC_H__

#include "RTCLib.h"

extern RTC_DS3231 rtc;
extern DateTime lastRtc;

struct vfdTime{
    uint8_t hd;
    uint8_t hu;
    uint8_t md;
    uint8_t mu;
};

extern struct vfdTime lastVfdTime;

void rtcInit();

void rtcUpdate();

#endif //__RTC_H__