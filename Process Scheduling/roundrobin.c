#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, b[20], a[20], rt[20] = {0}, i , j, t[20] = {0}, w[20] = {0}, tq;

	int remain,count,time = 0, flag = 0;

	float sat = 0, swt = 0;

	printf("Enter the no. of processes:\n");
	scanf("%d", &n);

	remain = n;

	printf("Enter the at and bt- \n");

	for(i=0;i<n;i++)
	{
		printf("Process %d\n",i);
		scanf("%d %d", &a[i], &b[i]);
		rt[i] = b[i];
	}

	printf("Enter the time quantum:\n");
	scanf("%d" ,&tq);

	for(count = 0; remain!=0;)
	{
		if(rt[count] <= tq && rt[count]>0)
		{
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		}
		else if(rt[count] > 0)
		{
			rt[count] = rt[count] - tq;
			time += tq;
		}

		if(rt[count] == 0 && flag == 1)
		{
			printf("%d\t%d\t%d\n",count,time - a[count], time - a[count] - b[count]);
			remain--;
			sat += time - a[count];
			swt += time - a[count] - b[count];
			flag = 0;
		}

		if(count == n-1)
			count = 0;
		else if(a[count + 1] <= time)
			count++;
		else
			count = 0;
	}

	printf("Avg. tat = %f\n", sat/n);
	printf("Avg. wt = %f\n", swt/n);


	printf("\n");
	return 0;
}