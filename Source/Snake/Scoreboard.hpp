//
// Created by Marcin on 2019-05-06.
//

#ifndef SCOREBOARD_SCOREBOARD_HPP
#define SCOREBOARD_SCOREBOARD_HPP
#include <string>
#include <utility>
#include <vector>
#include <conio.h>
#include <ctime>
class Timer {
public:

	Timer(std::size_t sec = 0, std::size_t min = 0, bool Swich = true) : sec_(sec), min_(min), Swich_(Swich) { timerSwich(); }

	void Stop() { Swich_ = 0; }
	void Start() { Swich_ = 1; }

private:
	std::size_t sec_;
	std::size_t min_;
	bool Swich_;

	void timerSwich();
	friend std::ostream &operator<< (std::ostream&, const Timer&);
};


class Scoreboard {
public:
	Scoreboard(std::size_t score = 0, Timer time = 0) : score_(score), time_(time) {}

	void resetTimer();


private:
	std::size_t score_;
	Timer time_;


};

#endif //SCOREBOARD_SCOREBOARD_HPP
