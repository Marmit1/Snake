#include <iostream>										 // Używa cout/cin
#include <conio.h>										 // Używa funkcje getch()
#include <windows.h>					 				 // Używa funkcji windows
#include <ctime>						 				 // Używa funkcji czas (prędkość gry)
#include <vector>										 // Używa funkcji Pozycje
#include <fstream>									     // Używa funkcji do wysokiego wyniku
#include <string>



using namespace std;
#define WIDTH 20										// Długość Plańszy
#define HEIGHT 20										// Szerokość Plańszy
char Level[HEIGHT][WIDTH];


// Deklaracja funkcji
void Initialize(int rozmiar, int snakeX[], int snakeY[]);														// Inicjacja Węża
void ClearScreen();																							// Jasność obrazu
void BudowaPoziomu();																							// Budowa Poziomu
void RysunekPlanszy();																								// Rysunek gry
void Poruszanie(int &rozmiar, int snakeX[], int snakeY[], int tempX[], int tempY[], int &item_count, int &punkty); // Aktualizacja pętli gry
void PredkoscPoruszania();																							// Aktualizacja Prędkości węża
void Pozycje(vector<int> &itemX, vector<int> &itemY, int &item_count, int snakeX[], int snakeY[], int &rozmiar, int tailX, int tailY, int &punkty);	// Powiększanie i odżywianie się Węża
bool IsGameOver(int snakeX[], int snakeY[], int rozmiar);														// Funkcja Koniec Gry
void bialy();																								// Kolor nieaktywnych opcji
void magnetowy();																							// Kolor aktywnej opcji
void PodMenu();																								// Wybór Poziomu Trudności
void Menu();																								// Menu główne
void snake();																								// Rozpoczęcie Gry
void Opcje();																								// Opcje
void Aktywne();																								// Zmiana koloru opcji Aktywnych
void Nieaktywne();																							// Zmiana koloru opcji Nieaktywnych
void GameOver();																							// Funkcja Koniec Gry
void Gwiazdka();																							// Gwiazdka po lewej stronie
void Gwiazdka2();																							// Gwiazdka po prawej stronie
void Sterowanie();																							// Wyświetla informacje o sterowaniu


// ZMIENNE
int n = 1, z;											// Poruszanie się klawiaturą w PodMenu
int m = 1;												// Poruszanie się klawiaturą w Menu
int o = 1;												// Poruszanie się klawiaturą w Opcjach
int p = 1;												// Poruszanie się klawiaturą w Zmianie koloru opcji Aktywnych
int r = 1;												// Poruszanie się klawiaturą w Zmianie koloru opcji Nieaktywnych
int x = 1;												// Poruszanie się klawiaturą w Funkcji GameOver
int nieaktywny = 1;										// Zmienna pozwalające zmiane Koloru wyświetlania opcji Nieaktywnych
int aktywny = 1;