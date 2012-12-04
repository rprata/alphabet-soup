#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int folha;
int questoes;

int i, j;

int cor, contadorBranco, contadorPreto;

char resposta;

int vetorQuestoes[6];

int main (void)
{
	while(1)
	{
		scanf("%d", &folha);
		
		if (!folha)
			break;

		for (i = 1 ; i <= folha; i++)
		{
			contadorPreto = contadorBranco = 0;
			for (j = 'A'; j <= 'E'; j++)
			{

				scanf("%d", &cor);
				if (cor > 127)
				{
					contadorBranco++;
				}
				else
				{
					contadorPreto++;
					resposta = j;
				}
			}
		
			if (contadorPreto > 1)
				printf("*\n");
			else if (contadorBranco == 5)
				printf("*\n");
			else
				printf("%c\n", resposta);
		}
	}
	return 0;
}