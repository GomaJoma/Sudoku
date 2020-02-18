#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define N 9		// Размерность таблицы

class Dot {
public:
	int val = 0;		// Значение в ячейке
	int square = 0;		// Номер квадранта, в котором находится ячейка
	int pos_val[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };	// Возможные значения ячейки, если она путсая

	Dot() {};
	Dot(int, int, int);
};

Dot::Dot(int Val, int Square, int Pos_val) {
	this->val = val;
	this->square = square;
	for (int i = 0; i < 9; i++)
		this->pos_val[i] = Pos_val;
}

int GetCurrentSquare(int i, int j);		// Определение номера квадранта таблицы
int GetSquareComparsion(int Num_of_Square, Dot* dot, Dot** Tab[[]]);	// Сравнение текущего элемента с элементами квадранта
void GetStringComparsion(int Num_of_String, Dot* dot, Dot** Tab[[]]);
void GetColumnComparsion(int Num_of_Column, Dot* dot, Dot** Tab[[]]);

int main()
{
	Dot** tab = new Dot*[N];		//
	for (int i = 0; i < N; i++) {	// Создание таблицы
		tab[i] = new Dot[N];		//
	}								//
	
	// Ввод начальной таблицы из файла
	ifstream fin("input.txt");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fin >> tab[i][j].val;
		}
	}// Конец ввода

	// Вывод начальной таблицы
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tab[i][j].val << " ";
			if ((j + 1) % 3 == 0) cout << " ";
		}
		if ((i + 1) % 3 == 0) cout << endl;
		cout << endl;
	}// Конец вывода


	// Определение возможных значений пустых ячеек

	int cur_sqr = -1;		// Переменная отслеживания текущего квадранта
	int test_error = -1;	// Переменная отслеживания сравнения значений в квадранте

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tab[i][j].val == 0) {
				// Сравнение значений в квадранте
				cur_sqr = GetCurrentSquare(i, j);
				test_error = GetSquareComparsion(cur_sqr, &tab[i][j], tab);
				// Сарвнение значений в строке
				// Сравнение значений в столбце
			}
		}
	}


	// Тестирование
	
	// Эхо-печать
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int s = 0; s < 9; s++)
				cout << tab[i][j].pos_val[s] << " ";
			cout << endl;
		}
		cout << endl;
	}

	cout << endl;
	// Конец тестирования
	return 0;
}

int GetCurrentSquare(int i, int j) {
	if ((i == 0) || (i == 1) || (i == 2)) {
		if ((j == 0) || (j == 1) || (j == 2)) return 0;
		else if ((j == 3) || (j == 4) || (j == 5)) return 1;
		else if ((j == 6) || (j == 7) || (j == 8)) return 2;
		else return -1;
	}
	else if ((i == 3) || (i == 4) || (i == 5)) {
		if ((j == 0) || (j == 1) || (j == 2)) return 3;
		else if ((j == 3) || (j == 4) || (j == 5)) return 4;
		else if ((j == 6) || (j == 7) || (j == 8)) return 5;
		else return -2;
	}
	else if ((i == 6) || (i == 7) || (i == 8)) {
		if ((j == 0) || (j == 1) || (j == 2)) return 6;
		else if ((j == 3) || (j == 4) || (j == 5)) return 7;
		else if ((j == 6) || (j == 7) || (j == 8)) return 8;
		else return -3;
	}
	else return -4;
	return 100;
}

int GetSquareComparsion(int Num_of_Square, Dot* dot, Dot** Tab[[]]) {

	if ((Num_of_Square == 0) || (Num_of_Square == 1) || (Num_of_Square == 2))
		for (int i = 0; i < 3; i++) {
			if (Num_of_Square == 0)
				for (int j = 0; j < 3; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else if (Num_of_Square == 1)
				for (int j = 3; j < 6; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else if (Num_of_Square == 2)
				for (int j = 6; j < 9; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else return -1;
		}
	if ((Num_of_Square == 3) || (Num_of_Square == 4) || (Num_of_Square == 5))
		for (int i = 3; i < 6; i++) {
			if (Num_of_Square == 3)
				for (int j = 0; j < 3; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else if (Num_of_Square == 4)
				for (int j = 3; j < 6; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else if (Num_of_Square == 5)
				for (int j = 6; j < 9; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else return -2;
		}
	if ((Num_of_Square == 6) || (Num_of_Square == 7) || (Num_of_Square == 8))
		for (int i = 6; i < 9; i++) {
			if (Num_of_Square == 6)
				for (int j = 0; j < 3; j++) 
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else if (Num_of_Square == 7)
				for (int j = 3; j < 6; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else if (Num_of_Square == 8) 
				for (int j = 6; j < 9; j++)
					dot->pos_val[Tab[i][j].val - 1] = 0;
			else return -3;
		}
	return 1;
}

void GetStringComparsion(int Num_of_String, Dot* dot, Dot** Tab[[]]) {

}

void GetColumnComparsion(int Num_of_Column, Dot* dot, Dot** Tab [[]] ) {

}