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

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] =  arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array in ascending order:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}