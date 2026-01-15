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

    int min, max;
    min = max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
}