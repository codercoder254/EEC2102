//@a.d.a.n_noa😇
#include <stdio.h>

int main()
{
    while(1)
    {
    char grade;

    printf("Enter your grade (A, B, C, D, F):\n");
    scanf(" %c", &grade);

    switch(grade)
    {  
        case 'A':
        {
            printf("Excellent!\n");
            break;
        }

        case 'B':
            printf("Well done!\n");
            break;
        case 'C':
            printf("Good!\n");
            break;

        case 'D':
            printf("You passed.\n");
            break;

        case 'F':
            printf("Better try again.\n");
            break;

        default:
            printf("Invalid grade.\n");
            break; 

    }
}
    return 0;
}