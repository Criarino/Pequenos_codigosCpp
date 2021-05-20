//Exemplo Map
//Maps são associações de chaves e valores. As chaves são sempre organizadas no momento da inserção, de acordo com um objeto de comparação (key_compare, parecido com java).Tem vários construtores, podendo copiar outro map em sua declaração, ou copiar uma lista. Tem como contar (map.count()) e encontrar um valor (map.find() - retorna um iterador para esse elemento)
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<char,int> teste; //declarando um map
	teste['c']=1;//adicionando elementos
	teste['b']=2;
	teste['a']=3;
	map<char, int>::iterator it;//cria um iterador (única maneira de acessar os elemntos
   	for(it=teste.begin(); it!=teste.end(); ++it)//iterador recebe primeira posição; enquanto o iterador for diferente da última posição; incrementa iterador
   	{
      cout << it->first << " => " << it->second << '\n';//primeira parte do elemento (chave), segunda parte do elemento (valor)
   	}
	return 0;
	
}
