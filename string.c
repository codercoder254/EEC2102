//@a.d.a.n_noa😇            
#include <stdio.h>

int main()
{
    char arr[50];
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);
    printf("You entered: %s\n", arr);

    int counter = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        counter++;
    }
    printf("Length of the string: %d\n", counter);


    return 0;
}