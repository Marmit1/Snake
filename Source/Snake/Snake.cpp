// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Gameboard.hpp"
#include <vector>
int main()
{
	plansza plansza;
    std::cout << "Hello World!\n"; 
}

void Snake::Fruit::render(const plansza &p)
{
	while (positionCoordinates_.y != ... && positionCoordinates_.x != ...)// tutaj trzeba dać warunki żeby nie renderowało się tam gdzie jest wąż, nie wiem jakie mają być  dlatego niech ktoś mądry nad tym pomyśli albo wymyśli coś innego bo ja się na tym nie znam
	{
		positionCoordinates_.y = (std::rand() % (plansza.getHeight() - 1)) + 1;//losowanie od 1 do 34 nw czy dobrze
		positionCoordinates_.x = (std::rand() % (plansza.getwidth() - 1)) + 1;
	}
	// tutaj funkcja robiąca jakiś znaczek na planszy 

}

void Snake::Fruit::clean()
{
	//funkcja usuwająca znaczek(owoc) z planszy jak wąż najedzie
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
