#include <stdio.h>

int main() 
{
	int a[10], b[10], x[10], i, j, smallest, remain=0, time, n;
	double wt=0, tt=0, end;
  	
  	printf("Enter the number of Processes:\n");
  	scanf("%d",&n); 
 	
 	printf("Enter arrival time\n");
 	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
 	
 	printf("Enter burst time\n");
 	for(i=0;i<n;i++)
 		scanf("%d",&b[i]); 
 
 	for(i=0;i<n;i++)
 		x[i]=b[i];

  	b[9]=9999;
  
	for(time=0;remain!=n;time++)
	{
	   smallest=9;

			for(i=0;i<n;i++)
	  		{
	   			if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
	   				smallest=i;
	  		}
	  	b[smallest]--;
	  
	  	if(b[smallest]==0)
	  	{
	   		remain++;
	   		tt = tt + time + 1 - a[smallest];
	   		wt = wt + time + 1 - a[smallest] - x[smallest];
	   		printf("%d\t%d\n", tt, wt);
	  	}
	 }

 	printf("\n\nAverage waiting time = %lf\n",wt/n);
    
    printf("Average Turnaround time = %lf",tt/n);
    
    printf("\n");
    return 0;
}
