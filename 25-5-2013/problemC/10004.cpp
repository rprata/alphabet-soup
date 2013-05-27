#include <queue>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAXINT (int)(pow(2,29)) //MAXINT < maior valor inteiro para que MAXINT + x não fique negativo 
#define MAXN 1001 //Número de Vértices máximo

typedef struct no* lista;
struct no{ int v;  lista prox; };
struct aresta{ int u, v, c; };

void InicializaMA(int, int);
void BPMA(int, int);
void insereMA(int, int);

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

int n, l;
int node_1, node_2;
bool res = true;

int main (void)
{
	while (1)
	{
		cin >> n;
		gn = n;
		
		if (n == 0)
			break;
		
		cin >> l;
		
		InicializaMA(n, 0);

		for (int i = 1; i <= l; i++)
		{
			cin >> node_1 >> node_2;
			insereMA(node_1, node_2);
		}
		
		res = true;
		for (int i = 1; i <= gn; i++)
		{
			if (gPre[i] == 0)
			{
				BPMA(i, 1);
			}
		}
		
		if (res)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	
	return 0;	
}

void InicializaMA(int n, int vi)
{
	int i,j;
	for(i = 1;i <= n;i++){
		gPre[i] = gPos[i] = gDe[i] = 0;
		for(j = 1; j <= n;j++) gE[i][j] = vi;
	}
	gpe = gps = gcomp = 0;
}

void insereMA(int node_1, int node_2)
{
	gE[node_1 + 1][node_2 + 1] = 1;
	gE[node_2 + 1][node_1 + 1] = 1;
}


void BPMA(int u,int cor)
{	
	int w;
	gPre[u] = cor; 
	for(w = 1;w <= gn;w++)
	{
		if( (gE[u][w] == 1))
		{
			if (gPre[w] == 0)
			{
				BPMA(w, 3 - cor);
			}
			else if (gPre[w] == gPre[u])
			{
				res = false;
				return;
			}
		}
	}
}  


