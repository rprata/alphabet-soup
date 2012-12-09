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

bool isLeap (string p)
{
	if (newMod(p, 4))
		if (!newMod(p, 100) || newMod(p, 400))
				return true;
	return false;
}

string number;
bool specialYear;


int main (void)
{
	int counter = 0;
	while (cin >> number)
	{
		if (counter)
			cout << endl;
		
		counter++;

		specialYear = false;
		if (isLeap(number))
		{
			cout << "This is leap year.\n";
	 		specialYear = true;
	 	}
	 	if (newMod(number, 15))
	 	{
			cout << "This is huluculu festival year.\n";
			specialYear = true;
		}

		if (newMod(number, 55) && isLeap(number))
			cout << "This is bulukulu festival year.\n";
		
		if (!specialYear)
			cout << "This is an ordinary year.\n";
	
	}
	return 0;
}