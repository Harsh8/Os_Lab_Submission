#include<stdio.h>

int main()
{
	int n,i,j,total_time,total,time,temp,flag,min;
	total_time=0,flag=0;
	printf("\nEnter the number of process	 ");
	scanf("%d",&n);
	
	int process[n][3];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the release time for %d process	",i+1);
		scanf("%d",&process[0][i]);
		printf("\nEnter the Deadline for %d process	",i+1);
		scanf("%d",&process[1][i]);
		printf("\nEnter the Execution time for %d process	",i+1);
		scanf("%d",&process[2][i]);
		total_time=total_time+process[2][i];
	}	
	
	int gantt[n][total_time];
	for(i=0;i<n;i++)
	{
		for(j=0;j<total_time;j++)
		{
			gantt[i][j]=0;
		}	
	}
	min = process[1][0]-process[2][0];
	j=0;
	for(time=0;time<total_time;time++)
	{
		
		for(i=0;i<n;i++)
		{
			if(process[0][i]<=time && process[2][i]!=0)
			{
				if(flag==1)
				{
					min = process[1][i]-process[2][i]-time;
					flag = 0;
					j=i;
				}
				if(process[1][i]-process[2][i]-time<min)
				{
					min = process[1][i]-process[2][i]-time;
					j=i;
				}				
			}
			else if(process[0][i]>time)
			break;
		}
		
		process[2][j] = process[2][j] - 1;
		gantt[j][time]=1;
		if(process[2][j]==0)
		{
			flag=1;
		}			
	}
	
for(i=0;i<n;i++)
	{
		for(j=0;j<total_time;j++)
		{
			printf("%d",gantt[i][j]);
		}
		printf("\n");	
	}
	return 0;			
}
