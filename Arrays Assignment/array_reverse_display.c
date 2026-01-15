#include <stdio.h>

int main()
{
    int n;
    printf("How many elements: ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n ; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}