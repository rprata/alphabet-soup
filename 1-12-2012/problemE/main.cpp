#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct ret { int d; int x; int y;};

long long int a, b, T;


ret r;

long long int k, x;

int MDC(int a, int b)
{   if (b == 0) return a;
    else return MDC(b, a % b);
}

ret MDCE(int a, int b, ret ra)
{   int xx;
    if (b == 0)
    {   ra.d = a;  ra.x = 1;  ra.y = 0;
    }
    else
    {   ra = MDCE(b, a % b, ra);
        xx = ra.x;  ra.x = ra.y;  ra.y = xx - (a / b)*ra.y;
    }    
    return ra;          
}


int main (void)
{
	cin >> T;
	for(int i = 1; i <= T; i++)
	{

		cin >> x;
		cin >> k;

		// cout << x << "\n";
		// cout << k << "\n";

		a = x/k;
		b = ceil(((double)x)/k);

		r.d = MDC(a,b);

		cout << r.d << "\n";
        r = MDCE(a, b, r);

	    // cout << r.x << " " << r.y << "\n";

	}

	return 0;

}