﻿#include "pch.h"
#include <iostream>

class plansza {
public:
	plansza() {
		setplansza();
		char pio = 186, poz = 205, pd = 188, pg = 187, lg = 201, ld = 200;  //graficzne tworzenie ramki planszy
		std::cout << lg;
		for (int i = 1; i <= _szepla; i++) {
			std::cout << poz << poz;
		}
		std::cout << pg;
		for (int i = 1; i <= _wyspla; i++) {
			std::cout << std::endl << pio;
			for (int x = 0; x < _szepla; x++) {
				std::cout << "  ";
			}
			std::cout << pio;
		}
		std::cout << std::endl;
		std::cout << ld;
		for (int i = 1; i <= _szepla; i++) {
			std::cout << poz << poz;
		}
		std::cout << pd;
		char polegry[35][35];                       //na razie jest char ale weźcie co wam wygodne
	}

	void setplansza() {                                                                          //ustalanie wielkości planszy
		std::cout << "Podaj rozmiary planszy (od 5 do 35)" << std::endl << "Wysokosc" << std::endl;
		std::cin >> _wyspla;
		if (_wyspla < 5) {
			std::cout << "Za malo. Ustawienie domyslne =5" << std::endl;
			_wyspla = 5;
		}
		if (_wyspla > 35) {
			std::cout << "Za duzo. Ustawienie domyslne =35" << std::endl;
			_wyspla = 35;
		}
		std::cout << "Szerokosc" << std::endl;
		std::cin >> _szepla;
		if (_szepla < 5) {
			std::cout << "Za malo. Ustawienie domyslne =5" << std::endl;
			_szepla = 5;

		}
		if (_szepla > 35) {
			std::cout << "Za duzo. Ustawienie domyslne =35" << std::endl;
			_szepla = 35;

		}
	}


	int _wyspla;
	int _szepla;
};

// szerokość faktyczna wynosi 2*szepla aby zachować proporcje z wysokością
