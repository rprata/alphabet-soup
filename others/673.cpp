#include <iostream>
#include <stack>

using namespace std;


int main (void)
{
	int N;
	stack<char> pilha;   char c; bool error; char ultimo;
    string s;    

	
	for (cin >> N, getline(cin, s); N--; )
	{		

		getline(cin, s);

		error = false;

		if (s.length() == 0)
		{
			cout << "Yes" << endl;
			error = true;
		}

    	for(int i = 0; i < s.size(); i++)
    	{

    		if (s[i] == '(' || s[i] == '[') 
    		{
    			pilha.push(s[i]);
    		}
    		else
    		{
    			if (pilha.empty())
    			{
    				cout << "No" << endl;
    				error = true;
    				break;
    			}

				
				if ((s[i] == ']' && pilha.top() == '[') || (s[i] == ')' && pilha.top() == '(')) 
				{
					pilha.pop();
				}
				else
				{
					cout << "No" << endl;
					error = true;
					break;
				}
    		}
    	}
    	if (!error)
    		if (pilha.empty())
    			cout << "Yes" << endl;
    		else
    			cout << "No" << endl;

    	while (!pilha.empty()) //limpado pilha para proxima linha de teste
    		pilha.pop();
	}
}
