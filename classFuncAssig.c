#include <stdio.h>

const int password = 4321;

//login function
int login()
{
    int input_pass;
    printf("Enter password to login: ");
    scanf("%d", &input_pass);
    while(getchar() != '\n'); //rmv '\n' left in buffer by scanf

    int counter = 0;

    while(counter < 2 && input_pass != password)
    {
        printf("Error: Incorrect pin. Try again: %d attempts remaining\n:", (2-counter));
        counter++;
        scanf("%d", &input_pass);
        while(getchar() != '\n');
    }

    if(input_pass == password)
    {
        printf("Login successful!\n");
        return 1;
    }
    else
    {
        printf("Login failed. Exiting program.\n");
        return 0;
    }
}

//checkbalance function
void check_balance(int *Amount)
{
    printf("Your balance is $%d\n", *Amount);  
}

//withdraw function
int withdraw(int *Amount)
{
    int withdraw_Amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &withdraw_Amount);
    while(getchar() != '\n');
    while(withdraw_Amount > *Amount)
    {
        printf("Error: Insufficient funds.\n");
        printf("Your current balance is $%d\n", *Amount);
        printf("Would you wish to try again?(Y/N): ");
        char choice;
        scanf(" %c", &choice);
        while(getchar() != '\n');
        if(choice == 'Y' || choice == 'y')
        {
            printf("Enter amount to withdraw: ");
            scanf("%d", &withdraw_Amount);
            while(getchar() != '\n');
        }
        else
        {
            printf("Withdrawal cancelled.\n");
            return -2;
        }
    }

    if(withdraw_Amount <= *Amount)
    {
        *Amount -= withdraw_Amount;
        return 2;
    }


}

//deposit function
int deposit(int *Amount)
{
    int dep_Amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &dep_Amount);
    while(getchar() != '\n');
    *Amount += dep_Amount;

    return 3;

}



int main()
{
    int Amount = 1000;
    int *pointer_Amount = &Amount;
    int login_statuscode = login();

    while(login_statuscode != 1)
    {
        if(login_statuscode == 0)
        {
            printf("Exiting program...\n");
            return -1;
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
                check_balance(pointer_Amount);
                break;

            case 2:
                {
                    int wd_statuscode = withdraw(pointer_Amount);
                    if(wd_statuscode == 2)
                    {
                        printf("Withdrawal successful.\n");
                        check_balance(pointer_Amount);
                    }
                    break;
                }

            case 3:
                {
                    int dep_statuscode = deposit(pointer_Amount);
                    if(dep_statuscode == 3)
                    {
                        printf("Deposit successful.\n");
                        check_balance(pointer_Amount);
                    }
                    break;
                }

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

}