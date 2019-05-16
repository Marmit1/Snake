// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Gameboard.hpp"
#include <vector>
#include "Snake.hpp"

int main()
{
	plansza plansza;
    std::cout << "Hello World!\n"; 
}

void Snake::Fruit::render(const plansza &p)
{
	//while (positionCoordinates_.y != ... && positionCoordinates_.x != ...)// tutaj trzeba dać warunki żeby nie renderowało się tam gdzie jest wąż, nie wiem jakie mają być  dlatego niech ktoś mądry nad tym pomyśli albo wymyśli coś innego bo ja się na tym nie znam
	//{
	//	positionCoordinates_.y = (std::rand() % (plansza.getHeight() - 1)) + 1;//losowanie od 1 do 34 nw czy dobrze
	//	positionCoordinates_.x = (std::rand() % (plansza.getwidth() - 1)) + 1;
	//}

	// tutaj funkcja robiąca jakiś znaczek na planszy 

}

void Snake::Fruit::clean()
{
	//funkcja usuwająca znaczek(owoc) z planszy jak wąż najedzie
}
