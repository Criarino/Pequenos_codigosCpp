//pilha, so ocorre remocao e insercao no topo - lista encadeada ao contrario
#include <iostream>
using namespace std;

struct no
{
	no *ant=NULL;
	int elem;
};

struct pil
{
	no *topo=NULL;
	void colocar(int elem);
	void tirar();
	void imprimir ();
};

void pil::colocar(int elem)
{
	no * novono;
	novono=new no;
	novono->elem=elem;
	if (topo!=NULL)
	{
		novono->ant=topo;
	}
	topo=novono;
}

void pil::tirar()
{
	if (topo!=NULL)
	{
	int r;
	cout<<"\n\t//Deseja eliminar o elemento "<<topo->elem<<"? Digite 1 para sim e 0 para não\\\\"<<endl;
	cin>>r;
	if (r==1)
	{
		no * temp;
		temp=topo;
		topo=topo->ant;
		delete temp;
		cout<<"\n//Elemento excluído\\\\"<<endl;
	}
	else
	{
		cout<<"\n//Exlusão cancelada\\\\"<<endl;
	}
	}
	else
		cout<<"\npilha vazia"<<endl;
}

void pil::imprimir()
{
	no * aux=topo;
	cout<<"\n\t//Pilha completa, do último inserido para o primeiro:\\\\\n\n\t| ";
	while (aux!=NULL)
	{
		cout<<aux->elem<<" | ";
		aux=aux->ant;
	}
}

int main()
{
	int b, elem;
	pil a;
	while (b!=1)
	{
		cout<<"\nDigite 0 para inserir um elemento\nDigite 1 para terminar\nDigite 2 para retirar o ultimo elemento inserido\nDigite 3 para imprimir a pilha"<<endl;
		cin>>b;
		switch (b)
		{
			case 0:
				cout<<"\n\tDigite o elemento\n\t";
				cin>>elem;
				a.colocar(elem);
				break;
			case 1:
				return 0;
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
