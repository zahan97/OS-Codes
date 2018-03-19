#include <stdio.h>

int allocation[20][20], max[20][20], avl[20], need[20][20];
int r,p;

void safecheck()
{
	int work[20], finish[20] = {0}, i, j, flag = 0, u;
	int counter = 0;

	for(i=0;i<r;i++)
		work[i] = avl[i];

	while(1)
	{	
		flag = 0;

		for(j=0;j<r;j++)
		{
			if(need[counter][j] <= work[j])
			{	
				flag = 1;
				break;
			}
		}

		if(flag == 0)
		{	
			for(j=0;j<r;j++)
				work[j] += allocation[counter][j];
			
			finish[counter] = 1;
			
			printf("Hello\n");

			printf("%d\n", counter);
		}
		

		counter++;

		if(counter >= p)
			counter = 0;

		for(i=0;i<p;i++)
		{
			if(finish[i] == 0)
			{
				break;
			}
		}

		if(i == p)
		{	
			printf("There exists a safe state\n");
			break;
		}
	}

	for(i=0; i<p; i++)
		printf("%d\t", finish[i]);
}


int main()
{
	int i,j,k;

	printf("Enter the total no. of processes:\n");
	scanf("%d", &p);

	printf("Enter the total no. of resources:\n");
	scanf("%d", &r);

	printf("Enter the allocation matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d", &allocation[i][j]);
		}
	}

	printf("Enter the max matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d", &max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	printf("The need matrix is:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}

	printf("Enter avaliable:\n");
	for(i=0;i<r;i++)
		scanf("%d", &avl[i]);

	safecheck();

	printf("\n");
	return 0;
}


































