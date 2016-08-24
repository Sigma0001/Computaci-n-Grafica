#ifndef _SINGLETON
#define _SINGLETON

class Singleton {
private:
	Singleton();
	static Singleton *instancia;
	int a, b;
public:
	static Singleton* getInstancia();
	void set(int a, int b);
	int Suma();
	int Rest();
	int Mult();
	int Div();
};
#endif
