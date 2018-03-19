#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int que[20], head, i, j, n, diff, flag, temp;

    float sum = 0;

    printf("Enter the size of the queue:\n");
    scanf("%d", &n);

    printf("Enter the queue:\n");
    for(i=1;i<=n;i++)
        scanf("%d", &que[i]);

    printf("Enter the head position:\n");
    scanf("%d", &head);

    que[0] = head;

    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=n;j++)
    	{
    		if(que[i] <= que[j])
    		{
    			temp = que[i];
    			que[i] = que[j];
    			que[j] = temp;
    		}
    	}
    }

    for(i=0;i<=n;i++)
    {
    	if(que[i] == head)
    		flag = i;
    }

    for(i=0;i<=n;i++)
    	printf("%d\t", que[i]);

    printf("\n");


    for(i=flag; i != 0; i--)
    {
    	diff = abs(que[i] - que[i - 1]);
    	sum += diff; 
    	printf("Move from %d -> %d : Seek = %d\n",que[i],que[i-1],diff);
    }

    sum += que[n] - que[0];
    printf("Move from %d -> %d : Seek = %d\n", que[0], que[n], que[n] - que[0]);

    for(i = n; i > flag + 1; i--)
    {
    	diff = abs(que[i] - que[i - 1]);
    	sum+=diff;
    	printf("Move from %d -> %d : Seek = %d\n",que[i],que[i - 1],diff);
    }

    printf("%f\n", sum);

    printf("%f\n", sum/n);

    printf("\n");

    return 0;
}






