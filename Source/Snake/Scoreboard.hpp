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

	
private:
	friend std::ostream &operator<< (std::ostream&, const Timer&);
};


class Scoreboard {
public:
	Scoreboard(std::size_t score = 0) : score_(score), time_(time) {}

	void resetTimer();


private:
	std::size_t score_;
	Timer time_;


};

#endif //SCOREBOARD_SCOREBOARD_HPP
