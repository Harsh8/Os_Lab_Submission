#include<stdio.h>

int main()
{
int n;

	printf("\nEnter the number of processes : ");
	scanf("%d",&n);

int burst_time[n],wait_time[n],turnaround_time[n];
int i;

	for(i=0;i<n;i++){
		printf("\nEnter the burst time of process P[%d]",i);
		scanf("%d",&burst_time[i]);
	}	

	printf("\nSrno  Process  Burst-Time");
	for(i=0;i<n;i++){
		printf("\n%d    P%d        %d",i,i,burst_time[i]);
	}
wait_time[0]=0;
turnaround_time[0]=burst_time[0];
	
	for(i=1;i<n;i++){
			wait_time[i] = burst_time[i-1] + wait_time[i-1];
			turnaround_time[i] = burst_time[i] + wait_time[i];
	}

	printf("\nSrno  Process  Burst-Time  Wait-Time  Turnaround-Time");
	for(i=0;i<n;i++){
		printf("\n%d    P%d        %d           %d          %d",i,i,burst_time[i],wait_time[i],turnaround_time[i]);
	}
printf("/n");
return 0;
}

