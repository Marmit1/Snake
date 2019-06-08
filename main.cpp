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

// Budowa Poziomu
void BudowaPoziomu()
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            Level[0][j] = '*';
            Level[i][0] = '*';
            Level[i][WIDTH-1] = '*';
            Level[HEIGHT-1][j] = '*';
        }
    }
}


// Wyświetlenie Poziomu
void RysunekPlanszy()
{
    for(int i=0; i<HEIGHT; i++)
    {
        cout << endl;
        for(int j=0; j<WIDTH; j++)
            cout  << " " << Level[i][j];

    }
}

// Funkcja GameOver
void GameOver()
{
    while(1)
    {
        system("cls");
        bialy();
        printf("\n\n\n\n\t\t\t      Koniec Gry\n\n\n\t\t\t   GRASZ JESZCZE ?\n");
        if(x==1){magnetowy();Gwiazdka();printf(" Tak ");Gwiazdka2();}
        if(x==1){bialy();printf("\t\t\t\t  Nie\n");}
        if(x==2){bialy(); printf("\t\t\t\t  Tak\n");}
        if(x==2){magnetowy();Gwiazdka();printf(" Nie ");Gwiazdka2();}
        z = _getch();

        if(z == 72){if(x>1){x--;}}
        if(z == 80){if(x<2){x++;}}
        if((z == 13) && (x == 2))  exit(1);
        if((z == 13) && (x == 1))  PodMenu();
    }
}