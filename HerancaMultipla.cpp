//herança multipla
#include <iostream>
using namespace std;

class A
{
	public:
	int a=1;
};

class B
{
	public:
	int b=2;
};

class C: public A, public B
{
	public:
	int get()
	{
		return a+b;
	}
};

int main()
{
	C exemplo;
	cout<<"A soma dos valores de ambas as classe é "<<exemplo.get()<<endl;
	return 0;
}
