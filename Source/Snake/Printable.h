#pragma once
#include<iostream>
#include<vector>


class printable {
public:
	virtual void print() = 0;
	virtual ~ printable () {}
};

class fruit : public printable {
public: 
	void print() override { //przyjnuje jak� zmienna i w ze�no�ci od tego mo�e rysowa� r�zne owocki
		std::cout << "$";
	}

};

class board :public printable {
public:
	void print() override {
		print_score();
		print_timer();
	}
	void print_score()
	void print_timer()
};

class snake_body : public printable {
public:
	void print(pole type) override {
		if(type==HEAD)
			std::cout << "";
		if (type == BODY)
			std::cout << "";
		if (type == TAIL)
			std::cout << "";//nie wiem co ma by� cia�em sanke'a
	}
};

class print_blanck : public printable {
	void print() override {
		std::cout << " ";
	}
};


print_game(std::vector<std::vector> board );