#include <stdio.h>

int main()
{	
	int pages[20], frames[20], np, nf, i, j, faults = 0, q ,k, temp[20] = {0};

	int flag1, flag2, flag3, pos, min;

	printf("Enter the no. of frames -\n");
	scanf("%d", &nf);

	printf("Enter the no. of pages -\n");
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
				flag1 = flag2 = 1;
				break;
			}
		}

		if(flag1 == 0)
		{
			for(j=0; j<nf; j++){
			if(frames[j] == -1)
			{
				faults++;
				frames[j] = pages[i];
				flag2 = 1;
				break;
			}
			}

		}//flag1

		if(flag2 == 0)
		{
			for(j=0;j<nf;j++)
			{
				for(k=i-1; k >= 0; k--)
				{
					if(frames[j] == pages[k])
					{
						temp[j] = k;
						break;
					}
				}
			}

			min = temp[0];
			pos = 0;

			for(q = 1; q<nf; q++)
			{
				if(min > temp[q])
				{
					min = temp[q];
					pos = q;
				}
			}


			faults++;
			frames[pos] = pages[i];

		}//flag2

		for(k=0; k<nf; k++)
		{
			printf("%d ", frames[k]);
		}

		printf("\n");
	}//main loop

	printf("Faults = %d\n", faults);

	printf("\n");
	return 0;
}