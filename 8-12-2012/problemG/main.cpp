#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool newMod (string p, int n)
{	
	long long int q = 0;

	for (int i = 0; i < p.size(); i++)
	{
		q = (q*10 + (p[i] - '0')) % n;
	}

	if (q == 0)
		return true;
	else
		return false;
}

long long int n;
long long int i;
bool c = true;


int main (void)
{

	string p, aux; 

	while (cin >> n)
	{
		p = "3";
		c = true; 

		while (c)
		{
			aux = p;
			for (i = 0; i < p.size(); i++)
			{
				if (newMod(aux, n))
				{
					cout << aux.size() << " " << aux.size() - i << " " << i << "\n";
					c = false;
					break;
				} 
				if (aux.size() > 1)
					aux[aux.size() - (i + 1)] = '0';
			}

			p += "3";
		} 

	}

	return 0;
}