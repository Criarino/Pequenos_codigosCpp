//Overload em operandos: fazer os operandos padrão terem comportamentos diferentes apenas onde quiser. Usa polimorfismo
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class numero
{
	public:
	string val;//guarda o nome do numero

	void set(string valor) //setando valor
	{
		val=valor;
	}
	string operator +(numero ad)//fazendo overload no operador +
	{
		string aux, lista;
		ifstream list("lista.txt");//lendo o arquivo txt que contém a lista
		if(!list.is_open())
		{
			cout<<"txt não aberto"<<endl;
			throw;
		}
		while (getline(list,aux))//copiando arquivo para o buffer
			lista+=aux+'\n';
		list.close();
		string::size_type primeiro=lista.find(ad.val,0);//operações com string para encontrar os valores
		string::size_type segundo=lista.find(val,0);
		int nume=stoi(lista.substr(primeiro-1,1))+stoi(lista.substr(segundo-1,1));//converte o valor em numero, pesquisa na lista pelo int, depois pega o q tem depois desse int
		string::size_type resultado=lista.find(to_string(nume),0)+1;
		string::size_type auxiliar=lista.find('\n',resultado);
		return lista.substr(resultado,auxiliar-resultado);
	}
};

int main()
{
	string input;
	string::size_type segundo;
	numero prim, seg;
	while(1)
	{
		cout<<"Informe a operação (sem espaços, maiúsculas ou acentuação, apenas soma e o resultado não pode ser maior do que 9):"<<endl;
		cin>>input;
		segundo=input.find("+",0)+1;//pegando numeros de input separadamente
		prim.set(input.substr(0,segundo-2));
		seg.set(input.substr(segundo,string::npos));
		cout<<"\nResultado: "<<prim+seg<<'\n'<<endl;
	}
	return 0;
}
