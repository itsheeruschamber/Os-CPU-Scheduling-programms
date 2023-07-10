#include<stdio.h>
int main()
{
    int AT[10],BT[10],WT[10],TT[10],n;
    int burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    printf("Enter number of the process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("AT\tBT\n");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&AT[i],&BT[i]);
    }
    
    // Logic for calculating Waiting time
    for(i=0;i<n;i++)
    {
        if(i==0)
            WT[i]=AT[i];
        else
            WT[i]=burst-AT[i];
        burst+=BT[i];
        Total+=WT[i];
    }
    Avg_WT=Total/n;
    
    // Logic for calculating Turn around time
    cmpl_T=0;
    Total=0;
    for(i=0;i<n;i++)
    {
        cmpl_T+=BT[i];
        TT[i]=cmpl_T-AT[i];
        Total+=TT[i];
    }
    Avg_TT=Total/n;
    
    // printing of outputs
    
    printf("Process ,Waiting_time ,TurnA_time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,WT[i],TT[i]);
    }
    printf("Average waiting time is : %f\n",Avg_WT);
    printf("Average turn around time is : %f\n",Avg_TT);
    return 0;
} 

//OUTPUT==>>

/tmp/E9RRWvcMld.o
Enter number of the process
3
Enter Arrival time and Burst time of the process
AT	BT
0 5
1 3
2 4
Process ,Waiting_time ,TurnA_time
1		0		5
2		4		7
3		6		10
Average waiting time is : 3.333333
Average turn around time is : 7.333333
