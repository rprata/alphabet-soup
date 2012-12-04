#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int C[10000001], P[1000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];
bool teste;

void GeraCrivo (long long int n)
{    long long int i, rq, t, d;
     for (i=1; i <= n; i++)   C[i] = 0;
     rq = sqrt(n);
     for (i = 2; i <= n; i++)
     {  
     	if (C[i] == 0)
        {   
         	t = i;
            while(t <= n)
            {   
            	C[t]++;
                t = t + i;
            }
         }
     }
 
}

int main (void)
{
	long long int n;
	GeraCrivo (1000000);
	while (cin >> n)
	{
		if (n == 0)
			break;
		
		cout << n << " : " << C[n] << "\n";
	}

	return 0;
}