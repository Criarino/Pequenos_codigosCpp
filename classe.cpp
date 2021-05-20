#include <iostream>
using namespace std;

class pessoa
{
	private:
	string nome;
	int idade;
	public:
	/*pessoa(string n, int i) //construtor
	{
		nome=n;
		idade=i;
	}*/
	void set(string n, int i) //seta os atributos
	{
		nome=n;
		idade=i;
	}
	void Falar() //faz output dos atributos
	{
		cout<<"\nMeu nome é "<<nome<<"\nMinha idade é "<<idade<<endl;
	}
	
};
class Adm: public pessoa
{
	private:
	int senha=123;
	public:
	void Falarsenha()
	{
		cout<<"A senha é "<<senha<<endl;
	}
};

int main()
{
	Adm p1;
	string nome;
	int i;
	cout<<"Digite o nome da pessoa"<<endl;
	cin>>nome;
	cout<<"Digite a idade da pessoa"<<endl;
	cin>>i;
	//pessoa p1 (nome, i); //passando parametros para o construtor
	p1.set(nome, i);
	p1.Falar();
	p1.Falarsenha();
	/*{	//Manipulando diretamente
	p1.nome=nome;
	p1.idade=i;
	cout<<"\nO nome da pessoa é "<<p1.nome<<"\nA idade da pessoa é "<<p1.idade<<endl;
	}*/
	return 0;
}
