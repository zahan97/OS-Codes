#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, b[20], a[20], i , j, t[20] = {0}, w[20] = {0};

	int g[20] = {0};

	float sumt = 0, sumw = 0;

	printf("Enter the no. of processes:\n");
	scanf("%d", &n);

	printf("Enter the at and bt- \n");

	for(i=0;i<n;i++)
	{
		printf("Process %d\n",i);
		scanf("%d %d", &a[i], &b[i]);
	}

	for(i=0;i<=n;i++)
	{
		g[i+1] = g[i] + b[i];
	}

	for(i=0;i<n;i++)
	{
		t[i] = g[i+1] - a[i];
		w[i] = t[i] - b[i];
	}

	for(i=0;i<=n;i++)
	{
		printf("%d ",g[i]);
	}

	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("%d ",t[i]);
		sumt += t[i];
	}

	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("%d ",w[i]);
		sumw += w[i];
	}

	printf("Avg. tat = %f\n", sumt/n);
	printf("Avg. wt = %f\n", sumw/n);

	printf("\n");
	return 0;
}