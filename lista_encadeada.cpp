//lista encadeada, vai aumentando à medida que vai usando
//limitações: custoso para eliminar elementos no meio ou final e para pesquisar/acessar
#include <iostream>
using namespace std;

struct no
{
	int ch;
	no * proximo;
};

struct list
{
	no * pn;
	void criar();
	void inserir(int ch);
	//no * pesquisar(int ch);
	void excluirinicio();
	void imprimir();
};

void list::excluirinicio()
{
	no * temp ;
	if (pn != NULL)
	{
		temp = pn;
		pn=pn->proximo ;
		delete temp ;
	}
}

void list::criar()
{
	pn=NULL;
}

void list::inserir(int ch)
{
	no * novono;
	novono=new no;
	novono->ch=ch;
	novono->proximo=NULL;
	if(pn==NULL)//caso lista vazia
	{
		pn=novono;
	}
	else
	{
		no*ultimo;
		ultimo=pn;
		while (ultimo->proximo!=NULL)
			ultimo=ultimo->proximo;
		ultimo->proximo=novono;
	}
}

void list::imprimir()
{
	no*atual;
	atual=pn;
	cout<<"Lista completa: "<<endl;
	while (atual)
	{
		cout<<atual->ch<<'|';
		atual=atual->proximo;
	}
	cout<<endl;
}

int main ()
{
	list a;
	int b=0, c=0;
	a.criar();
	while (b!=-1)
	{
		cout<<"insira o elemento"<<endl;
		cin>>b;
		if (b==-1)
			break;
		a.inserir(b);
		c++;
	}
	a.imprimir();
	cout<<"a lista tem "<<c<<" elementos"<<endl;
	return 0;
}
