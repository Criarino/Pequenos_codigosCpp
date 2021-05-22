/*smart pointer=um contêiner que abstrai ponteiros, adicionando operações como auto-desalocação.
funciona como uma classe que faz overload nos operandos
tipos: unique_ptr=Faz com que tenha apenas uma referência a um objeto, mas tem como transferir um objeto de um ponteiro para outro. O objeto é destruído automaticamente quando sai de escopo
shared_ptr=Permite que mais de um ponteiro aponte para o mesmo objeto. Contém um contador para a quantidade de referências, o objeto é destruido automaticamente quando não há mais referencias a ele
weak_ptr=O mesmo que shared_ptr, mas não mantém uma contagem de referências*/
#include <iostream>
#include <memory> //biblioteca que contém os smart pointers
using namespace std;

class recta
{
	public:
	int altura;
	int largura;

	recta(int alt, int lar)
	{
		altura=alt;
		largura=lar;
	}
	int area()
	{
		return altura*largura;
	}
};

int main()
{

	{
		unique_ptr<recta> Retangulo1(new recta(5, 10));
		cout<<"Área do retangulo1: "<<Retangulo1->area()<<endl;
		//unique_ptr<recta> Retangulo1a (Retangulo1);//isso vai dar erro pois unique_ptr só permite uma referência
		unique_ptr<recta> Retangulo1a=move(Retangulo1);//passa o objeto de Retangulo1 para Retangulo1a.
		cout<<"Área do retangulo1a: "<<Retangulo1a->area()<<endl;
		recta *rt1=Retangulo1.get();//copia o endereço do smartptr para um ponteiro comum
		cout<<"Retangulo1 agora aponta para "<<rt1<<endl;//escreve 0, pois um smartptr retorna 0 quando não aponta para nada. Isso significa que o ponteiro Retangulo1 não aponta para mais nada
	}
	//Agora as variáveis Retangulo1 e Retangulo1a não existem mais, e o objeto para o qual apontavam também foi destruído por causa da saída de escopo
	shared_ptr<recta> Retangulo2(new recta(10,10));
	shared_ptr<recta> Retangulo2a;
	Retangulo2a=Retangulo2;
	cout<<"Área do retangulo2: "<<Retangulo2->area()<<endl;
	cout<<"Área do retangulo2a: "<<Retangulo2a->area()<<endl;
	cout<<"Quantidade de referências ao segundo retangulo: "<<Retangulo2.use_count()<<endl;
	return 0;
	//com o término da função (nesse caso a main) não há mais nenhuma variável apontando para o segundo retangulo, sendo assim o objeto foi destruído
}
