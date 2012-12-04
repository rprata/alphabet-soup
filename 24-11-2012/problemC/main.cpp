#include <iostream>
#include <cstdlib>

int main (void)
{
	long long int num;
	long long int ultimo;

	while (std::cin >> num)
	{
		long long int linha = (num + 1)/2;
		ultimo = linha*num + (linha - 1);
		std::cout << 3*ultimo - 6 << '\n'; 
	}
	return 0;
}