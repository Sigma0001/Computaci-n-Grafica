#include <iostream>
#include "Singleton.h"

using namespace std;

Singleton *val1, *val2;
float c, d;

int main()
{
	val1 = Singleton::getInstancia();
	val2 = Singleton::getInstancia();
	cout << "Calculadora Singleton" << endl;
	cout << "Ingresa numero 1.-";// << endl;
	cin >> c;
	cout << "Ingresa numero 2.-";// << endl;
	cin >> d;
	val1->set(c,d);
	cout << "\n";
	cout << val2->Suma() << endl;
	cout << val2->Rest() << endl;
	cout << val2->Mult() << endl;
	cout << val2->Div() << endl;
	cin.get();
	return 0;
}

