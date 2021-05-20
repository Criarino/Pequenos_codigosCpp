//fila- pilha que tira de um lado e coloca do outro
#include <iostream>
using namespace std;

struct no
{
	int elem;
	no * prox=NULL;
};

struct fil
{
	no * ultimo=NULL;
	no * primeiro=NULL;
	void tirar();
	void colocar(int elem);
	void imprimir();	
};

void fil::tirar()
{
	if (primeiro==NULL)
	{
		cout<<"Fila vazia"<<endl;
	}
	else
	{
		int a;
		cout<<"\n\tDeseja retirar o elemento "<<primeiro->elem<<"? Digite 1 para sim e 0 para não"<<endl;
		cin>>a;
		if(a==1)
		{
			no * temp;
			temp=primeiro;
			primeiro=primeiro->prox;
			delete temp;
			cout<<"\n\t///Elemento excluído///";
		}
		else
		{
			cout<<"\n\t///Exclusão cancelada///";
		}
	}
}

void fil::colocar(int elem)
{
	no * novono;
	novono=new no;
	novono->elem=elem;
	if (primeiro==NULL)
	{
		primeiro=novono;
	}
	else
		ultimo->prox=novono;
	ultimo=novono;
	cout<<"\n\t///Elemento inserido///";
}

void fil::imprimir()
{
	cout<<"\n\t///Fila completa: ///\n\t| ";
	no * aux=primeiro;
	while (aux!=NULL)
	{
		cout<<aux->elem<<" | ";
		aux=aux->prox;
	}
}

int main()
{
	fil a;
	int b,c;
	for (int i=1;i!=0;)
	{
		cout<<"\n\nDigite 1 para inserir um elemento\nDigite 2 para remover um elemento\nDigite 3 para imprimir a fila\nDigite 0 para encerrar"<<endl;
		cin>>b;
		switch (b)
		{
			case 0:
				return 0;
				break;
			case 1:
				cout<<"\n\n\t\t///Insira o elemento///"<<endl;
				cin>>c;
				a.colocar(c);
				break;
			case 2:
				a.tirar();
				break;
			case 3:
				a.imprimir();
				break;
		}
	}
	return 0;
}
