#include <iostream>
#include <ctype.h>

using namespace std;

int main (void)
{
  	string linha;
    int soma = 0;
    
    while (getline(cin, linha))
    { 
    	for (int i = 0; i < linha.length() - 1; i++)
    	{
    		if (isalpha(linha[i])) //verifica se nao eh uma letra
    		{
    			soma++;
    			while (isalpha(linha[++i]));
    		}
    	}
    	cout << soma << endl;
    	soma = 0;
    }

	return 0;
}