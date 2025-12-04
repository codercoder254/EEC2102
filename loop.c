//a.d.a.n_noa😇
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pin = 1234;
    int counter = 0;
    int input;
    printf("Enter PIN: ");
    scanf("%d", &input);

    
    while (input != pin && counter < 2)
    {
        fprintf(stderr, "Error: Incorrect PIN. Try again.\n");
        counter++;
        scanf("%d", &input);
    }
    

    /*
    for(int i = 0; i < 2; i++)
    {
        if(input == pin)
        {
            printf("Access granted.\n");
            break;
        }
        else
        {
            fprintf(stderr, "Error: Incorrect PIN. Try again.\n");
            scanf("%d", &input);
        }
    }
    */
    
    /*
    do
    { 
        if(input != pin)
        {
            fprintf(stderr, "Error: Incorrect PIN. Try again.\n");
            counter++;
            scanf("%d", &input);
        }
    }while(input != pin && counter < 2);
    */

    if (input == pin)
    {
        exit(0);
    }
    else
    {
        fprintf(stderr, "Access denied. Too many incorrect attempts.\n");
        return -1;
    }
    

    return 0;
}

/*

int pin = 1234; - set the actual pin
int counter = 0; - set a counter to zero, keep track of attempts
int input; - variable to hold user input

First it asks you to enter a PIN.  
The real PIN is 1234. If you type the wrong one, you get up to 2 more tries.

The top two blocks of code (the while-loop version and the for-loop version)
are just different ways of doing the same job. 

I left them inside  the / * ... * / so they don't run.  
If you remove the / * ... * / around them and run the program each at a time, 
each version works perfectly on its own.

The version that is running is the do–while loop.

do {                   - start the do-while loop
    if(input != pin)   - if the PIN is wrong
    {
        fprintf(stderr, "Error: Incorrect PIN. Try again.\n");
                         - print error message on the error stream
        counter++;        - add 1 attempt
        scanf("%d", &input);
                         - ask again for a new PIN
    }
} while(input != pin && counter < 2); -Basically just do whatever is in the do { },  while whatever is in the while( ) keeps happening.
                       - keep repeating while PIN is wrong AND
                         attempts are less than 3 total

if (input == pin)      - if the user finally got the correct PIN
{
    exit(0);           - end the program immediately (success)
}
else                   - if the user failed 3 times
{
    fprintf(stderr, "Access denied. Too many incorrect attempts.\n");
                         - show denied message
    return -1;            - return -1 to show failure
}

while(input != pin && counter < 2)
{
    fprintf(stderr, "Error: Incorrect PIN. Try again.\n"); - print error message on the error stream
    counter++; - add 1 attempt
    scanf("%d", &input); - ask again for a new PIN
}

for(int i = 0; i < 2; i++) - for loop version, do the following 2 times
{
    if(input == pin)
    {
        printf("Access granted.\n");
        break;
    }
    else
    {
        fprintf(stderr, "Error: Incorrect PIN. Try again.\n"); - print error message on the error stream
        scanf("%d", &input); - ask again for a new PIN
    }
}

return 0;

NOTE:
1.the simplest way is the while loop version at the top.Just 4 lines of code and you're done, easy road.
2.You can use printf instead of fprint just that its a norm for error messages to go to stderr.
3.using exit(0); is just a quick way to end the program immediately on success but  still not a better design for larger programs.Defined in stdlib.h
3.We count the first attempt as well, so counter starts at 0 and goes to 2 (3 attempts total).
4.A cleaner way is to use a function that returns success or failure codes. i.e int main() { int res = check_pin(); return res; }
5.The program is short and simple approximatly 30 lines of code, comments not included.
6.To compile and run:


Powershell:
$gcc loop.c -o loop.exe
$./loop.exe
$echo $?  - shows return code (0 = success, -1 = failure)


*/