#include <iostream>
#include <cmath>

using namespace std;

int C[10000001], P[1000001], rq, nf, np, nd, mdc;
long long int n, q, F[50], D[10000];
bool teste;

void GeraCrivo (int n)
{    int i, rq, t, d;
     for (i=1; i<=n; i++)   C[i] = i;
     for (i=2; i<=n; i+=2)  C[i] = 2;
     rq = sqrt(n);
     for (i=3; i<=rq; i+=2)
     {   if (C[i] == i)
         {   t = i*i;  d = i+i;
             while(t<=n)
             {   if (C[t] == t) C[t] = i;
                 t = t+d;
             }
         }
     }
}

void GeraPrimos (int rq)
{    np = 0;
	 mdc = 0; 
     for (int i = 2; i <= rq ; i++)
         if (C[i]==i)
         {
           P[++np]= i;
       	 }
}

bool TestaPrimo (long long int q)
{    bool primo = true;
     for (int i=1; i<=np; i++)
     {   if ((q % P[i]) == 0)
         {   
	     if (q != P[i]) primo = false;
             break;
         }    
     }
     return (primo);
}

void Fatora (long long int q)
{    nf = 0;
     for (int i=1; i<=np; i++)
     {   while((q % P[i]) == 0)
         {   F[++nf] = P[i];  q = q/P[i];
         }
         if (q == 1) break;
     }
     if (q != 1) F[++nf] = q;
}

int main (void)
{
	GeraCrivo(10000000);
	GeraPrimos(1000000);

	int anterior = 2; 

	while (cin >> n)
	{
		n = fabs(n);
		
		if (n == 0)
			break;

		Fatora(n);
		mdc=1;
		for (int i = 2; i <= nf; i++)
		{   
			if (F[i] != F[i-1])
			{
				mdc++;			
			}
		}		

		if (mdc <= 1)
		{
			cout << "-1" << "\n";
		}
		else
		{

			cout << F[nf] << "\n";
		}
	}
	return 0;
}