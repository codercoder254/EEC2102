//@a.d.a.n_noa😇
#include <stdio.h>

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int digits = 0;
    int temp = n;

    while(temp > 0)
    {
        digits++;
        temp /= 10;
    }
    printf("Number of digits in %d is: %d\n", n, digits);

    return 0;
}