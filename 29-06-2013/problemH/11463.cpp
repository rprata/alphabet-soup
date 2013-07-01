#include <queue>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

#define MAXINT (0x3f) //MAXINT < maior valor inteiro para que MAXINT + x não fique negativo 
#define MAXN 101 //Número de Vértices máximo
int DM[MAXN][MAXN], n, m;
int soma_inicio, soma_fim;

using namespace std;

int T;
int u, v;
int inicio, fim;

int main (void)
{
	cin >> T;
	
	for(int teste = 1; teste <= T; teste++)
	{
		soma_fim = soma_inicio = 0;
		memset(DM, 0x3f, sizeof(DM));  
		
		cin >> n >> m;
		
		for(int i = 1; i <= m; i++) 
		{
			cin >> u >> v;
			DM[v + 1][u + 1] = 1;
			DM[u + 1][v + 1] = 1;
        }

        cin >> u >> v;
		inicio = u + 1;
		fim = v + 1;
        
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    DM[i][j] = min(DM[i][j], DM[i][k] + DM[k][j]);
        for(int i=1; i<=n; i++) DM[i][i]=0; 

        int soma_maxima = DM[inicio][1] + DM[fim][1];
        for(int i=2; i<=n; i++)
        {

        	if (soma_maxima < DM[inicio][i] + DM[fim][i])
        		soma_maxima = DM[inicio][i] + DM[fim][i];
        }
        cout << "Case " << teste << ": " << soma_maxima << endl;
	}


	return 0;
}