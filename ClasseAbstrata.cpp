//classe abstrata
#include <iostream>
using namespace std;

class exemplo //essa classe é abstrata
{
	public:
	int i=1; //atributos não podem ser abstratos
	virtual int get()=0; // o =0 é necessário para informar que é puramente abstrata
};

class ex1:public exemplo
{
	public:
	int get() override //o argumento override não é necessário
	{
		return i;
	}
};

class ex2:public exemplo
{
	public:
	int get() override
	{
		return i+1;
	}
};

int main ()
{
	int i;
	ex1 a;
	ex2 b;
	cout<<"O conteúdo de ex1 é: "<<a.get()<<"\nO conteúde de ex2 é: "<<b.get()<<endl;	//polimorfismo
	return 0;
}
