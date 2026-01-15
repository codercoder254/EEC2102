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

    printf("Unique elements in the array: ");

    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < n ; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count == 1)
        {
            printf("%d ", arr[i]);
        }


    }

    
}