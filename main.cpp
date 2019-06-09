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

void Poruszanie(int &rozmiar, int snakeX[], int snakeY[], int tempX[], int tempY[], int &item_count, int &punkty) {
    int count = 0;
    char input = 219;
    char previnput = 's';
    int tailX, tailY;
    bool gameOver = false;
    vector<int> itemX, itemY;

    while (!gameOver)                                    // Pętla aż gra się skończy
    {
        PredkoscPoruszania();                                    // Prędkość

        // Dodanie ogona podczas poruszania
        tailY = snakeY[rozmiar - 1];
        tailX = snakeX[rozmiar - 1];

        // Usunięcie poprzednich śladów po ogonie
        Level[tailY][tailX] = ' ';
        Pozycje(itemX, itemY, item_count, snakeX, snakeY, rozmiar, tailX, tailY, punkty);

        // Kopia węża (z wyjątkiem ogona) do tablicy temp
        // Zostawienie pierwszego elementy
        for (int i = 0; i < rozmiar - 1; i++) {
            tempX[i + 1] = snakeX[i];                        // Kopiowanie wartości y
            tempY[i + 1] = snakeY[i];                        // Kopiowanie wartości x
        }

        // Kopia głowy do pierwszego elementy aby mógł zostać przeniesiony przez użytkownika
        tempX[0] = snakeX[0];
        tempY[0] = snakeY[0];

        // Kopiowanie tablicy temp
        // Pierwsze 2 elementy będą powielać głowy z samej pozycji X i Y
        for (int i = 0; i < rozmiar; i++) {
            snakeX[i] = tempX[i];                        // Kopiowanie wartości Y
            snakeY[i] = tempY[i];                        // Kopiowanie wartości X
        }

        // Naciśnięcie klawiszy
        if (_kbhit())
            input = _getch();

        // WHILE MOVING DOWN
        if (previnput == 's') {
            snakeY[0] += 1;                                // Zestaw głów na nowej pozycji
            if (input == 'a' || input == 'A')            // Idź w lewo
                previnput = 'a';
            else if (input == 'd' || input == 'D')    // Idź w prawo
                previnput = 'd';
        }
            // WHILE MOVING UP
        else if (previnput == 'w') {
            snakeY[0] -= 1;                                // Zestaw głów na nowej pozycji
            if (input == 'a' || input == 'A')        // Idź w lewo
                previnput = 'a';
            else if (input == 'd' || input == 'D')    // Idź w prawo
                previnput = 'd';
        }
            // WHILE MOVING RIGHT
        else if (previnput == 'd') {
            snakeX[0] += 1;                                // Zestaw głów na nowej pozycji
            if (input == 'w' || input == 'W')        // Idź w górę
                previnput = 'w';
            else if (input == 's' || input == 'S')    // Idź w dół
                previnput = 's';
        }
            // WHILE MOVING LEFT
        else if (previnput == 'a') {
            snakeX[0] -= 1;
            if (input == 'w' || input == 'W')            // Idź w góre
                previnput = 'w';
            else if (input == 's' || input == 'S')    // Idź w dół
                previnput = 's';
        }
    }
}