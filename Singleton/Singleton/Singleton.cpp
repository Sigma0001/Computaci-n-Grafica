#include "Singleton.h"

Singleton::Singleton(){}

Singleton* Singleton::instancia = nullptr;

Singleton * Singleton::getInstancia()
{
	if (instancia == nullptr)
	{
		instancia = new Singleton();
	}
	return instancia;
}

void Singleton::set(int _a, int _b)
{
	this->a = _a;

	this->b = _b;
}

int Singleton::Suma()
{
	return a + b;
}

int Singleton::Rest()
{
	return a - b;
}

int Singleton::Mult()
{
	return a * b;
}

int Singleton::Div()
{
	return a / b;
}