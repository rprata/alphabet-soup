#include <iostream>

using namespace std;


int A[5][5] = {
			{0, 1, 1, 0, 1},
			{1, 0, 1, 0, 1},
			{1, 1, 0, 1, 1},
			{0, 0, 1, 0, 1},
			{1, 1, 1, 1, 0}
		};
int V[5][5] = {
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1}
		};
int P[100];

int caminhos = 0;

int np, n;

void Permut(){
    for (int i=0; i<=4; i++)
        if (A[P[np]][i] && V[P[np]][i]){
            V[i][P[np]]=0;  V[P[np]][i]=0; P[++np]=i; 
            if (np == 8){
                for (int j=0; j<=8; j++) cout<<P[j]+1; cout<<endl;
            }
            else Permut();
            np--; V[i][P[np]]=1; V[P[np]][i]=1; 
        }
}

int main (void)
{	
	np  = 0;
	P[0] = 0;
	Permut();
	return 0;
}