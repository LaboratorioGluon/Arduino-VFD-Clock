#include "RTC.h"

RTC_DS3231 rtc;
DateTime lastRtc;

struct vfdTime lastVfdTime;

void rtcInit(){

    if(!rtc.begin()){
        abort();
    }

    lastRtc = rtc.now();

    lastVfdTime.hd = lastRtc.hour()/10;
    lastVfdTime.hu = lastRtc.hour()%10;
    lastVfdTime.md = lastRtc.minute()/10;
    lastVfdTime.mu = lastRtc.minute()%10;

}

void rtcUpdate(){

    // Update the lastRtc Value;
    lastRtc = rtc.now();


    lastVfdTime.hd = lastRtc.hour()/10;
    lastVfdTime.hu = lastRtc.hour()%10;
    lastVfdTime.md = lastRtc.minute()/10;
    lastVfdTime.mu = lastRtc.minute()%10;
    
}