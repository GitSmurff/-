// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;

const int sz = 8;

struct List_st {
	int mas[sz];
	int lastp = 0;
};
void init(List_st *);
void add(List_st *);
void deletezn(List_st *);
void addafter(List_st *);
void addbefore(List_st *);
void deleteafter(List_st *);
void deletebefore(List_st *);
void minel(List_st *);
void sortsp(List_st *);
void print(List_st *);

int menu() {
	int var;
	cout << "Выберите вариант: \n" << endl;
	cout << "1. Инициализация списка\n"
		<< "2. Добавление элемента в список\n"
		<< "3. Удаление элемента из списка\n"
		<< "4. добавление нового элемента после заданного значения\n"
		<< "5. добавление нового элемента перед заданным элементом\n"
		<< "6. удаление элемента после заданого элемента\n"
		<< "7. удаление элемента перед заданым элементаn\n"
		<< "8. нахождение позиции минимального элемента списка\n"
		<< "9. упорядочение списка\n"
		<< "10. вывод\n"
		<< "11. Выйти\n" << endl;
	cout << ">>> ";
	cin >> var;
	return var;
}
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List_st *x = new List_st;
	int t = 0;
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
			deletezn(x);
			break;
		case 4:
			addafter(x);
			break;
		case 5:
			addbefore(x);
			break;
		case 6:
			deleteafter(x);
			break;
		case 7:
			deletebefore(x);
			break;
		case 8:
			minel(x);
			break;
		case 9:
			sortsp(x);
			break;
		case 10:
			print(x);
			break;
		case 11:
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
	if (n > sz) {
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
	int x, i = 0;
	if (begin->lastp == sz) {
		cout << "Нет места для добавление!" << endl;
	}
	else {
		cout << "Введите значение элемента: ";
		cin >> x;
		while (begin->mas[i] != x)
			i += 1;
		for (int j = begin->lastp; j > i; j--) {
			begin->mas[j] = begin->mas[j - 1];
		}
		begin->lastp++;
	}
}

void deletezn(List_st *begin) {
	int k, i = 0;
	cout << "Введите значение элемента: ";
	cin >> k;
	while (begin->mas[i] != k)
		i += 1;
	for (int j = i + 1; j < begin->lastp; j++) {
		begin->mas[j - 1] = begin->mas[j];
	}
	begin->lastp--;
}


void addafter(List_st *begin) {
	int n, k, i = 0;
	if (begin->lastp == sz) {
		cout << "Нет места для добавление!" << endl;
	}
	else {
		cout << "Введите элемент, который нужно добавить: ";
		cin >> n;
		cout << "Введите число после которого нужно добавить элемент: ";
		cin >> k;
		while (begin->mas[i] != k)
			i += 1;
		for (int j = begin->lastp; j > i + 1; j--) {
			begin->mas[j] = begin->mas[j - 1];
		}
		begin->mas[i + 1] = n;
		begin->lastp++;
	}
}

void addbefore(List_st *begin) {
	int n, k, i = 0;
	if (begin->lastp == sz) {
		cout << "Нет места для добавление!" << endl;
	}
	else {
		cout << "Введите элемент, который нужно добавить: ";
		cin >> n;
		cout << "Введите число перед которым нужно добавить элемент: ";
		cin >> k;
		while (begin->mas[i] != k)
			i += 1;
		for (int j = begin->lastp; j > i - 1; j--) {
			begin->mas[j] = begin->mas[j - 1];
		}
		begin->mas[i] = n;
		begin->lastp++;
	}
}

void deleteafter(List_st *begin) {
	int k, i = 0, t = 0, z=0;
	cout << "Введите элемент для удаление элемента после заданого: ";
	cin >> k;
	for (int j = 0; j < begin->lastp; j++) {
		t = begin->mas[j];
	}
	if (k == t) {
		cout << "Ошибка,это последний элемент!" << endl;
	}
	else {
		while (begin->mas[i] != k) {
			i += 1;
		}
		z = i + 1;
		for (int j = z + 1; j < begin->lastp; j++) {
			begin->mas[j - 1] = begin->mas[j];
		}
		begin->lastp--;
	}
}


void deletebefore(List_st *begin) {
	int k, i = 0, z = 0;
	cout << "Введите элемент для удаление элемента перед заданным: ";
	cin >> k;
	if (k  == begin->mas[0]) {
		cout << "Ошибка, это самый первый элемент!" << endl;
		
	}
	else {
		while (begin->mas[i] != k) {
			i += 1;
		}
		z = i - 1;
		for (int j = z + 1; j < begin->lastp; j++) {
			begin->mas[j - 1] = begin->mas[j];
		}
		begin->lastp--;
	}
}

void minel(List_st *begin) {
	int min, mini = 0;
	min = begin->mas[0];
	for (int i = 0; i < begin->lastp; i++) {
		if (begin->mas[i] < min) {
			min = begin->mas[i];
			mini = i;
		}
	}
	cout << "№ позиции [" << mini << "] , мин число: " << min << endl;
}

void sortsp(List_st *begin) {
	int k, j = -1;
	bool flag;
	do {
		flag = true;
		for (int i = 0; i < begin->lastp - 1; i++) {
			if (begin->mas[i] > begin->mas[i + 1]) {
				k = begin->mas[i];
				begin->mas[i] = begin->mas[i + 1];
				begin->mas[i + 1] = k;
				flag = false;
				j++;
			}
		}
	} while (!flag);
	if (j != -1) 
		cout << "Сортировка прошла успешно!" << endl;
	else 
		cout << "Ошибка!" << endl;
}

void print(List_st *begin) {
	int j = -1;
	for (int i = 0; i < begin->lastp; i++) {
		cout << begin->mas[i] << " ";
		j++;
	}
	cout << endl;
	if (j == -1) cout << "Список Пуст!" << endl;
}




