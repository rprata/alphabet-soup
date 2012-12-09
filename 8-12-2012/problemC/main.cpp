#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int newMod (string p, int n)
{
	long long int q = 0;
	int counter = 1;

	for (int i = 0; i < p.size(); i++)
	{
		q = (q*10 + (p[i] - '0')) % n;
	}

	if (q == 0)
		return true;
	else
		return false;

}
int main (void)
{

	long long int number;
	int quant;
	string s;
	while (cin >> number)
	{
		s = "1";
		quant = 1;
		while (true)
		{
			if (newMod(s, number))
			{
				cout << quant << "\n";
				break;
			}
			s += "1";
			quant++;
		}
	}

	return 0;
}