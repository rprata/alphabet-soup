#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>

#define MAX 30
using namespace std;

int E[MAX][MAX], Pre[MAX], Pos[MAX], D[MAX], DU[MAX], n, m, os, oe, u, v;

void BP(int u, int v)
{
    Pre[v]=++oe;
    for(int i = 1; i <= n; i++)
        if ((E[v][i]==1)&&(Pre[i]==0))
            BP(v, i);
    os++; Pos[n-os+1]=v;  
}

void insereDadoMatrizAdj(int u, int v)
{
	E[u - 'A' + 1][v - 'A' + 1] = 1;
}

int N, peso, maximo;

char aresta;
string s, precedencia;
stringstream ss;

int main (void)
{

	cin >> N;

	for (int k = 1; k <= N; k++)
	{
		memset(E, 0, sizeof(E)); memset(Pre, 0, sizeof(Pre));  
    	memset(Pos, 0, sizeof(Pos));  memset(D, 0, sizeof(Pre)); 
    	memset(DU, 0, sizeof(DU)); 

		cin >> aresta >> peso;

		getline(cin, s);
		 
		n = 1;
		DU[n] = peso;

		while (getline(cin, s))
		{
			//generate MA
			if (s.empty())
				break;

			n++;			
			ss.clear();
			ss.str(s);
			ss >> aresta >> peso >> precedencia;

			DU[n] = peso;

			for (int j = 0; j <= precedencia.length() - 1; j++)
			{
				insereDadoMatrizAdj(precedencia[j], aresta);
			}
		}

		oe=os=0;
        for(int i=1; i<=n; i++)
            if (Pre[i]==0) BP(0,i);

        for (int i = 1; i <= n; i++)
			D[i] = DU[i];

		for(int i=n; i>0; i--)
			for (int j=1; j<=n; j++)
			{
			    if ((E[j][Pos[i]]==1) && (D[j] <= DU[j] + D[Pos[i]]))
			    {
					D[j] = DU[j] + D[Pos[i]];  	
			    }  
			}
		
		maximo = 0;

		for (int i = 1; i <= n; i++)
		{
			if (D[i] > maximo)
				maximo = D[i];
		}

        cout << maximo << endl;
    	if (k < N) cout << endl;

	}

	return 0;
}
