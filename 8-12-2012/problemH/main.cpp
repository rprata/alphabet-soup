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

string number;

int main (void)
{	
	while (true)
	{
		cin >> number;

		if (number == "0")
			break;

		if (newMod(number, 17))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}