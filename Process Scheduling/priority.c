#include <stdio.h>


int main()
{
	int n, a[20], b[20], p[20], i, j, remain, time = 0, smallest;

	float tat = 0, wt = 0;

	printf("Enter the no. of processes:\n");
	scanf("%d", &n);

	remain = n;

	printf("Enter the arrival time, burst time and priority:\n");

	for(i=0;i<n;i++)
	{
		scanf("%d %d %d", &a[i], &b[i], &p[i]);
	}

	p[19] = 999;

	for(time = 0; remain!=0; )
	{
		smallest = 19;

		for(i=0; i<n; i++)
		{
			if(b[i] > 0 && a[i] <= time && p[i] < p[smallest])
			{
				smallest = i;
			}
		}

		time += b[smallest];
		remain--;
		printf("%d\t%d\t%d\n", smallest, time - a[smallest], time - a[smallest] - b[smallest]);
		tat += time - a[smallest];
		wt += time - a[smallest] - b[smallest];
		b[smallest] = 0;
	}

	printf("%f\n", tat/n);
	printf("%f\n", wt/n);



	printf("\n");
	return 0;
}