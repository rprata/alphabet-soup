#include <stdlib.h>
#include <stdio.h>

int muroAnterior, muro;

int descida, subida;

int T, N, i, j;

int main (void)
{

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		descida = subida = 0;

		scanf("%d", &N);
		scanf("%d", &muroAnterior);
		for (j = 1; j <= N - 1; j++)
		{	
			if (N <= 1)
			{
				printf("Case %d: 0 0\r\n", i);
				break;
			}
			scanf("%d", &muro);
			if (muro < muroAnterior)
			{
				descida++;
			}
			else if (muro > muroAnterior)
			{
				subida++;
			}
			muroAnterior = muro;
		}
		printf("Case %d: %d %d\n", i, subida, descida);
	}

	return 0;
}