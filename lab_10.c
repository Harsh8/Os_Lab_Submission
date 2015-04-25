#include<stdio.h>
int main ()
{
	int np,i,j,temp=0;
	printf("\nEnter the Number of processes	");
	scanf("%d",&np);
	int p[np],burst_time[np],turn_around_time[np],waiting_time[np];
	for(i=0;i<np;i++)
	{
		printf("\nEnter the burst time for process%d	",i+1);
		scanf("%d",&burst_time[i]);
		p[i]=i+1;
	}
	for(i=0;i<np-1;i++)
	{
		for(j=i+1;j<np;j++)
		{
			if(burst_time[j]<burst_time[i])
			{
				temp = burst_time[i];
				burst_time[i]=burst_time[j];
				burst_time[j]=temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	waiting_time[0]=0;
	turn_around_time[0]=burst_time[0];
	printf("\nProcess waiting_time turn_around_time");
	printf("\n%d	 %d		%d",p[0],waiting_time[0],turn_around_time[0]);
	for(i=1;i<np;i++)
	{
		waiting_time[i]= waiting_time[i-1]+burst_time[i-1];
		turn_around_time[i]=waiting_time[i]+burst_time[i];
		printf("\n%d	 %d		%d",p[i],waiting_time[i],turn_around_time[i]);
	}
return 0;
}		 			
