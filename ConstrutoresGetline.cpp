//Construtores,getline,acesso via ponteiros
#include <iostream>
using namespace std;

class A
{
	public:
	int x;
	A(int x) //basta ter o mesmo nome e os parenteses
	{
		this->x=x;//quando está acessando algo de uma struct/classe via ponteiros ou usando o this, usa -> ao inves do ponto
	}
};

class B:public A
{
	public:
	int y;
	B(int y,int x):A(x)//se o construtor da superclasse tiver argumentos, deve-se usar essa sintaxe
	{
		//using A::A;//se o construtor da superclasse não tiver argumentos, não precisa chamar explicitamente
		this->y=y;
	}	
};

int main()
{
	/*string a;
	cin.ignore() //limpa o buffer
	getline(cin,a);*///pega o input até uma quebra de linha	
	B teste1(2,1);
	cout<<teste1.x<<' '<<teste1.y<<endl;
	return 0;
}
