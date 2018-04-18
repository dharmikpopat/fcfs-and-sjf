#include<stdio.h>
#include<conio.h>

void FCFS(){

    float process[500],aTime[500],bTime[500],abTime[500],wTime[500],tat_time[500];
    int n = 0,i = 0 ;
    float aw_time = 0, atat_time = 0;
    printf("*** FCFS Scheduling Algorithm Using Arrival Time ***\n");
    printf("\nEnter the number of process : ");
    scanf("%d",&n);

    printf("Enter the Arrival time and Burst time.\n\n");
    printf("\tA_Time B_Time\n");
    for(i = 0 ; i < n ; i++){
        process[i]=i+1;
        printf("P%d :\t", i+1);
        printf("Enter arrival time :");
        scanf("%f",&aTime[i]);
        printf("P%d :\t", i+1);
        printf("Enter burst time :");
		scanf("%f",&bTime[i]);
    }
    printf("\n\nProcess\tA_Time\tB_Time\n");
    for(i = 0 ; i < n ; i++){
        printf("P[%d]\t%.2f\t%.2f\n",i,aTime[i],bTime[i]);
    }
    wTime[0] = 0;
    tat_time[0] = bTime[0];
    abTime[0] = bTime[0]+aTime[0];
    for( i = 1 ; i < n ; i++){
        abTime[i] = abTime[i-1] + bTime[i];
        tat_time[i] = abTime[i] - aTime[i];
        wTime[i] = tat_time[i] - bTime[i];
    }
    for(i = 0 ; i < n ; i++){
        aw_time = aw_time + wTime[i];
        atat_time = atat_time + tat_time[i];
    }
    printf("\tA_time\tB_time\tC_time\tTat_time  W_time\n");
    for(i = 0 ; i < n ; i++){
        printf("P[%d]\t%.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\n",i,aTime[i],bTime[i],abTime[i],tat_time[i],wTime[i]);
    }
    printf("\nAverage waiting time : %0.2f",aw_time/n);
    printf("\nAverage turn around time : %0.2f",atat_time/n);

}


void SJF(){
	
	int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
	int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf(" -------Shortest Job First Scheduling ( NP )-------\n");
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\tEnter the burst time of %d process :",i+1);
		scanf(" %d",&bt[i]);
		printf("\tEnter the arrival time of %d process :",i+1);
		scanf(" %d",&at[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=at[j];
				at[j]=at[i];
				at[i]=temp;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
	
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp=at[k];
				at[k]=at[i];
				at[i]=temp;
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
	
	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
	
	tavg=(tsum/n);
	
	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
	}
	
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
	
}

void SJF1(){
	
	int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
	int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf(" -------Shortest Job First Scheduling ( NP )-------\n");
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\tEnter the burst time of %d process :",i+1);
		scanf(" %d",&bt[i]);
		printf("\tEnter the arrival time of %d process :",i+1);
		scanf(" %d",&at[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				temp=at[j];
				at[j]=at[i];
				at[i]=temp;
				temp=bt[j];
				bt[j]=bt[i];
				bt[i]=temp;
			}
		}
	}
	
	for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp=at[k];
				at[k]=at[i];
				at[i]=temp;
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
	
	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
	
	tavg=(tsum/n);
	
	printf("************************");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
	}
	
	printf("\n\nAVERAGE WAITING TIME : %f",wavg+1);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg+1);
	
}



int main(){
	int choice;
	
	printf("Enter 1 for LRU replacement\n");
	printf("Enter 2 for FIFO replacement\n");
	printf("Enter 3 for optimal replacement\n");
	printf("Enter 4 to exit\n\n");
	printf("Enter your choice :");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: FCFS();
				return 0;
			break;
		case 2: SJF();
			break;
		case 3: SJF1();
			break;
		case 4: return 0;
			break;
		default: printf("enter valid choice");
			break;
	}
	
}


