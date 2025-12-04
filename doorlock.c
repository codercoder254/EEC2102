//@a.d.a.n_noa😇
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int Key = 5321;

int deb_p(int pass_func)
{int deb_p(int pass_func)
{
    int n;
    do {
        n = pass_func;
        int digits = 0;
        int temp = n;
        const int ABSOLUTE_TERMINATION_CONDITION = 0;
        while (1)
        {
            if (temp == ABSOLUTE_TERMINATION_CONDITION)
            {
                if (digits == 0)
                {
                    digits = 1;
                }
                break;
        }

            digits++;
            temp /= 10;
        }

        if (digits != 4)
        {
            fprintf(stderr, "Error: Password must be exactly 4 digits long.\n");
            printf("Enter password again: ");
            scanf("%d", &pass_func);
            while (getchar() != '\n');
            continue;
        }

        int eas_pas[] = {
            0000, 1111,  3457, 2346,
            2222, 3333,  9876, 6542,
            4444, 5555,  2112, 3003,
            6666, 7777,  0411, 1029,
            8888, 9999,  2587, 369,
            1234, 4321,  1594, 8426,
            2468, 1357,  4321, 7654,
            987, 5678
        };
        size_t eas_count = sizeof(eas_pas) / sizeof(eas_pas[0]);

        int easy = 0;
        for (size_t Al_p = 0; Al_p < eas_count; Al_p++)
        {
            if (n == eas_pas[Al_p])
            {
                easy = 1;
                break;
            }
        }
        if (easy)
        {
            fprintf(stderr, "Error: Password is too easy to guess.\n");
            printf("Enter password again: ");
            scanf("%d", &pass_func);
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);
 return n;
}
}

int  change_password(int pass_func)
{
    int k_i;
    do
    {
        printf("Enter Key... ");
        scanf("%d", &k_i);
        while(getchar() != '\n');
        if(k_i != Key)
        {
            fprintf(stderr, "Error: Incorrect key entered.Try again\n");
        }
    }while(k_i != Key);
    printf("Enter old password: ");
    int old_p;
    do{
    scanf("%d", &old_p);
    while(getchar() != '\n');
    if(old_p != pass_func)
    {
        fprintf(stderr, "Error: Old password does not match current password.Try again\n");
    }
    }while(old_p != pass_func);
    printf("Enter new password: ");
    int nw_p;
    while (scanf("%d", &nw_p) != 1) {
        printf("Invalid input. Please enter a numeric password: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }while(getchar() != '\n');
    nw_p = deb_p(nw_p);
    printf("Password changed successfully.\n");
     return nw_p;
}

char* deb_u()
{
    char* u_n = malloc(50 * sizeof(char));
    if (!u_n) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(10);
    }

    int valid;

    do {
        valid = 1; // assume correct until proven guilty

        printf("Enter new username: ");
        fgets(u_n, 50, stdin);
        u_n[strcspn(u_n, "\n")] = '\0';
        if (strlen(u_n) < 8 || strlen(u_n) > 20){
            fprintf(stderr, "Error: Username must be between 8 and 20 characters long.\n");
            valid = 0;
            continue; }
        size_t ulen = strlen(u_n);
        for (size_t i = 0; i < ulen; i++)
        {
            if ((u_n[i] < 'a' || u_n[i] > 'z') &&
                (u_n[i] < 'A' || u_n[i] > 'Z'))
            {
                if ((u_n[i] < '0' || u_n[i] > '9') &&
                    u_n[i] != '_' && u_n[i] != '@')
                {
                    fprintf(stderr, "Error: Username contains invalid characters.\n");
                    valid = 0;
                    break;
                }
            }
        }
    } while (!valid);
    return u_n;
}

char* change_username(char *user_func)
{
printf("Enter Key... ");
int k_i;
do {
    scanf("%d", &k_i);
    while (getchar() != '\n');
    if (k_i != Key) {
        fprintf(stderr, "Error: Incorrect key entered.\n");
        printf("Enter Key... ");
    }
} while (k_i != Key);
char old_u[50];
do {
    printf("Enter old username: ");
    fgets(old_u, sizeof(old_u), stdin);
    old_u[strcspn(old_u, "\n")] = '\0';
    if (strcmp(old_u, user_func) != 0) {
        fprintf(stderr, "Error: Old username does not match current username.\n");
    }
} while (strcmp(old_u, user_func) != 0);
char* nw_u = deb_u();
printf("Username changed successfully.\n");
return nw_u;
}


int main()
{
   int def_pass = 1234;
   char* def_user = malloc(20 * sizeof(char));
   strcpy(def_user, "admin");
   printf("Hello %s\n", def_user);
   printf("Your default password is '%d'\n", def_pass);
   printf("YOur default username is '%s'\n", def_user);
   printf("Please change your default credentials\n");
   
   while(1)
   { 
    printf("__________MENU__________\n");
    printf("1. Change Username\n");
    printf("2. Change Password\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");

    int ch_char;
    scanf("%d", &ch_char);
    int c;
    while ((c =getchar()) != '\n' && c != EOF);
    switch(ch_char)
    {
        case 1:
            char* tmp_user;
            tmp_user = change_username(def_user);
            free(def_user);
            def_user = tmp_user;
            break;

        case 2:
            def_pass = change_password(def_pass);
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again. \n");
            break;
    }
   }

   return 0;
}