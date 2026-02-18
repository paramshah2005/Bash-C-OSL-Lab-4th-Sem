#include <stdio.h>

typedef struct{
    int pid, arrival, burst, deadline;
    int completed;
} Process;

int main(){
    int n,time=0,completed=0,i,idx;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    Process p[n];

    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: "); scanf("%d",&p[i].arrival);
        printf("Burst Time: "); scanf("%d",&p[i].burst);
        printf("Deadline: "); scanf("%d",&p[i].deadline);
        p[i].completed=0;
    }

    printf("\nGantt Chart:\n|");

    while(completed<n){
        int earliest=9999;
        idx=-1;

        for(i=0;i<n;i++){
            if(!p[i].completed && p[i].arrival<=time){
                if(p[i].deadline<earliest){
                    earliest=p[i].deadline;
                    idx=i;
                }
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        printf(" P%d |",p[idx].pid);
        time+=p[idx].burst;
        p[idx].completed=1;
        completed++;
    }

    printf("\nEDF Scheduling Completed.\n");
    return 0;
}
