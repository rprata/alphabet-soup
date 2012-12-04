#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct ret { int d; int x; int y;};

int a, b; ret r;

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
	while (cin >> a >> b)
	{
        r.d = MDC(a, b);
        r = MDCE(a, b, r);
	    cout << r.x << " " << r.y << " " << r.d << "\n";
    }
	return 0;
}