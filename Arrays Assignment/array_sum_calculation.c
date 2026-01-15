#include <stdio.h>

int main()
{
    printf("How many elements: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n ; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("Sum of array elements: %d\n", sum);
}