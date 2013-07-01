#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define MAX 2001
using namespace std;

int E[MAX][MAX], Pre[MAX], Low[MAX], Vis[MAX], Pil[MAX], n, m, oe, co, topo, t, u, v;

void CFC(int u, int v){
    Pre[v]=Low[v]=Vis[v]=++oe;  Pil[++topo] = v;
    for(int w=1; w <= n; w++)
        if (E[v][w]==1){
            if (Pre[w]==0) CFC(v, w);
            if (Vis[w]>0 && Low[w] < Low[v]) Low[v] = Low[w];
        }
    if (Low[v]==Pre[v]){
        cout<<"Componente "<<++co<<": ";
        while(1){
            int w=Pil[topo--];  cout<<(char)w<<" ";  Vis[w]=0;
            if(w==v) break;
        }
        cout<<endl;
    }    
}

int cases, n;
char alt[10], maxim;

int main (void)
{
	while (true)
    {
		cin >> cases;
		
        if (cases == 0)
			break;

        memset(E, 0, sizeof(E)); memset(Pre, 0, sizeof(Pre));  
        memset(Low, 0, sizeof(Low));  memset(Vis, 0, sizeof(Vis)); 

		for (int i = 1; i <= cases; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                cin >> alt[j];
            }       
            for (int j = 1; j <= 5; j++)
            {
                cout << alt[6] << " - " << alt[j] << endl;
                E[alt[6] - 'A' + 1][alt[j] - 'A' + 1] = 1;
            }
        }

        oe=co=topo=0;
        for(char ii='A'; ii<=26; ii++)
            if (Pre[ii]==0) CFC(0,ii);        
/        
    }

    return 0;	
}