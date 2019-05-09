#include "scoreboard.hpp"
#include <fstream>
#include <algorithm>
#include <windows.h>

void Scoreboard::resetTimer() {time_.Stop(); time_.Start();}


std::ostream &operator<<(std::ostream &out, const Timer &t) {
    out <<" "<<t.min_<<":"<<t.sec_<<" ";
    return out;
}


void Timer::timerSwich() {
    min_=0;
    while(Swich_){
        for(sec_=0;sec_<60;sec_++){ Sleep(1000);}
        min_++;
    }
}
