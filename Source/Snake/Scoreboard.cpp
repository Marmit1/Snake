#include "pch.h"
#include "Scoreboard.hpp"
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

void Scoreboard::startTimer() { time_.timerSwich(1); }


void Timer::timerSwich(bool start) {
	min_ = 0;
	while (start) {
		for (sec_ = 0; sec_ < 60; sec_++) { Sleep(1000); }
		min_++;
	}
}

std::string Timer::tostring() {
	std::ostringstream oss;
	oss << "[" << min_ << ":" << sec_ << "]";

	return oss.str();
}

