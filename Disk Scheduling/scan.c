#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int que[20], head, i, j, n, diff, cyc, flag, temp;

    float sum = 0;

    printf("Enter the size of the queue and no. of cylinders:\n");
    scanf("%d %d", &n, &cyc);

    printf("Enter the queue:\n");
    for(i=1;i<=n;i++)
        scanf("%d", &que[i]);
    que[n+1] = cyc;
    que[0] = 0;

    printf("Enter the head position:\n");
    scanf("%d", &head);

    que[n+2] = head;

    for(i=0;i<=n+2;i++)
    {
    	for(j=0;j<=n+2;j++)
    	{
    		if(que[i] <= que[j])
    		{
    			temp = que[i];
    			que[i] = que[j];
    			que[j] = temp;
    		}
    	}
    }

    for(i=0;i<=n+2;i++)
    {
    	if(que[i] == head)
    		flag = i;
    }

    for(i=0;i<=n+2;i++)
    	printf("%d\t", que[i]);

    printf("\n");

    for(i=flag; i != 0; i--)
    {
    	diff = abs(que[i] - que[i - 1]);
    	sum += diff; 
    	printf("Move from %d -> %d : Seek = %d\n",que[i],que[i-1],diff);
    }

    sum += que[flag + 1];
    printf("Move from 0 -> %d : Seek = %d\n",que[flag+1], que[flag + 1]);

    for(i = flag + 1; i < n+1;i++)
    {
    	diff = abs(que[i + 1] - que[i]);
    	sum+=diff;
    	printf("Move from %d -> %d : Seek = %d\n",que[i],que[i+1],diff);
    }

    printf("%f\n", sum);

    printf("%f\n", sum/n);

    printf("\n");
    return 0;
}






