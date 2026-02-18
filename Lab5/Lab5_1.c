#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int pid, at, bt, rt, ct, wt, tat, priority;
} Process;

void printResults(Process p[], int n) {
    float avgWT = 0, avgTAT = 0;
    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT/n);
}

void fcfs(Process p[], int n){
    int time = 0;
    printf("\nGantt Chart:\n|");
    for(int i=0;i<n;i++){
        if(time < p[i].at)
            time = p[i].at;
        p[i].ct = time + p[i].bt;
        time = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        printf(" P%d |",p[i].pid);
    }
    printResults(p,n);
}

void srtf(Process p[], int n){
    int completed=0, time=0, minIndex=-1;
    int minRT;

    printf("\nGantt Chart:\n|");

    while(completed != n){
        minRT = 9999;
        minIndex = -1;

        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt>0 && p[i].rt<minRT){
                minRT = p[i].rt;
                minIndex = i;
            }
        }

        if(minIndex==-1){
            time++;
            continue;
        }

        printf(" P%d |",p[minIndex].pid);
        p[minIndex].rt--;
        time++;

        if(p[minIndex].rt==0){
            completed++;
            p[minIndex].ct=time;
            p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
            p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
        }
    }
    printResults(p,n);
}

void roundRobin(Process p[], int n, int q){
    int time=0, completed=0;
    printf("\nGantt Chart:\n|");

    while(completed<n){
        int done=1;
        for(int i=0;i<n;i++){
            if(p[i].rt>0 && p[i].at<=time){
                done=0;
                if(p[i].rt>q){
                    time+=q;
                    p[i].rt-=q;
                    printf(" P%d |",p[i].pid);
                }else{
                    time+=p[i].rt;
                    printf(" P%d |",p[i].pid);
                    p[i].rt=0;
                    completed++;
                    p[i].ct=time;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                }
            }
        }
        if(done) time++;
    }
    printResults(p,n);
}

void priority(Process p[], int n){
    int time=0, completed=0;
    int visited[MAX]={0};

    printf("\nGantt Chart:\n|");

    while(completed<n){
        int maxP=-1, idx=-1;
        for(int i=0;i<n;i++){
            if(!visited[i] && p[i].at<=time){
                if(p[i].priority>maxP){
                    maxP=p[i].priority;
                    idx=i;
                }
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        visited[idx]=1;
        printf(" P%d |",p[idx].pid);
        time+=p[idx].bt;
        p[idx].ct=time;
        p[idx].tat=p[idx].ct-p[idx].at;
        p[idx].wt=p[idx].tat-p[idx].bt;
        completed++;
    }
    printResults(p,n);
}

int main(){
    Process p[MAX], temp[MAX];
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: "); scanf("%d",&p[i].at);
        printf("Burst Time: "); scanf("%d",&p[i].bt);
        printf("Priority: "); scanf("%d",&p[i].priority);
        p[i].rt=p[i].bt;
    }

    do{
        for(int i=0;i<n;i++) temp[i]=p[i];

        printf("\n1.FCFS\n2.SRTF\n3.Round Robin\n4.Priority\n5.Exit\nChoice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: fcfs(temp,n); break;
            case 2: srtf(temp,n); break;
            case 3: roundRobin(temp,n,10); break;
            case 4: priority(temp,n); break;
        }
    }while(choice!=5);

    return 0;
}
