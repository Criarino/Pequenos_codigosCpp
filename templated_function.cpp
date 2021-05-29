/*Templates são usados em programação genérica. Um template serve para declarar um novo tipo (com o nome que você escolheu, mais comumente T) que pode ser qualquer outro tipo. É parecido com o auto, em que o compilador olha todas as vezes que essa função foi chamada no codigo e faz uma cópia da função para cada tipo de parâmetro diferente
Default Arguments with Function Templates
*/
#include <iostream>
using namespace std;

template<typename T> //usar sempre typename. "T" é como um novo tipo de variavel
double media(T tArray[], int nElements) //é possível retornar um template tbm: T media()
{ //é possível usar ponteiros e referencias da mesma maneira que com tipos normais (poderia declarar T& para receber a referência)
    T tSum = T(); //chama o construtor padrão de um tipo/classe. No caso de int, por exemplo int i=int() é o mesmo que int i=0

    for (int nIndex = 0; nIndex < nElements; ++nIndex)
    {
        tSum += tArray[nIndex];
    }

    //sempre retorna como double
    return double(tSum) / nElements;
}


int main()
{
    int  IntArray[5] = {100, 200, 400, 500, 1000}; //um vetor de inteiros
    float FloatArray[3] = { 1.55f, 5.44f, 12.36f}; //um vetor de float

    cout << media(IntArray, 5)<<endl; //chama a função passando um int como argumento
    cout << media(FloatArray, 3)<<endl; //chama a função passando um float como argumento
    //tem como forçar o compilador a instanciar a função usando um tipo especifico: media<double>(IntArray, 5). Com isso, ao invés de instanciar a função como double media (int tArray[], int nElements), o argumento tArray vai ser double. De maneira similar para quando tem dois argumentos template media<double, double>()
}
