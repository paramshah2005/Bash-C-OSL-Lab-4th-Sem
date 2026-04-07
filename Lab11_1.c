#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void fcfs(int req[], int n, int head) {
    int i, total = 0;
    for(i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
    }
    printf("FCFS Total Head Movement = %d\n", total);
}

void sstf(int req[], int n, int head) {
    int visited[50] = {0};
    int i, count = 0, total = 0;

    while(count < n) {
        int min = 10000, index = -1;
        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                int dist = abs(req[i] - head);
                if(dist < min) {
                    min = dist;
                    index = i;
                }
            }
        }
        visited[index] = 1;
        total += min;
        head = req[index];
        count++;
    }
    printf("SSTF Total Head Movement = %d\n", total);
}

void scan(int req[], int n, int head, int disk_size) {
    int i, total = 0;
    int arr[50];

    for(i = 0; i < n; i++)
        arr[i] = req[i];

    arr[n] = disk_size - 1;
    n++;

    sort(arr, n);

    int pos;
    for(i = 0; i < n; i++) {
        if(head < arr[i]) {
            pos = i;
            break;
        }
    }

    for(i = pos; i < n; i++) {
        total += abs(arr[i] - head);
        head = arr[i];
    }

    for(i = pos - 1; i >= 0; i--) {
        total += abs(arr[i] - head);
        head = arr[i];
    }

    printf("SCAN Total Head Movement = %d\n", total);
}

void cscan(int req[], int n, int head, int disk_size) {
    int i, total = 0;
    int arr[50];

    for(i = 0; i < n; i++)
        arr[i] = req[i];

    arr[n] = disk_size - 1;
    arr[n + 1] = 0;
    n += 2;

    sort(arr, n);

    int pos;
    for(i = 0; i < n; i++) {
        if(head < arr[i]) {
            pos = i;
            break;
        }
    }

    for(i = pos; i < n; i++) {
        total += abs(arr[i] - head);
        head = arr[i];
    }

    for(i = 0; i < pos; i++) {
        total += abs(arr[i] - head);
        head = arr[i];
    }

    printf("C-SCAN Total Head Movement = %d\n", total);
}

int main() {
    int n, i, head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[50];

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    fcfs(req, n, head);
    sstf(req, n, head);
    scan(req, n, head, disk_size);
    cscan(req, n, head, disk_size);

    return 0;
}