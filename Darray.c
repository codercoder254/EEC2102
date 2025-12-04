#include <stdio.h>

int main()
{
    unsigned long long pin;
    printf("Enter pin: ");
    scanf("%llu", &pin);

    
    int counter = 0;
    while(pin > 0)
    {
        pin /= 10; //pin = pin / 10;
        counter++;//counter = counter + 1;
    }

    printf("Total digits: %d\n", counter);

    return 0;
    
}