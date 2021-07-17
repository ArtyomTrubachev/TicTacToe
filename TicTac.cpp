#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

const int N = 3;
int size = N * N;
int randomDirectComputer();
void showMenu();
void showMap(int map[N][N]);
bool checkInput(int map[N][N], int choise, int type);
bool checkWin(int map[N][N], int type);
bool victoryCheckHorVert(int map[N][N], int coordinateX, int coordinateY, int type);
bool victoryCheckDiagonal(int map[N][N], int coordinateX, int coordinateY, int type);
int x = 0;
int y = 0;
int choiseMenu = 0;
int chosetype = 0;

int main()
{
	int map[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	int humanChoise = 0;
	int computerChoise  = 0;
	int cross = 0; 
	int null = -1;
	int crossOrNull = 0;
	int choise = 0;

	srand(time(NULL));
	while (true)
	{
		system("cls");
		showMenu();
		cout << endl << " Your choise: ";
		cin >> choiseMenu;
		cout << endl;
		if (choiseMenu == 0)
			break;
		else if (choiseMenu == 1 or choiseMenu == 2)
		{	
			chosetype = choiseMenu;	
			if (chosetype == 1){
				cross = 0; 
				null = -1;				
			}
			else {
				cross = -1; 
				null = 0;	
			}
			system("cls");
			while (true)
				{	
					while (true)
					{	
						system("cls");
						showMap(map);
						if (choiseMenu % 2 == 1) {
							cout << endl;
							cout << endl << "Your choise: ";
							cin >> humanChoise;	
							choise = humanChoise;
							crossOrNull = cross;									
						}
						else {
							choise = randomDirectComputer();
							crossOrNull = null;	
				
						}

						if (checkInput(map, choise, crossOrNull) == true)
						{
							size--;
							break;							
						}
						else 
							if (choiseMenu % 2 == 1) {
								cout << "Wrong position selected. Please try choose again among the specified numbers";
								Sleep(1500);					
							}	
					}			
					if (checkWin(map, crossOrNull) == true) {
						system("cls");
						showMap(map);
						if (chosetype == 1) {
							if (crossOrNull == cross) {
								cout << endl << "X - the winner!";
								getch();
								return 0;							
							}
							else {
								cout << endl << "O - the winner!";		
								getch();
								return 0;							
							}
						}
						else {
							if (crossOrNull == cross) {
								cout << endl << "O - the winner!";
								getch();
								return 0;							
							}
							else {
								cout << endl << "X - the winner!";		
								getch();
								return 0;							
							}						
						}
					}
					if (size == 0 and victoryCheckHorVert(map, x, y, crossOrNull) == false and victoryCheckDiagonal(map, x, y, crossOrNull) == false) {
						system("cls");
						showMap(map);
						cout << endl << "The draw!";
						getch();
						return 0;							
					}
					choiseMenu++;	
				}
		}
		else 
		{
			system("cls");
			cout << "Wrong";			
		}
	}
	return 0;
}
void showMenu()
{
	cout << "1 - play with X" << endl;
	cout << "2 - play with O" << endl;	
	cout << "0 - exit" << endl;	
}
void showMap(int map[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			if (map[i][j] == 0) 
				cout << "X ";
			else if (map[i][j] == -1) 
				cout << "0 ";
			else 
				cout << map[i][j] << " ";
	cout << endl;
	}		
}
int randomDirectComputer()
{
	int computerChoise = 0;
	return computerChoise = 1 + rand() % (N * N);	
}
bool checkInput(int map[N][N], int choise, int type)
{
	bool check = false;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
				if (map[i][j] == choise and choise != -1 and choise != 0) {
					map[i][j] = type;
					x = j;
					y = i;	
					check = true;				
				}
	if (check)
		return true;
	else 
		return false;
}
bool checkWin(int map[N][N], int type)
{
	if (victoryCheckHorVert(map, x, y, type) == true)
		return true;			
	if (x == y or x + y == 2)
		if (victoryCheckDiagonal(map, x, y, type) == true)
			return true;	
	if (victoryCheckHorVert(map, x, y, type) != true and victoryCheckDiagonal(map, x, y, type) != true)
		return false;			
}
bool victoryCheckHorVert(int map[N][N], int coordinateX, int coordinateY, int type)
{
	int countHorizontal = 0;
	int countVertical = 0;
	for (int i = 0; i < N; i++) {
		if (map[coordinateY][i] == type)
			countHorizontal++;
		if (map[i][coordinateX] == type)
			countVertical++;	
	}
	if (countHorizontal == N or countVertical == N)
		return true;
	else 
		return false;		
}	
bool victoryCheckDiagonal(int map[N][N], int coordinateX, int coordinateY, int type)
{
	int countFirstDiagonal = 0;
	int countSecondDiagonal = 0;
	for (int i = 0; i < N; i++) {
		if (map[i][i] == type)
			countFirstDiagonal++;
		if (map[abs(i-2)][i] == type)
			countSecondDiagonal++;		
	}
	if (countFirstDiagonal == N or countSecondDiagonal == N)
		return true;
	else {
		return false;
	}		
}	

						
