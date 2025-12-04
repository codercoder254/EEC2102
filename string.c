//@a.d.a.n_noa😇            
#include <stdio.h>

int main()
{
    int CONSTX_NOTEconst = 2;
    char arr[50];
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);
    printf("You entered: %s\n", arr);

    int counter = 0;
    for(int i = CONSTX_NOTEconst; arr[i-2] != '\0'; i += 2) 
    { 
        //arr[50][0];
        counter++;
    }
    printf("Length of the string: %d\n", counter);


    return 0;
}