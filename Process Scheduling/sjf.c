#include <stdio.h>

int main()
{
	int n, a[20], b[20], bb[20], i, j, time, flag = 0, lowest;

	int g[20] = {0}, tat[20], wt[20], d;

	float stat = 0, swt = 0;

	printf("Enter the no. of processes:\n");
	scanf("%d", &n);

	printf("Enter the arrival time and burst time:\n");

	for(i=0; i<n; i++)
	{
		scanf("%d %d", &a[i], &bb[i]);
	}

	for(i=0;i<n;i++)
		b[i] = bb[i];

	g[0] = a[0]; 

	g[1] = b[0];

	time = g[1];

	for(i=1;i<n;i++)
	{
		if(a[i] <= time)
		{	
			lowest = 999;

			if(time >= a[n])
				d = n;
			else
				d = time + 1;

			for(j=1;j<d;j++)
			{
				if(lowest >= b[j])
				{
					lowest = b[j];
					flag = j;
				}
			}

			time += lowest;
			b[flag] = 999;

			g[i+1] = time;
		}
	}

	for(i=0;i<=n;i++)
		printf("%d\t", g[i]);

	for(i=0;i<n;i++)
	{
		tat[i] = g[i+1] - a[i];
		wt[i] = tat[i] - bb[i];

		stat += tat[i];
		swt += wt[i];
	}

	printf("\n");

	for(i=0;i<n;i++)
		printf("%d\t", tat[i]);

	printf("\n");

	for(i=0;i<n;i++)
		printf("%d\t", wt[i]);

	printf("Avg tat = %f\n", stat/n);
	
	printf("Avg wt = %f\n", swt/n);

	printf("\n");
	return 0;
}