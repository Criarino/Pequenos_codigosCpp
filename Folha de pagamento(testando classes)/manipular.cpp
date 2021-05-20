#include "folhapag.h"
#include <iostream>
using namespace std;

class manipula //lembrar de sempre colocara classe depois de suas dependências i.e. se a classe B usa/faz referencia à classe A, no código a declaração de A deve vir antes da declaração de B
{
	friend class listar; //classe friend
	private:
	empregado *VE[10];
	int i=-1;
	public:
	
	int maininterface ()
	{
		int res;
		while(1)
		{
			cout<<"\nQual tipo de empregado?\n0-Voltar\n1-Assalariado\n2-Por hora"<<endl;
			cin>>res;
			switch(res)
			{
				case 0:
					return 0;
					break;
				case 1:
					this->inserirassa();
					break;
				case 2:
					this->inserirph();
					break;			
			}
		}
	}
	
	void inserirassa()
	{
		i++;
		assalariado* aux=new assalariado;
		aux->setnome();
		aux->setsalario();
		VE[i]=aux;
		cout<<"\nOperação bem-sucedida"<<endl;
	}
	
	void inserirph()
	{
		i++;
		porhora* aux=new porhora;
		aux->setnome();
		aux->setsalario();
		aux->sethe();
		VE[i]=aux;
		cout<<"\nOperação bem-sucedida"<<endl;
	}
};

class listar
{
	public:
	void exe(manipula* i)
	{
		for(int a=0;a<=(i->i);a++)
		{
			i->VE[a]->tostring();
		}
	}
};
