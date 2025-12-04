//@a.d.a.n_noa😇
//ENE212-0082/2024 ADAN Onyancha
//Simulated ATM system with login, check balance, withdraw, and deposit functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int password = 1234;

//login function

int login()
{
    int input_pass;
    printf("Enter password to login: ");
    while(scanf("%d", &input_pass) == 0)
    {
        printf("Invalid input. Please enter a numeric number: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n'); //removs \n that's lft in buffer by scanf
    //determining number of digits
    int digits = 0;
    int temp = input_pass;
    while(temp > 0)
    {
        temp /= 10;
        digits++;
    }
    
    int counter = 0;
    while(digits != 4 && counter < 2)
    {
        printf("Error: Password must be 4 digits long.\n");
        printf("Try again: %d attempt(s) left\n", (2 - counter));
        counter++;
        scanf("%d", &input_pass);
        while(getchar() != '\n');

        digits = 0;
        int temp = input_pass; 
        while(temp > 0)
        {
            temp /= 10;
            digits++;
        }
    }

    while(counter < 2 && input_pass != password)
    {
        printf("Error: Incorrect pin. Try again: %d attempts remaining\n:", (2-counter));
        counter++;
        scanf("%d", &input_pass);
        while(getchar() != '\n');
    }

    if(counter >= 2)
    {
        fprintf(stderr, "Access denied. Too many incorrect attempts.\n");
        return -1;
    }

    if(input_pass == password)
    {
        printf("Login successful.\n");
        return 1;
    }

}

//check balance function
void check_balance(long *ptr_Amount)
{
    printf("Your balance is $%d\n", *ptr_Amount);
}

//withdraw function
int withdraw(long *ptr_Amount)
{
    long wd_Amount;
    printf("Enter amount to withdraw: ");
    scanf("%ld", &wd_Amount);
    while(getchar() != '\n');
    while(wd_Amount > *ptr_Amount)
    {
        printf("Error: Insufficient funds. Your current balance is $%ld\n", *ptr_Amount);
        printf("Would you wish to try again?(Y/N): ");
        char choice;
        while(scanf(" %c", &choice) == 0)
        {
            printf("Invalid input. Please enter Y or N: ");
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        char choise_lower = tolower(choice);
        if(choise_lower == 'y')
        {
            printf("Enter amount to withdraw: ");
            scanf("%d", &wd_Amount);
            while(getchar() != '\n');
        }
        else
        {
            printf("Withdrawal cancelled.\n");
            return -2;
        }
    }

    if(wd_Amount <= *ptr_Amount)
    {
        *ptr_Amount -= wd_Amount;
        return 2;
    }
}

//deposit function
int deposit(long *ptr_Amount)
{
    int dep_Amount;
    printf("Enter amount to deposit: ");
    while(scanf("%d", &dep_Amount) == 0)
    {
        printf("Invalid input. Please enter a numeric amount: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');
    *ptr_Amount += dep_Amount;

    return 3;
}


int main()
{
    long Amount = 1000;
    long* ptr_Amount = &Amount;
    int login_statuscode = login();

    while(login_statuscode == -1)
    {
        printf("Seems there was an issue logging in. Would you like to try again? (Y/N): ");
        char retry_choice;
        while(scanf(" %c", &retry_choice) == 0)
        {
            printf("Invalid input. Please enter Y or N: ");
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        char retry_choice_lower = tolower(retry_choice);
        if(retry_choice_lower == 'n')
        {
            printf("Login required. Please choose an option:\n");
            while(login_statuscode == -1)
            {
                printf("_________MENU__________\n");
                printf("1. Login\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                int menu_choice;
                while(scanf("%d", &menu_choice) == 0)
                {
                    printf("Invalid input. Please enter a numeric choice: ");
                    while(getchar() != '\n');
                }
                while(getchar() != '\n');
                switch(menu_choice)
                {
                    case 1:
                        login_statuscode = login();
                        break;

                    case 2:
                        printf("Exiting...\n");
                        exit(0);

                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }
            }
        }
        else
        {
            printf("Retrying login...\n");
            login_statuscode = login();
        }
    }
    

    while(1)
    {
        int counter_login = 0;

        //menu
        printf("__________MENU__________\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        while(scanf("%d", &choice) == 0)
        {
            printf("Invalid input. Please enter a numeric choice: ");
            while(getchar() != '\n');
        }
        while(getchar() != '\n');

        switch(choice)
        {
            case 1:
                check_balance(ptr_Amount);
                break;

            case 2:
                {
                    int wd_statuscode = withdraw(ptr_Amount);
                    if(wd_statuscode == 2)
                    {
                        printf("Withdrawal successful.\n");
                        check_balance(ptr_Amount);
                    }
                    break;
                }

            case 3:
                {
                    int dep_statuscode = deposit(ptr_Amount);
                    if(dep_statuscode == 3)
                    {
                        printf("Deposit successful.\n");
                        check_balance(ptr_Amount);
                    }
                    break;
                }

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}