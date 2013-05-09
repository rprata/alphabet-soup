//1. acesse uva.onlinejudge.org
//2. va em Browse problems -> Contestvolumes -> CXIX
//  -> "11988 - Broken Keyboard"
//3. Resolva o problema usando seus conhecimentos de C++

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main (void)
{
	string entrada, no, res;

	int i; char caracter; bool home;

	while (cin >> entrada)
	{

		no = "";
		list<string> saida; //lista pois e a melhor estrutura para controle de insercao no inicio e no fim
		home = false;
		
		for(i = 0; i < entrada.size(); i++)
		{
			caracter = entrada.at(i);

			//Controle do fluxo
			if (caracter == '[') //home
			{	
				if (!home)
   					saida.push_back(no);
   				else
    				saida.push_front(no);
   				no = "";
   				home = true;
			}
			else if (caracter == ']') //end
			{
				if (!home)
								saida.push_back(no);
				else
					saida.push_front(no);
				no = "";
				home = false;
			}
			else
			{
				no += caracter;
			}
		}
		
		//restante do buffer
		if (!home)
 			saida.push_back(no);
		else
			saida.push_front(no);

  		list<string>::const_iterator it;
 		res = "";
 		
 		for (it = saida.begin(); it != saida.end(); it++)
 		{
			res += *(it);
 		}
			
		cout << res << endl;
	}

	return 0;
}