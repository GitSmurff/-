#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;

const int sz = 5;

struct List_st {
	int mas[sz];
	int lastp = 0;
};
void init(List_st *);
void add(List_st *);
void deleteP(List_st *);
void SearchP(List_st *);
void SearchEl(List_st *);
void print(List_st *);
void clearsp(List_st *);
int menu() {
	int var;
	cout << "Выберите вариант: \n" << endl;
	cout << "1. Инициализация списка\n"
		<< "2. Добавление элемента в список по позиции\n"
		<< "3. Удаление элемента из списка по позиции\n"
		<< "4. Поиск элемента по позиции\n"
		<< "5. Поиск элемента по значению\n"
		<< "6. Вывод элементов списка\n"
		<< "7. Удаление списка\n"
		<< "8. Выйти\n" << endl;
	cout << ">>> ";
	cin >> var;
	return var;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List_st *x = new List_st;
	int var;
	do {
		var = menu();
		switch (var) {
		case 1:
			init(x);
			break;
		case 2:
			add(x);
			break;
		case 3:
			deleteP(x);
			break;
		case 4:
			SearchP(x);
			break;
		case 5:
			SearchEl(x);
			break;
		case 6:
			print(x);
			break;
		case 7:
			clearsp(x);
			break;
		case 8:
			cout << "Выход из программы..." << endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			cerr << "Вы выбрали неверный вариант" << endl;
			exit(EXIT_FAILURE);
		}
	} while (var != 0);
	system("pause");
	return 0;
}

void init(List_st *begin) {
	int n;
	cout << "Введите кол-во элементов: " << endl;
	cin >> n;
	if(n > sz){
		cout << "Нет места для такого кол-ва элементов!" << endl;
		cout << "Введите повторно." << endl;
		init(begin);
	}
	else {
		cout << "Ввод элементов: " << endl;
		begin->lastp = n;
		for (int i = 0; i < n; i++) {
			cin >> begin->mas[i];
		}
	}
}

void add(List_st *begin) {
	int pos, el;
	cout << "Введите позицию в которую хотите добавить элемент: ";
	cin >> pos;
	if (pos <= sz - 1 && begin->lastp != sz) {
		cout << "Введите элемент: ";
		cin >> el;
		for (int j = begin->lastp; j > pos; j--) {
			begin->mas[j] = begin->mas[j - 1];
		}
		begin->mas[pos] = el;
		begin->lastp++;
	}
	else {
		cout << "Нет места для добавления!" << endl;
	}
}

void deleteP(List_st *begin) {
	int pos;
	cout << "Введите позицию для удаление элемента: ";
	cin >> pos;
	for (int i = pos; i < begin->lastp - 1; i++) {
		begin->mas[i] = begin->mas[i + 1];
	}
	begin->lastp--;
}

void SearchP(List_st *begin) {
	int k, x=0, z = 0;
	cout << "Введите позицию для поиска элемента: ";
	cin >> k;
	for (int i = 0; i < begin->lastp; i++) {

		if (k == i) {
			z = begin->mas[i];
			x += 1;
			begin->mas[k] = i;
			
		}	
	}
	if(x == 0) cout << "Элемента в позиции № - " << k <<" нет!" << endl;
	else if (x == 1) cout << "Элемента: "<< z << " в позиции № - "  << begin->mas[k] << " есть" << endl;

}

void SearchEl(List_st *begin) {
	int b, i, z = 0, y = 0;
	cout << "Введите нужный элемент: ";
	cin >> b;
	for (i = 0; i < begin->lastp; i++) {
		if (begin->mas[i] == b) {
			y += 1;
			cout << "Индекс(ы) элемента: "<< i << endl;
		}
	}
	if (y == 0) cout << "Такого элеменнта нет" << endl;
}

void print(List_st *begin) {
	int j = -1;
	for (int i = 0; i < begin->lastp; i++) {
		cout << begin->mas[i] << " ";
		j++;
	}
	cout << endl;
	if (j == -1) cout << "Список пуст!" << endl;
}

void clearsp(List_st *begin) {
	delete[]begin;
	begin = NULL;
}
