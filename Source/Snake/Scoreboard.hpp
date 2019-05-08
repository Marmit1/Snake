//
// Created by Marcin on 2019-05-06.
//

#ifndef SCOREBOARD_SCOREBOARD_HPP
#define SCOREBOARD_SCOREBOARD_HPP
#include <string>
#include <utility>
#include <vector>
#include <conio.h>
#include <time.h>
class Timer {
public:
	Timer(std::size_t sec = 0, std::size_t min = 0) : sec_(sec), min_(min) {}

	void timerSwich(bool);
	std::string tostring();

private:
	std::size_t sec_;
	std::size_t min_;
};
class Scoreboard {
public:
	Scoreboard(std::size_t score = 0, Timer time = 0) : score_(score), time_(time) {}

	void startTimer();


private:
	std::size_t score_;
	Timer time_;
};

#endif //SCOREBOARD_SCOREBOARD_HPP
