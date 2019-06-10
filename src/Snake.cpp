#include <iostream>										 
#include <conio.h>										 
#include <windows.h>					 				 
#include <ctime>						 				
#include <vector>										
#include <fstream>									     
#include <string>

using namespace std;
#define WIDTH 20									
#define HEIGHT 20									
char Level[HEIGHT][WIDTH];


// Deklaracja funkcji
void Initialize(int rozmiar, int snakeX[], int snakeY[]);
void ClearScreen();																							
void BudowaPoziomu();																							
void RysunekPlanszy();																								
void Poruszanie(int &rozmiar, int snakeX[], int snakeY[], int tempX[], int tempY[], int &item_count, int &punkty); 
void PredkoscPoruszania(){}
void Pozycje(vector<int> &itemX, vector<int> &itemY, int &item_count, int snakeX[], int snakeY[], int &rozmiar, int tailX, int tailY, int &punkty){}
bool IsGameOver(int snakeX[], int snakeY[], int rozmiar);														
void bialy(){}
void magnetowy(){}
void PodMenu(){}
void Menu();																								
void snake();																								
void Opcje();																								
void Aktywne();																								
void Nieaktywne();																							
void GameOver();																							
void Gwiazdka(){}
void Gwiazdka2(){}
void Sterowanie();																							


// ZMIENNE
int n = 1, z;											
int m = 1;												
int o = 1;												
int p = 1;												
int r = 1;											
int x = 1;												
int nieaktywny = 1;									
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

// Inicjalizacja Węża
void Initialize(int rozmiar, int snakeX[], int snakeY[])
{
    snakeX[0] = WIDTH/2;	snakeY[0] = 3;				// Wymiary Węża
    snakeX[1] = WIDTH/2;	snakeY[1] = 2;
    snakeX[2] = WIDTH/2;	snakeY[2] = 1;
    for(int i=3; i< 100; i++)
    {
        snakeX[i] = NULL;
        snakeY[i] = NULL;
    }
    char waz = 219;
    // Pozycja węża
    for(int i=0; i<rozmiar; i++)
        Level[snakeY[i]][snakeX[i]] = waz ;
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
    //int count = 0;
    char input = (char)219;
    char previnput = 's';
    int tailX, tailY;
    bool gameOver = false;
    vector<int> itemX, itemY;

    while (!gameOver)                                    
    {
        PredkoscPoruszania();                                    

        // Dodanie ogona podczas poruszania
        tailY = snakeY[rozmiar - 1];
        tailX = snakeX[rozmiar - 1];

        // Usunięcie poprzednich śladów po ogonie
        Level[tailY][tailX] = ' ';
        Pozycje(itemX, itemY, item_count, snakeX, snakeY, rozmiar, tailX, tailY, punkty);

        // Kopia węża (z wyjątkiem ogona) do tablicy temp
        // Zostawienie pierwszego elementy
        for (int i = 0; i < rozmiar - 1; i++) {
            tempX[i + 1] = snakeX[i];                       
            tempY[i + 1] = snakeY[i];                       
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
            snakeY[0] += 1;                                
            if (input == 'a' || input == 'A')            
                previnput = 'a';
            else if (input == 'd' || input == 'D')    
                previnput = 'd';
        }
            // WHILE MOVING UP
        else if (previnput == 'w') {
            snakeY[0] -= 1;                                
            if (input == 'a' || input == 'A')       
                previnput = 'a';
            else if (input == 'd' || input == 'D')    
                previnput = 'd';
        }
            // WHILE MOVING RIGHT
        else if (previnput == 'd') {
            snakeX[0] += 1;                                
            if (input == 'w' || input == 'W')        
                previnput = 'w';
            else if (input == 's' || input == 'S')   
                previnput = 's';
        }
            // WHILE MOVING LEFT
        else if (previnput == 'a') {
            snakeX[0] -= 1;
            if (input == 'w' || input == 'W')           
                previnput = 'w';
            else if (input == 's' || input == 'S')   
                previnput = 's';
        }
    }
}

int main()
{
}
