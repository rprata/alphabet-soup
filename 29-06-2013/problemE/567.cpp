#include <queue>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

#define MAXINT (0x3f3f3f3f) //MAXINT < maior valor inteiro para que MAXINT + x não fique negativo 
#define MAXN 21 //Número de Vértices máximo
int DM[MAXN][MAXN], n, m;

using namespace std;

int numero_de_conexoes;
int query;
int vertice;
int s, f;
int test = 1;

int main (void)
{
	n = 20;
	while (cin >> numero_de_conexoes)
	{ 
		memset(DM, 0x3f, sizeof(DM));   
	
		for (int i = 1; i <= 19; i++) //insere caminhos
		{
			for (int j = 1; j <= numero_de_conexoes; j++)
			{
				cin >> vertice;
				DM[i][vertice] = 1;				
				DM[vertice][i] = 1;				
			}
			cin >> numero_de_conexoes;
		}

		query = numero_de_conexoes;
		
		//FLOYD
        for(int k = 1; k <= n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    DM[i][j] = min(DM[i][j], DM[i][k] + DM[k][j]);

        for(int i = 1; i <= n; i++) DM[i][i]=0;         

        cout << "Test Set #" << test << endl;
		for(int k = 0; k < query; k++)
		{
			cin >> s >> f;
			printf("%2d to %2d: %d\n", s, f, DM[s][f] );
			//cout << s << " to " << f << ": " << DM[s][f] << endl;
		}

		cout << endl;
		test++;
	}

	return 0;
}