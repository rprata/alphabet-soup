#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

long long int entrada, x, y;
long long int linha;
long long int metade;

int main (void)
{
	x=y=1;
	while (true)
	{
		cin >> entrada;
		if (!entrada)
			break;

		for (long long int i = 1; i <= entrada; i++)
		{
			if (i*i >= entrada)
			{
				linha = i;
				break;
			}
		}

		metade = linha*linha - linha + 1;

		if (entrada == metade)
		{
			x = y = linha;
		}
		else if (entrada > metade)
		{
			if (linha % 2)
			{
				y = linha;
				x = linha*linha - entrada + 1;
			}
			else
			{
				x = linha;
				y = linha*linha - entrada + 1;
			}
		}
		else
		{
			if (linha % 2)
			{
				x = linha;
				y = linha - (metade - entrada);
			}
			else
			{
				y = linha;
				x = linha - (metade - entrada);
			}
		}

		cout << x << " " << y << '\n';
	}
	return 0;
}