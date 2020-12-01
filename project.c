#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void admin_menu(void);
void admin_login(void);
void user_login(int a);
void user_menu(void);
void transaction(void);
void deposit(void);
void withdraw(void);
void balance(void);
void delete (void);
void record(void);
void check_password();

void main(void)
{
    int code;
    system("cls");
    system("color 3");
    printf("TEST");
    printf("THIS IS THE MAIN MENU.\n\n");
    printf("\n1) Admin login\n2) User login\n3) Exit Program\nChoose an option: ");
    printf("test");
    scanf("%d", &code);
    system("cls");
    if (code == 2)
    {
        user_login(0);
    }
    else if (code == 1)
    {
        admin_login();
    }
    else
    {
        exit(1);
    }
}

void user_login(int a)
{
    int code;
    int account_no;
    char password[1000];
    system("cls");
    printf("THIS IS THE USER LOGIN PAGE.\n\n");
    if (a)
    {
        printf("Account Successfully created.");
    }

    printf("\n1) Login\n2) Sign up\n3) Main menu\n4) Exit program\n Choose an option\n");
    scanf("%d", &code);
    if (code == 1)
    {
        system("cls");
        printf("Enter the Account Number: ");
        scanf("%d", &account_no);
        printf("Enter the Password: ");
        getchar();
        gets(password);

        if (1)
        {
            user_menu();
        }
    }
    else if (code == 2)
    {
        printf("Enter the Account Number: ");
        scanf("%d", &account_no);
        printf("Enter the Password: ");
        gets(password);
        if (check_password(&password))
        {
            user_login(1);
        }

        user_menu();
    }
    else if (code == 3)
    {
        main();
    }
    else
    {
        exit(1);
    }
}
void admin_login(void)
{
    char admin[] = "admin";
    int pass = 1234;
    char code1;

    int passcode;
    char tempadmin[6];
    system("cls");
    printf("THIS IS THE ADMIN LOGIN PAGE.\n\n");

    printf("Enter the username: ");
    getchar();
    gets(tempadmin);

    printf("Enter the Passcode: ");
    scanf("%d", &passcode);

    if (strcmp(admin, tempadmin) == 0 && pass == passcode)
    {

        admin_menu();
    }
    else
    {
        system("cls");
        printf("Incorrect. To try again enter y, to exit press n: ");
        scanf(" %c", &code1);
        if (code1 == 'y')
        {
            admin_login();
        }
        else
        {
            exit(1);
        }
    }
}

void user_menu(void)
{
    int code;
    system("cls");
    printf("THIS IS THE USER MENU.\n\n");

    printf("\n1) Transaction\n2) Deposit amount\n3) Withdraw amount\n4) Balance Statement\nChoose an option: ");
    scanf("%d", &code);

    switch (code)
    {
    case 1:
        transaction();
        break;
    case 2:
        deposit();
        break;
    case 3:
        withdraw();
        break;
    case 4:
        balance();
        break;
    default:
        main();
        break;
    }
}
void admin_menu(void)
{
    int code;
    system("cls");
    printf("THIS IS THE ADMIN MENU.\n\n");

    printf("\n1) Delete Account\n2) Show record\n3) Main Menu\n4) End program\nChoose an option: ");
    scanf("%d", &code);

    switch (code)
    {
    case 1:
        delete ();
        break;
    case 2:
        record();
        break;
    case 3:
        main();
        break;

    default:
        exit(1);
        break;
    }
}
void transaction(void)
{
    printf("Transaction done: ");
}
void deposit(void)
{
    printf("depost done: ");
}
void withdraw(void)
{
    printf("withdraw done: ");
}
void balance(void)
{
    printf("balance check: ");
}
void delete (void)
{
    printf("deleted: ");
}
void record(void)
{
    printf("here is the record: ");
}
void check_password()
{
    printf("Correct password\n");
}