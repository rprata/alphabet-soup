#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 2001
using namespace std;

int E[MAX][MAX], Pre[MAX], Low[MAX], Vis[MAX], Pil[MAX], n, m, oe, co, topo, t, u, v;

int CFC(int u, int v, int * out){
    Pre[v]=Low[v]=Vis[v]=++oe;  Pil[++topo] = v;
    for(int w=1; w <= n; w++)
        if (E[v][w]==1){
            if (Pre[w]==0) CFC(v, w, out);
            if (Vis[w]>0 && Low[w] < Low[v]) Low[v] = Low[w];
        }
    if (Low[v]==Pre[v]){
    	*out = ++co;
        while(1){
            int w=Pil[topo--]; Vis[w]=0;
            if(w==v) break;
        }
    }    
}


int main (void)
{
	int out;
	
	while (true)
	{

		cin >> n >> m;
        
		if (n == 0)
			break;

		memset(E, 0, sizeof(E)); memset(Pre, 0, sizeof(Pre));  
        memset(Low, 0, sizeof(Low));  memset(Vis, 0, sizeof(Vis));

		for(int i=1; i<=m; i++) {
            cin >> u >> v >> t;  
            if (t == 1)
            	E[u][v] = 1;
            else
            {
            	E[u][v] = 1;
            	E[v][u] = 1;
            }
        }

        oe=co=topo=0;
        for(int i=1; i<=n; i++)
            if (Pre[i]==0) CFC(0,i,&out);

        if (out == 1)
        	cout << out << endl;
        else
        	cout << "0" << endl;
	}

	return 0;
}