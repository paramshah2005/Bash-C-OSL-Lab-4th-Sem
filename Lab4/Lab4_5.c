#include <stdio.h>
#include <pthread.h>

int fib[50], n;

void* generate(void* p) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return NULL;
}

int main() {
    pthread_t t;
    printf("Enter Size of Fibonnaci Series:\n");
    scanf("%d", &n);

    pthread_create(&t, NULL, generate, NULL);
    pthread_join(t, NULL);
    printf("Fibonacci Sequence\n");
    for (int i = 0; i < n; i++)
        printf("%d ", fib[i]);

}
