//arquivos .h=headers, substitui os prototipos dos arquivos, .cpp=usado para dividir o codigo em arquivos
//g++ manipular.cpp main.cpp tiposempregados.cpp -o exe
#include "main.h" //incluindo header
#include <iostream>
using namespace std;

int main()
{
	int res;
	manipula m1;
	listar l1;
	while(1) //loop infinito
	{
		cout<<"\nO que quer fazer?\n0-Encerrar\n1-Inserir empregado\n2-Ver lista de empregados"<<endl;
		cin>>res;
		switch (res)
		{
			case 0:
				return 0;
				break;
			case 1:
				m1.maininterface();
				break;
			case 2:
				l1.exe(&m1);
				break;
		}
	}
	return 0;	
}
