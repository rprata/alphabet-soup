#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int T;
string s, aux;
stringstream ss;

int main (void)
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		getline(cin, s); //limpa o caracter enter
 
		while (getline(cin, s))
		{
			//generate MA
			if (s.empty())
				break;

			ss.clear();
			ss.str(s);

			while (ss >> aux)
			{

			}
			cout << endl;

		}

	}

	return 0;
}