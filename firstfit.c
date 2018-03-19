#include <stdio.h>
#include <stdlib.h>

int main()
{
	int p[20], b[20], i, j, np, nb, temp;

	int barr[20] = {0}, parr[20] = {0}; 

	printf("Enter the no. of blocks:\n");
	scanf("%d",&nb);

	printf("Enter the no. of processes:\n");
	scanf("%d",&np);

	for(i=1;i<=nb;i++)
		scanf("%d",&b[i]);

	for(i=1;i<=np;i++)
		scanf("%d",&p[i]);

	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(barr[j] == 0)
			{
				temp = b[j] - p[i];

				if(temp >= 0)
				{
					parr[i] = j;
					break;
				}
			}
		}

		barr[parr[i]] = 1;
	
	}

	for(i=1;i<=np;i++)
	{
		if(parr[i] == 0)
		{
			printf("Process %d Not Allocated\n", i);
		}
	}

	for(i=1;i<=np;i++)
	{
		if(parr[i] != 0)
		printf("%d -> %d\n",p[i],b[parr[i]]);
	}


	printf("\n");
	return 0;
}