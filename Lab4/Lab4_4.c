#include <stdio.h>
#include <pthread.h>

int a[50], n;

void* bubble(void* p) {
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    return NULL;
}

void* selection(void* p) {
    int i, j, m, t;
    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[m])
                m = j;
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    printf("Enter Array Size\n");
    scanf("%d", &n);
    printf("Enter Array Elements\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    pthread_create(&t1, NULL, bubble, NULL);
    pthread_create(&t2, NULL, selection, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
