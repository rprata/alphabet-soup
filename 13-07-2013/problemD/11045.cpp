#include <cstdlib>
#include <cstring>
#include <iostream>
#include <climits>
#include <string>

#define MAX 70

using namespace std;

int C[MAX][MAX], F[MAX][MAX], n, m, nn, nt, fmax, T, nc, nm, camisas;
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
	cin >> T;

	for (int counter = 0; counter < T; counter++)
	{
		memset(C, 0, sizeof(C));  memset(F, 0, sizeof(F));  memset(V, 0, sizeof(V));       
		
		cin >> nc >> nm;

		n = 6 + nm + 2;
		
		camisas = nc/6;
		
		for (int i = 2; i <= 7; i++)
		{
			C[1][i] = camisas;
		}

		for (int i = 8; i <= nm + 7; i++)
		{
			C[i][n] = 1;
		}

		string t1, t2;

		for (int i = 8; i <= nm + 7; i++)
		{
			cin >> t1 >> t2;

			if (t1 == "XXL" || t2 == "XXL")
				C[2][i] = 1;
			if (t1 == "XL" || t2 == "XL")
				C[3][i] = 1;
			if (t1 == "L" || t2 == "L")
				C[4][i] = 1;
			if (t1 == "M" || t2 == "M")
				C[5][i] = 1;
			if (t1 == "S" || t2 == "S")
				C[6][i] = 1;
			if (t1 == "XS" || t2 == "XS")
				C[7][i] = 1;
		}

		fmax = 0;

        while(int fm = MF(1, n, INT_MAX)) {
            fmax += fm;
            memset(V, 0, sizeof(V));
            //Imprime();
        }

        if (fmax == nm)
        	cout << "YES" << endl;
        else
        	cout << "NO" << endl;

	}

	return 0;
}