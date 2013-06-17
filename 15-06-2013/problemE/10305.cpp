#include <iostream>
#include <cstdio>
#include <cstring>


#define MAX 110
using namespace std;

int E[MAX][MAX], Pre[MAX], Pos[MAX], D[MAX], n, m, os, oe, u, v;

void BP(int u, int v)
{
    Pre[v]=++oe;
    for(int i = 1; i <= n; i++)
        if ((E[v][i]==1)&&(Pre[i]==0))
            BP(v, i);
    os++; Pos[n-os+1]=v;
}

int main (void)
{
	while (true)
	{
		cin >> n >> m;
	    if (m == 0 && n == 0) break;


		memset(E, 0, sizeof(E)); memset(Pre, 0, sizeof(Pre));  
	    memset(Pos, 0, sizeof(Pos));  memset(D, 0, sizeof(Pre)); 

	    for(int i=1; i<=m; i++) 
	    {
	        cin >> u >> v;
	        E[u][v] = 1;
	    }

	    oe=os=0;
	    for(int i=1; i<=n; i++)
	        if (Pre[i]==0) BP(0,i);

	    for(int i=1; i<=n; i++) cout << Pos[i]<<" "; cout << endl;  

	    for(int i=n; i>0; i--)
	        for (int j=1; j<=n; j++)
	            if ((E[j][Pos[i]]==1) && (D[j] <= D[Pos[i]])) D[j] = D[Pos[i]]+1;
    }
	return 0;
}
