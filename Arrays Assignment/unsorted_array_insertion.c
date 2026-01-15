#include <stdio.h>

int main()
{
    printf("How many elements: ");
    int N;
    scanf("%d", &N);

    int n = N + 1;

    int arr[n];
    for(int i = 0; i < n-1 ; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int position, value;
    printf("Enter the position to insert (1 to %d): ", n);
    scanf("%d", &position);
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if(position < 1 || position > n + 1)
    {
        printf("Invalid position!\n");
        return 1;
    }

    for(int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;


    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}