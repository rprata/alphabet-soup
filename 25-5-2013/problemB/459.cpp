#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

#define MAXINT (int)(pow(2,29)) //MAXINT < maior valor inteiro para que MAXINT + x não fique negativo 
#define MAXN 27 //Número de Vértices máximo

int N;
char largestNode;
string s;

typedef struct no* lista;
struct no{ int v;  lista prox; };
struct aresta{ int u, v, c; };

int inicializaMatrizAdj();
int insereDadoMatrizAdj(char , char );
void BPMA(int ,int);

int opcao,
    gn, gm, gcomp, // Numero de vertices, arestas e componentes conexas
    gpe, gps, gr, gf, gtopo,//ordem de entrada, ordem de saída, variáveis de fila e pilha 
    gE[MAXN][MAXN], gDm[MAXN][MAXN], //Matriz de Adjacências e de Distâncias Mínimas
    gPre[MAXN], gPos[MAXN], gLow[MAXN], //Ordem de entrada, saida e menor vertice visivel na BP
    gCo[MAXN], gDe[MAXN], gPa[MAXN], //Componente, grau de entrada, contador de articulações
    gPv[MAXN], //Valores inversos do vetor gPos: gPv[gPos[i]] = i
    gDi[MAXN], //Distâncias mínimas ou máximas
    gQ[MAXN], gS[MAXN], //Fila e Pilha auxiliares
    gPai[MAXN], //Pai de cada vértice na up-tree ou na fila gQ
    gCap[MAXN][MAXN], gFl[MAXN][MAXN]; //Capacidades e Fluxos das arestas 
    lista gA[MAXN]; // Lista de Adjacências
vector <aresta*> gAr; vector <aresta*> gMst;

int main (void)
{
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{		
		cin >> largestNode;	
		getline(cin, s);
		gn = largestNode - 'A' + 1;
		inicializaMatrizAdj();
		
		while (getline(cin, s))
		{
			//generate MA
			if (s.empty())
				break;
			insereDadoMatrizAdj(s[0], s[1]);
		}
		
		for (int k = 1; k <= largestNode - 'A' + 1; k++)
		{
			if (gPre[k] == 0)
			{  
				gcomp++;
				BPMA(0, k);
			}
			
		}
		
		cout << gcomp << endl;
		if (i < N - 1)	cout << endl;
	}	
	return 0;
}

int inicializaMatrizAdj()
{
	for (int i = 1; i <= 26; i++)
	{
		gPre[i] = gPos[i] = gDe[i] = 0;
		for (int j = 1; j <= 26; j++)
			gE[i][j] = 0;
	}
	gpe = gps = gcomp = 0;
}

int insereDadoMatrizAdj(char node_1, char node_2)
{
	gE[node_1 - 'A' + 1][node_2 - 'A' + 1] = 1;
	gE[node_2 - 'A' + 1][node_1 - 'A' + 1] = 1;
}

void BPMA(int u,int v)
{  
	int w;
	gPre[v] = gcomp;  gCo[v] = gcomp;
	for(w = 1;w <= gn; w++)
		if( (gE[v][w] == 1) && (gPre[w] == 0) ) BPMA(v,w);
	gPos[v] = ++gps;	
}  
