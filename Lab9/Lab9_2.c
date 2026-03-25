#include <stdio.h>

int main()
{
    int page_size = 32;
    int total_memory = 256;
    int logical_address;

    printf("Enter logical address: ");
    scanf("%d", &logical_address);

    int page_number = logical_address / page_size;
    int offset = logical_address % page_size;

    printf("\nPage Number = %d\n", page_number);
    printf("Offset = %d\n", offset);

    int temp = total_memory;
    int bits = 0;

    while (temp > 1)
    {
        temp = temp / 2;
        bits++;
    }

    printf("Number of bits required = %d\n", bits);

    return 0;
}