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

void clook(int req[], int n, int head, int prev_head, int disk_size)
{
    int arr[50];

    for (int i = 0; i < n; i++)
        arr[i] = req[i];

    sort(arr, n);

    int direction = (prev_head > head) ? 0 : 1;
    int total = 0, index, i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] >= head)
        {
            index = i;
            break;
        }
    }

    if (i == n)
        index = n;

    if (direction == 1)
    {
        for (i = index; i < n; i++)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }

        if (index > 0)
        {
            total += abs(head - arr[0]);
            head = arr[0];
        }

        for (i = 1; i < index; i++)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }

        if (index < n)
        {
            total += abs(head - arr[n - 1]);
            head = arr[n - 1];
        }

        for (i = n - 2; i >= index; i--)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }
    }

    printf("\nC-LOOK THM: %d \n", total);
}

void look(int req[], int n, int head, int prev_head, int disk_size)
{
    int arr[50];
    for (int i = 0; i < n; i++)
    {
        arr[i] = req[i];
    }
    sort(arr, n);
    int direction = (prev_head > head) ? 0 : 1;
    int i, total = 0, index;
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= head)
        {
            index = i;
            break;
        }
    }
    if (i == n)
    {
        index = n;
    }
    if (direction == 1)
    {
        for (i = index; i < n; i++)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }
        for (i = index - 1; i >= 0; i--)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }
        for (i = index; i < n; i++)
        {
            total += abs(head - arr[i]);
            head = arr[i];
        }
    }
    printf("Look THM: %d", total);
}

int main()
{
    int n, i, head, prev_head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[50];

    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter previous head position: ");
    scanf("%d", &prev_head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    look(req, n, head, prev_head, disk_size);
    clook(req, n, head, prev_head, disk_size);

    return 0;
}