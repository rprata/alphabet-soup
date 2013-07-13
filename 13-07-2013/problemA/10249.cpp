#include <cstdlib>
#include <cstring>
#include <iostream>
#include <climits>

#define MAX 125

using namespace std;

int C[MAX][MAX], F[MAX][MAX], n, m, nn, nt, fmax, alunos;
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

int main (void)
{
	while (true)
	{
		memset(C, 0, sizeof(C));  memset(F, 0, sizeof(F));  memset(V, 0, sizeof(V));       
		
		cin >> nt >> nn;
		if (nt == 0)
			break;
		
		n = nt + nn + 2;

		alunos = 0;
		for (int i = 2; i <= nt + 1; i++) 
		{
			cin >> C[1][i];
			alunos += C[1][i];
		}

		for (int i = nt + 2; i <= nt + nn + 1; i++)
		{
			cin >> C[i][n];
		}

		for (int i = 2; i <= nt + 1; i++)
		{
			for (int j = nt + 2; j <= nt + nn + 1; j++) 
			{
				C[i][j] = 1;
			}
		}
		
		fmax = 0;

		while(int fm = MF(1, n, INT_MAX)) {
            fmax += fm;
            memset(V, 0, sizeof(V));
            //Imprime();
        }

        if (alunos == fmax)
        {
        	cout << 1 << endl;
			for (int i = 2; i <= nt + 1; i++)
			{
				bool primeiro = false;
				for (int j = nt + 2; j <= nt + nn + 1; j++) 
				{
					if (F[i][j] == 1)
					{
						if (primeiro)
							cout << " ";
						primeiro = true;
						cout << j - nt - 1;

					}
				}
				cout << endl;
			}
        }
        else
        {
        	cout << 0 << endl;
        }
        // Imprime();
        
	}

	return 0;
}