#include <cstdlib>
#include <cstring>
#include <iostream>
#include <climits>
#include <string>

#define MAX 210

using namespace std;

int C[MAX][MAX], F[MAX][MAX], n, m, fmax, T, quantidade_1, quantidade_2;
bool V[MAX];

void Imprime(){
        cout<<"Rede:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (F[i][j] > 0) cout << i << " " << j << "  "<<F[i][j]<<endl;
            }        
        }     
}

int MF(int s, int t, int minn) {
    V[s] = true;
    if (s==t) return minn;
    for(int i=1; i<=n; i++) {
        if (!V[i] && C[s][i] > 0) {
            if (int fm = MF(i, t, min(minn, C[s][i]))) {
                C[s][i] -= fm;  C[i][s] += fm;
                F[s][i] += fm;  F[i][s] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}
int L1[MAX];
int L2[MAX];


int main (void)
{
    cin >> T;

    for (int counter = 1; counter <= T; counter++)
    {
        memset(C, 0, sizeof(C));  memset(F, 0, sizeof(F));  memset(V, 0, sizeof(V));       
        memset(L1, 0, sizeof(L1));  memset(L2, 0, sizeof(L2)); 

        cin >> quantidade_1;

        for (int i = 2; i <= quantidade_1 + 1; i++)
        {
            cin >> L1[i];
        }

        cin >> quantidade_2;

        for (int i = quantidade_1 + 2; i <= quantidade_1 + quantidade_2 + 1; i++)
        {
            cin >> L2[i];
        }

        n = quantidade_1 + quantidade_2 + 2;

        for (int i = 2; i <= quantidade_1 + 1; i++)
        {
            C[1][i] = 1;
        }

        for (int i = quantidade_1 + 2; i <= quantidade_1 + quantidade_2 + 1; i++)
        {
            C[i][n] = 1;
        }

        for (int i = 2; i <= quantidade_1 + 1; i++)
        {
            for (int j = quantidade_1 + 2; j <= quantidade_1 + quantidade_2 + 1; j++)
            {

                if ((L1[i] == 0 && L2[j] == 0) || (L1[i] != 0 && L2[j] % L1[i] == 0))
                {
                    C[i][j] = 1;                   
                }

            }
        }

        fmax = 0;

        while(int fm = MF(1, n, INT_MAX)) {
            fmax += fm;
            memset(V, 0, sizeof(V));
            //Imprime();
        }

        cout << "Case " << counter << ": " << fmax << endl;

    }

    return 0;
}