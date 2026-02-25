#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m];
    int request[n][m];
    int available[m];

    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("For Process P%d:\n", i);
        for(int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\nEnter Request Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("For Process P%d:\n", i);
        for(int j = 0; j < m; j++)
            scanf("%d", &request[i][j]);
    }

    printf("\nEnter Available Resources:\n");
    for(int j = 0; j < m; j++)
        scanf("%d", &available[j]);

    bool finish[n];
    int work[m];

    for(int i = 0; i < n; i++) {
        bool zeroAlloc = true;
        for(int j = 0; j < m; j++) {
            if(allocation[i][j] != 0) {
                zeroAlloc = false;
                break;
            }
        }
        finish[i] = zeroAlloc;
    }

    for(int j = 0; j < m; j++)
        work[j] = available[j];

    bool found;
    do {
        found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool possible = true;

                for(int j = 0; j < m; j++) {
                    if(request[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }

                if(possible) {
                    for(int j = 0; j < m; j++)
                        work[j] += allocation[i][j];

                    finish[i] = true;
                    found = true;
                }
            }
        }

    } while(found);

    bool deadlock = false;

    for(int i = 0; i < n; i++) {
        if(!finish[i]) {
            printf("Process P%d is deadlocked\n", i);
            deadlock = true;
        }
    }

    if(!deadlock)
        printf("System is NOT deadlocked\n");
    else
        printf("System is in DEADLOCK state\n");

    return 0;
}