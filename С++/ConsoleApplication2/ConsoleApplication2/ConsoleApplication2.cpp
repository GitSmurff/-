
#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
char* f(char* s, char** e) {
	char* p, *i, *j;
	while (*s != 0) {
		p = s + 1;
		while (*p != 0) {
			if (*p == *s && *(p + 1) == *(s + 1))
				break;
			p++;
		}
		if ((p - s) > 1) {
			i = s;
			j = p;
			while (*i && (*i == *j)) {
				j++;
				i++;
			}

			if (i == p) {
				if (e != 0)
					*e = j;
				return s;
			}
		}
		s++;
	}
	return 0;
}
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* p, *e;
	int size = 256;
	char* s = new char[size];
	cin.getline(s, size);
	p = f(s, 0);
	cout << "\n"<< "Все пары: " << endl;
	for (p = &s[0]; (p = f(p, &e)) != 0; p = e) {
		while (p != e)
			cout << *p++;
		cout << endl;
	}
	system("pause");
	return 0;
}