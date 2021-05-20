//    __   __        __   __   __    __
//   |__| |__| \  / |  | |__| |__   |__| \  / |
//   |  | | \   \/  |__| | \  |__   |  |  \/  |__
//

#include <iostream>
#include <unistd.h> //para o comando sleep()
using namespace std;

struct no
{
	int nv; //nv recebe o nível em que este nó está na árvore
	int ch;
	no *esq, *dir, *an; //an recebe o endereço do nó anterior
};

struct ar
{
	no *raiz=NULL;
	void ins(int ch); //função de inserção
	void imp(no *at, int vez); //impressão legal em formato de árvore
	void impchpro(no *at); //impressões chatas pre-ordem, em-ordem e pos-ordem
	void impcheo(no *at);
	void impchpo(no *at);
	no* bus(int ch); //função de busca
	int fb(no *at, int v); //função para calculo de fator de balanceamento
	void rot (no *at, int f); //função de rotação
};

void ar::ins(int ch)
{
	no *novono; //inserção igual a lista encadeada
	novono=new no;
	novono->ch=ch;
	novono->dir=NULL;
	novono->esq=NULL;
	int nv=0; //para atribuir o nivel do nó na variável nv do proprio no
	if (raiz==NULL)
	{
		novono->an=NULL;
		novono->nv=0;
		raiz=novono;
	}
	else
	{
		no *at;
		at=raiz;
		while (at!=NULL)
		{
		nv++;
			if (ch<at->ch)
			{
				if (at->esq==NULL)
				{
					novono->an=at;
					novono->nv=nv;
					at->esq=novono;
					break;
				}
				at=at->esq;
			}
			else
			{
				if (at->dir==NULL)
				{
					novono->an=at;
					novono->nv=nv;
					at->dir=novono;
					break;
				}
				at=at->dir;
			}
		}
	}
	cout<<"\n\t\t//Elemento inserido//\n"<<endl;
}

void ar::imp(no *at, int vez) //!!PS!!: A impressão legal só funciona até o segundo nível da árvore. Para imprimir árvores maiores use os métodos chatos
{
	no *ante=NULL;
	if (vez==0)
	{
		at=raiz;
		cout<<"\t\t\t|"<<at->ch<<"|\n"<<'\t';
	}
	ante=at->dir;
	at=at->esq;
	if (at!=NULL)
	{
		cout<<'|'<<at->ch<<'|';
		if (vez==1)
			cout<<"\t\t";
	}
	if (ante!=NULL)
	{
		if (vez==0)
			cout<<"\t\t\t\t";
		if ((vez==0)&&(at==NULL))
			cout<<" ";
		if ((at==NULL)&&(vez==1))
			cout<<"\t\t";
		cout<<'|'<<ante->ch<<'|';
	}
	vez++;
	if ((at!=NULL)&&(vez==1))
	{
		cout<<"\n";
		ar::imp(at, vez);
		if ((at->esq==NULL)&&(at->dir==NULL))
			cout<<"\t\t";
	}
	if ((ante!=NULL)&&(vez==1))
	{
		if((at==NULL)&&(vez==1))
			cout<<"\n\t\t";
		cout<<"\t\t";
		ar::imp(ante, vez);
	}
}

no* ar::bus(int ch)
{
	no *at;
	if (raiz==NULL)
	{
		cout<<"Árvore vazia!"<<endl;
		return NULL;
	}
	at=raiz;
	while (at!=NULL)
	{
		if (at->ch==ch)
		{
			cout<<"\n\t\t//Elemento existente//\n"<<endl;
			return at;
		}
		else if (ch>at->ch)
			{
				at=at->dir;
			}
			else if (ch<at->ch)
				{
					at=at->esq;
				}

		if (at==NULL)
		{
			cout<<"\n\t\t//Elemento inexistente//\n"<<endl;
			return NULL;
		}
	}
}

