#include <stdio.h>


int main()
{	
	int pages[20], frames[20], np, nf, i, j, counter = 0, time[20] = {0}, faults = 0, q ,k;

	int flag1, flag2, pos, mini;

	printf("Enter the no. of frames-\n");
	scanf("%d", &nf);

	printf("Enter the no. of pages-\n");
	scanf("%d", &np);

	printf("Enter the pages -\n");
	for(i=0;i<np;i++)
		scanf("%d", &pages[i]);

	for(i=0;i<20;i++)
		frames[i] = -1;

	for(i=0; i<np; i++)
	{
		flag1 = 0;
		flag2 = 0;

		for(j=0; j<nf; j++)
		{
			if(frames[j] == pages[i])
			{
				counter++;
				time[j] = counter;
				flag1 = flag2 = 1;
				break;
			}
		}

		if(flag1 == 0)
		{
			for(j=0; j<nf; j++)
			{
				if(frames[j] == -1)
				{
					counter++;
					faults++;
					time[j] = counter;
					frames[j] = pages[i];
					flag2 = 1;
					break;
				}
			}
		}

		if(flag2 == 0)
		{	
			mini = time[0];
			pos = 0;

			for(k=1;k<nf;k++)
			{
				if(mini > time[k]){
					mini = time[k];
					pos = k;
				}
			}

			counter++;
			faults++;
			time[pos] = counter;
			frames[pos] = pages[i];
		}

		for(q=0;q<nf;q++)
		{
			printf("%d ", frames[q]);
		}

		printf("\n");
	}

	printf("Faults = %d\n", faults);

	printf("\n");
	return 0;
}