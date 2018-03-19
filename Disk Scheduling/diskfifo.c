#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int que[20], head, i, j, n, diff;

    float sum = 0;

    printf("Enter the size of the queue:\n");
    scanf("%d", &n);

    printf("Enter the queue:\n");
    for(i=0;i<n;i++)
        scanf("%d", &que[i]);

    printf("Enter the head position:\n");
    scanf("%d", &head);

    sum += abs(head - que[0]); 
    printf("Move from %d -> %d : Seek = %f\n", head, que[0], sum);

    for(i=0;i<n-1;i++)
    {
        diff = (float)abs(que[i+1] - que[i]);
        sum += diff;
        printf("Move from %d -> %d : Seek = %d\n", que[i], que[i+1], diff);
    }

    printf("%f\n", sum);

    printf("%f\n", sum/n);


    printf("\n");
    return 0;
}