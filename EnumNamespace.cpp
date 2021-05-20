//Teste de enum e namespace. Significa enumeração, é o mesmo que usar #define com algumas coisinhas a mais
#include <iostream>
using namespace std;

enum
{
	V1=0, //mesmo que fazer #define V1 0. NAO COLOCA ; APENAS ,
	V2, //quando não atribui valor, ele sempre pega o anterior +1
	V3=1,//Não tem problema ser o mesmo valor
	V4,//vai valer 2
}; //não esquecer ;

enum Tipo1//quando coloca nome, vira um tipo de constante assim como #define Tipo1 const int
{
	V5=2,
	V6,
};

namespace Tipo2 //definindo um namespace
{
	enum
	{
		V7=3,
		V8,
	};
}

namespace Tipo3
{
	enum
	{
		V7=4,//não se pode dar o mesmo nome a variaveis enum diferentes, A NAO SER QUE use namespaces
		V8,
	};
}

int main()
{
	cout<<"Primeiros enums: "<<endl<<V1<<endl<<V2<<endl<<V3<<endl<<V4<<endl;
	//V1=0 //ERRO: enums são constantes

	Tipo1 tipo1=V5;
	cout<<"\n'TAD' enums: "<<endl<<tipo1<<endl<<V6<<endl;

	cout<<"\nNamespace enums, Namespace Tipo2: "<<endl<<Tipo2::V7<<endl<<Tipo2::V8<<endl;
	cout<<"Namespace Tipo3: "<<endl<<Tipo3::V7<<endl<<Tipo3::V8<<endl;
	return 0;
}
