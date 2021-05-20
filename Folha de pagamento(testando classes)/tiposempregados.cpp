#include <iostream>
using namespace std;

class empregado
{	
	private:
	string nome;
	public:
	void setnome()
	{
		string nom;
		cin.ignore();
		cout<<"\nInforme o nome"<<endl;
		getline(cin,nom);
		nome=nom;
	}
	string getnome()
	{
		return nome;
	}
	virtual void tostring()=0;
};

class assalariado : public empregado
{
	private:
	double salario;
	public:
	void setsalario ()
	{
		double sal;
		cout<<"\nInforme o salario"<<endl;
		cin>>sal;
		salario=sal;
	}
	double getsalario()
	{
		return salario;
	}
	void tostring ()
	{
		cout<<'\n'<<this->getnome()<<"\nTipo: Assalariado\nSalário: "<<this->getsalario()<<endl; 
	}//sempre que acessar um atributo ou função dentro de uma struct/classe via ponteiro, usa-se -> ao invés de ponto
};

class porhora : public assalariado
{
	private:
	int he;
	double bonus;
	public:
	void sethe()
	{
		int h;
		cout<<"\nInforme o numero de horas extras"<<endl;
		cin>>h;
		he=h;
		bonus=(this->getsalario()/40)*0.5;
	}
	int gethe()
	{
		return he;
	}
	void tostring()
	{
		cout<<'\n'<<this->getnome()<<"\nTipo: Hora extra\nSalário base: "<<this->getsalario()<<"\nSalario + bonus: "<<this->getsalario()+bonus<<endl;
	}
};
