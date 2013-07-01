#include <queue>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <map>

#define MAXINT (0x3f3f3f3f) //MAXINT < maior valor inteiro para que MAXINT + x não fique negativo 
#define MAXN 101 //Número de Vértices máximo

using namespace std;

int DM[MAXN][MAXN], n, m;
int a, b;
int soma;

int counter;
int caseTest = 1; 
int contador_vertices;


map<int,int> vertice;

int main (void)
{
	while (true)
	{
		n = counter = 0;
		memset(DM, 0x3f, sizeof(DM)); 

		vertice.clear();
		contador_vertices = 0;

		while (cin >> a >> b, a)
		{
			counter++;
			if (vertice.count(a) == 0)
			{
				contador_vertices++;
				vertice[a] = contador_vertices;
			}

			if (vertice.count(b) == 0)
			{
				contador_vertices++;
				vertice[b] = contador_vertices;
			}

			DM[vertice[a]][vertice[b]] = 1;
		}

		if (!counter) return 0;

		n = contador_vertices;
		soma = 0;

		//FLOYD
        for(int k = 1; k <= n; k++)
            for(int i=1; i <= n; i++)
                for(int j=1; j<=n; j++)
                {
                    DM[i][j]= min(DM[i][j], DM[i][k] + DM[k][j]);
                }

        for(int i = 1; i <= n; i++) DM[i][i] = 0;
        
    	for(int i = 1; i <= n; i++)
	    	for(int j = 1; j <= n; j++)
            	soma += DM[i][j];

        printf("Case %d: average length between pages = %.3lf clicks\n", caseTest,(double) soma/(n*(n-1)));
		caseTest++;

	}
	return 0;
}