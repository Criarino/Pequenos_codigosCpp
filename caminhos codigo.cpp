#include <iostream>
using namespace std;

int main()
{
    int men1; //0=mentiroso 1=verdadeiro
    int sp1;
    cout<<"Eu sou um viajante, em certo momento chego a uma bifurcação no caminho.\nSem saber qual lado leva à cidade, pergunto a uma pessoa que passava, você...\nPorém eu me lembro de uma velha história,\nque dizia que alguns dos habitantes daquela regiao sempre falavam mentiras.\nA fim de saber qual o caminho, faço 2 perguntas:\nResponda às perguntas com \"1\" para sim ou \"0\" para não"<<endl;
    cout<<"Você está respirando neste momento?"<<endl;
    cin>>men1;
    cout<<"O caminho certo é o da direita?"<<endl;
    cin>>sp1;
    if (sp1==0)
    {
        if (men1==1)
        {
            cout<<"Eu pego o caminho da esquerda"<<endl;
        }
        else
        {
            cout<<"Eu pego o caminho da direita"<<endl;
        }
    }
    if (sp1==1)
    {
        if(men1==1)
        {
            cout<<"Eu pego o caminho da direita"<<endl;
        }
        else
        {
            cout<<"Eu pego o caminho da esquerda"<<endl;
        }
    }
}
