//Coisas com vetores. Vetores de objetos funcionam (e são declarados) como qualquer outro
#include <iostream>
#include <vector> //adiciona mais operações para vetores e matrizes, parecido com as funções de Object do java (toString, equals, getClass), recomendável pra quando vai alocar vetores dinamicamente, já que tem um desconstrutor (delete) automático
//#include <array> //mesmo que <vector>, mas não pode mudar o tamanho depois de alocado
//constexpr é um tipo const que pode ser aplicado a funções e atributos, a diferença é que constexpr é inicializado em tempo de compilação
using namespace std;

int main()
{

	vector <int>teste1(5,1); //objeto vector, armazena um vetor do tipo int com 5 posições e o preenche com 1. É possível omitir o argumento preencher
	for (int i=0;i<5;i++)
	{
		teste1[i]=i;//após declarado, pode ser usado como um vetor normal
		cout<<teste1[i]<<' ';
	}
	cout<<"\nPrimeiro elemento do vetor: "<<teste1.front()<<endl;
	cout<<"Último elemento do vetor: "<<teste1.back()<<endl;
	cout<<"Tamanho do vetor: "<<teste1.size()<<endl;
	teste1.resize(6);
	cout<<"Tamanho do vetor depois do resize: "<<teste1.size()<<endl;
	cout<<"Capacidade máxima do vetor: "<<teste1.capacity()<<endl;
	teste1.reserve(100);
	cout<<"Capacidade máxima depois de reservar mais espaço: "<<teste1.capacity()<<endl;
	teste1.push_back(5);
	cout<<"Último elemento após adicionar o 5: "<<teste1.back()<<endl;
	/*teste1.insert(it,1);
	cout<<"Primeiro elemento após adicionar o 1: "<<teste1.front()<<endl;*///é complicado
	return 0;
}
