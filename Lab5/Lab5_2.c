#include <stdio.h>

int main(){
    int n,i,time=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int bt[n], rt[n], level[n];

    for(i=0;i<n;i++){
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
        level[i]=0;
    }

    printf("\nGantt Chart:\n|");

    for(i=0;i<n;i++){
        if(rt[i]>8){
            printf(" P%d |",i+1);
            time+=8;
            rt[i]-=8;
            level[i]=1;
        }else{
            printf(" P%d |",i+1);
            time+=rt[i];
            rt[i]=0;
        }
    }

    for(i=0;i<n;i++){
        if(rt[i]>0 && level[i]==1){
            if(rt[i]>16){
                printf(" P%d |",i+1);
                time+=16;
                rt[i]-=16;
                level[i]=2;
            }else{
                printf(" P%d |",i+1);
                time+=rt[i];
                rt[i]=0;
            }
        }
    }

    for(i=0;i<n;i++){
        if(rt[i]>0){
            printf(" P%d |",i+1);
            time+=rt[i];
            rt[i]=0;
        }
    }

    printf("\nTotal Execution Time = %d\n",time);
    return 0;
}