int main()
{
	ar a;
	int res, ch, na=0;
	no *aux;
	while (na==0)
	{
		cout<<"\tO que deseja fazer?\n\n1-Inserir elemento\n2-Imprimir árvore\n3-Pesquisar chave\n4-Terminar\n\n5-Imprimir do jeito chato pré-ordem\n6-Imprimir do jeito chato em-ordem\n7-Imprimir do jeito chato pós-ordem\n8-Calcular fator de balanceamento de um nó\n9-Rotacionar um nó\n10-Fazer uma rotação dupla"<<endl;
		cin>>res;
		switch (res)
		{
			case 1:
				cout<<"Insira a chave: ";
				cin>>ch;
				a.ins(ch);
				sleep(1); // o comando sleep dá uma pequena pausa após exibir o resultado
				break;
			case 2:
				cout<<'\n';
				a.imp(NULL,0);
				cout<<"\n\n";
				sleep(2);
				break;
			case 3:
				cout<<"Insira a chave: ";
				cin>>ch;
				aux=a.bus(ch);
				sleep(1);
				break;
			case 4:
				return 0;
				break;
			case 5:
				cout<<'\n';
				if (a.raiz==NULL)
					cout<<"Árvore vazia!";
				else
					a.impchpro(a.raiz);
				cout<<'\n';
				sleep(1);
				break;
			case 6:
				cout<<'\n';
				if (a.raiz==NULL)
					cout<<"Árvore vazia!";
				else
					a.impcheo(a.raiz);
				cout<<'\n';
				sleep(1);
				break;
			case 7:
				cout<<'\n';
				if (a.raiz==NULL)
					cout<<"Árvore vazia!"<<endl;
				else
					a.impchpo(a.raiz);
				cout<<'\n';
				sleep(1);
				break;
			case 8:
				cout<<"Qual nó deseja calcular?"<<endl;
				cin>>ch;
				aux=a.bus(ch);
				if (aux!=NULL)
				{
					ch=a.fb(aux, 0);
					cout<<"\nO fator de balanceamento é "<<ch<<"\n\n";
				}
				sleep(1);
				break;
			case 9:
				cout<<"Qual nó deseja rotacionar?"<<endl;
				cin>>ch;
				aux=a.bus(ch);
				if (aux!=NULL)
				{
					ch=a.fb(aux, 0);
					if ((ch==0)||(ch==1)||(ch==-1))
						cout<<"\n\tRotação não necessária"<<endl;
					else
						a.rot(aux, ch);
				}
				sleep(1);
				break;
			case 10:
				cout<<"Qual nó deseja rotacionar?"<<endl;
				cin>>ch;
				cout<<"Você deseja:\n1-Dupla rotação à esquerda\n2-Dupla rotação à direita"<<endl;
				cin>>res;
				aux=a.bus(ch);
				if (aux==NULL)
					cout<<"Erro"<<endl;
				else
					if (res==1)
					{
						a.rot(aux, 1);
						aux=aux->esq;
						a.rot(aux, -1);
					}
					else
					{
						a.rot(aux, -1);
						aux=aux->dir;
						a.rot(aux, 1);
					}
				cout<<"\n\tRotação concluída"<<endl;
				sleep(1);
		}
	}
	return 0;
}

void ar::impchpro(no *at)
{
	cout<<at->ch<<" ";
	no *ant=at->dir;
	if (at->esq!=NULL)
	{
		at=at->esq;
		ar::impchpro(at);
	}
	if (ant!=NULL)
	{
		ar::impchpro(ant);
	}
}

void ar::impcheo(no *at)
{
	no *ant=at->dir, *aux=at;
	if (at->esq!=NULL)
	{
		at=at->esq;
		ar::impcheo(at);
	}
	cout<<aux->ch<<' ';
	if (ant!=NULL)
	{
		ar::impcheo(ant);
	}
}

void ar::impchpo(no *at)
{
	no *ant=at->dir, *aux=at;
	if (at->esq!=NULL)
	{
		at=at->esq;
		ar::impchpo(at);
	}
	if (ant!=NULL)
	{
		ar::impchpo(ant);
	}
		cout<<aux->ch<<' ';
}

int ar::fb(no *at, int v) //calculo de fator de balanceamento, recebe o nó base como parametro
{
	int b=0, a=0, f;
	no *ant=at->dir;
	no *prox=at->esq;
	if (v==0)
	{
		a=at->nv; //correção da correção :-P
		b=at->nv;
	}
	if (prox!=NULL)
	{
		a=ar::fb(prox, v+1); //retorna a maior altura da subarvore da esquerda
	}
	if (v!=0) //para garantir que não execute no primeiro ciclo
	{
		if (ant!=NULL)
		{
			b=ar::fb(ant, v+1); //retorna a maior altura da subarvore da direita
		}
		if ((ant==NULL)&&(prox==NULL)) //identifica nós folha
		{
			f=at->nv;
			return f;
		}
		if (a>b) //executa apenas em nós anteriores aos nós folha, após terem recebido a altura de suas respectivas sub-árvores
			return a;
		else
			return b;
	}
	if (ant!=NULL) //isso vai executar apenas uma vez, no primeiro ciclo
	{
		b=ar::fb(ant, v+1);
	}
	int aux1;
	aux1=at->nv; //correção de níveis
	a=a-aux1;
	b=b-aux1;
	return a-b;
}

void ar::rot (no *at, int f) //função para rotação, recebe o nó que quer rotacionar e o fb deste nó
{
	no *aux1, *aux2, *aux3;
	if (f<0) //caso o fb seja negativo, faz rotação à esquerda
	{
		aux1=at->dir;
		aux2=aux1->esq;
		if (at==raiz)
			raiz=aux1;
		else
		{
			aux3=at->an;
			if (aux3->dir==at)
				aux3->dir=aux1;
			else
				aux3->esq=aux1;
		}
		aux1->esq=at;
		at->an=aux1;
		at->dir=aux2;
		if (aux2!=NULL)
			aux2->an=at;
	}
	if (f>0) //caso o fb seja positivo, faz rotação à direita
	{
		aux1=at->esq;
		aux2=aux1->dir;
		if (at==raiz)
			raiz=aux1;
		else
		{
			aux3=at->an;
			if (aux3->dir==at)
				aux3->dir=aux1;
			else
				aux3->esq=aux1;
		}
		aux1->dir=at;
		at->an=aux1;
		at->esq=aux2;
		if (aux2!=NULL)
			aux2->an=at;
	}
	cout<<"\t\t\nRotação realizada\n\n";
}
