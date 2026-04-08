#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void fcfs(int req[], int n, int head)
{
    int i, total = 0;
    for (i = 0; i < n; i++)
    {
        total += abs(req[i] - head);
        head = req[i];
    }
    printf("FCFS THM = %d\n", total);
}

void sstf(int req[], int n, int head)
{
    int visited[50] = {0};
    int i, count = 0, total = 0;

    while (count < n)
    {
        int min = 10000, index = -1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int dist = abs(req[i] - head);
                if (dist < min)
                {
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
    printf("SSTF THM= %d\n", total);
}

void scan(int req[], int n, int head, int disk_size)
{
    int i, total = 0, pos = 0;
    int arr[50];

    for(i = 0; i < n; i++)
        arr[i] = req[i];

    arr[n] = 0;
    n++;

    sort(arr, n);

    for(i = 0; i < n; i++)
    {
        if(head < arr[i])
        {
            pos = i;
            break;
        }
    }

    for(i = pos - 1; i >= 0; i--)
    {
        total += abs(head - arr[i]);
        head = arr[i];
    }

    for(i = pos; i < n; i++)
    {
        total += abs(head - arr[i]);
        head = arr[i];
    }

    printf("SCAN THM = %d\n", total);
}

void cscan(int req[], int n, int head, int disk_size)
{
    int i, total = 0, pos = 0;
    int arr[50];
    for(int i=0;i<n;i++){
        arr[i]=req[i];
    }
    sort(arr,n);
    int idx = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>head){
            idx=i;
            break;
        }
    }
    total+=abs(arr[idx]-head);
    for(int i=idx+1;i<n;i++){
        total+=abs(arr[i]-arr[i-1]);
    }
    total+=abs(disk_size-arr[n-1]);
    head=0;
    total+=arr[0];
    for(int i=1;i<idx;i++){
        total+=abs(arr[i]-arr[i-1]);
    }

    printf("C-SCAN THM = %d\n", total);
}
int main()
{
    int n, i, head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[50];

    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++)
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