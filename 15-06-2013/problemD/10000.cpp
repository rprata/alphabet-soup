#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>

#define MAX 110
using namespace std;

int E[MAX][MAX], Pre[MAX], Pos[MAX], D[MAX], DU[MAX], n, m, os, oe, u, v;

int inicial, vmin, maximo;

void BP(int u, int v)
{
    Pre[v]=++oe;
    for(int i = 1; i <= n; i++)
        if ((E[v][i]==1)&&(Pre[i]==0))
            BP(v, i);
    os++; Pos[n-os+1]=v;  
}

void BP_RESTRITIVA(int u, int v, int d)
{
    if ((d == 0) && (v < vmin))
        vmin = v;

    Pre[v]=++oe;
    for(int i = 1; i <= n; i++)
        if ((E[v][i]==1)&&(Pre[i]==0 && D[i] == d - 1))
            BP_RESTRITIVA(v, i, d - 1);
    os++; Pos[n-os+1]=v;  
}

int main (void)
{
    int p = 0;
	while (true)
	{
        p++;
		cin >> n;

		if (n == 0)
			break;

		memset(E, 0, sizeof(E)); memset(Pre, 0, sizeof(Pre));  
    	memset(Pos, 0, sizeof(Pos));  memset(D, 0, sizeof(Pre)); 

    	cin >> inicial;
    	
    	while (true)
    	{
    		cin >> u >> v;

    		if (u == 0)
    			break;

    		E[u][v] = 1;
    	}

    	oe=os=0;

        for(int i=1; i<=n; i++)
            if (Pre[i]==0) BP(0,i);

        for(int i=n; i>0; i--)
            for (int j=1; j<=n; j++)
                if ((E[j][Pos[i]]==1) && (D[j] <= D[Pos[i]])) D[j] = D[Pos[i]]+1;   


        memset(Pre, 0, sizeof(Pre));  
        memset(Pos, 0, sizeof(Pos)); 

        vmin = n + 1;
        BP_RESTRITIVA(0,inicial, D[inicial]);

        cout << "Case " << p << ": The longest path from " << inicial << " has length " << D[inicial] << ", finishing at " << vmin << "." << endl << endl;

    }

	return 0;
}