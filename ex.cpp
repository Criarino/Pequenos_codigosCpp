#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main()
{
	int a=0,i;
	while (a==0)
	{
		i=rand()%8;
		while (i>0)
		{
			cout<<'\t';
			i--;
		}
		cout<<"pudim"<<endl;
		sleep(1);
	}
	return 0;
}
