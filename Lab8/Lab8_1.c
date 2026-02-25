#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    int total[3] = {10, 5, 7};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int alloc[n][3], max[n][3], need[n][3];
    int available[3];

    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("For Process P%d:\n", i);
        for(int j = 0; j < 3; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("\nEnter Max Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("For Process P%d:\n", i);
        for(int j = 0; j < 3; j++)
            scanf("%d", &max[i][j]);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(int j = 0; j < 3; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += alloc[i][j];
        available[j] = total[j] - sum;
    }

    printf("\nNeed Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for(int j = 0; j < 3; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for(int j = 0; j < 3; j++)
        printf("%d ", available[j]);
    printf("\n");

    bool finish[n];
    int safeSeq[n];
    int work[3];

    for(int i = 0; i < n; i++)
        finish[i] = false;

    for(int j = 0; j < 3; j++)
        work[j] = available[j];

    int count = 0;

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool safe = true;

                for(int j = 0; j < 3; j++) {
                    if(need[i][j] > work[j]) {
                        safe = false;
                        break;
                    }
                }

                if(safe) {
                    for(int j = 0; j < 3; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found) {
            printf("\nSystem is NOT SAFE\n");
            return 0;
        }
    }

    printf("\nSystem is SAFE.\nSafe Sequence: ");
    for(int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}