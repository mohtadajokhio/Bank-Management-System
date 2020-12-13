#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

void admin_menu(void);
void admin_login(void);
void user_login();
void user_menu(void);
void transaction(int user_account);
void deposit(int user_account);
void withdraw(void);
int balance(int user_account);
void delete (int user_account);
void record(void);
int check_password(char pass[100]);
void encrypt(char password[100], int key);
typedef struct
{
    int account;
    char password[100];
    char name[1000];
    int balance;
    char email[1000];

} user;

void main(void)
{

    int code;
    system("cls");
    system("color 3");
    printf("THIS IS THE MAIN MENU.\n\n");
    printf("\n1) Admin login\n2) User login\n3) Exit Program\nChoose an option: ");
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

void user_login()
{
    int code, account_no, key;
    char password[1000];
    user person;
    FILE *login;
    FILE *signup;
    signup = fopen("record.txt", "a");
    login = fopen("record.txt", "r");
    system("cls");
    char temp;

    printf("\n1) Login\n2) Sign up\n3) Main menu\n4) Exit program\n Choose an option\n");
    scanf("%d", &code);
    if (code == 1)
    {
        system("cls");
    here:
        printf("Enter the Account Number: ");
        scanf("%d", &account_no);
        printf("Enter the Password: ");
        getchar();
        gets(password);
        printf("Enter the key: ");
        scanf("%d", &key);
        encrypt(password, key);
        while (fscanf(login, "%d %s %s %d %s\n", &person.account, &person.password, &person.name, &person.balance, &person.email) != EOF)
        {
            if (account_no == person.account && strcmp(password, person.password) == 0)
            {
                fclose(login);
                fclose(signup);
                user_menu();
            }
        }
        printf("Incorrect Account or Password. \n1) Try again\n2) Main Menu\nOption: ");
        scanf("%d", &code);
        if (code == 1)
        {
            goto here;
        }
        else
        {
            main();
        }
    }
    else if (code == 2)
    {
        printf("Enter the Account Number: ");
        scanf("%d", &person.account);

        printf("Enter the Password: ");
        getchar();
        gets(person.password);

        printf("Enter the encryption key: ");
        scanf("%d", &key);
        encrypt(person.password, key);

        printf("Enter the Name: ");
        getchar();
        gets(person.name);

        printf("Enter the Money to deposit: ");
        scanf("%d", &person.balance);

        printf("Enter the Email: ");
        getchar();
        gets(person.email);

        fprintf(signup, "%d %s %s %d %s\n", person.account, person.password, person.name, person.balance, person.email);
        fclose(login);
        fclose(signup);

        printf("Account created. \n1) Main menu\n2)User menu \nOption: ");
        scanf("%d", &code);
        if (code == 1)
        {
            main();
        }
        else
        {
            user_login();
        }
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
    // case 1:
    //     transaction();
    //     break;
    // case 2:
    //     deposit();
    //     break;
    // case 3:
    //     withdraw();
    //     break;
    // case 4:
    //     balance();
    //     break;
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
    // case 1:
    //     delete ();
    //     break;
    // case 2:
    //     record();
    //     break;
    case 3:
        main();
        break;
    default:
        exit(1);
        break;
    }
}
void transaction(int user_account)
{
    // scanf account
    ///update account
    printf("Transaction done: ");
}
void deposit(int user_account)
{
    //scanf amount
    //update
    printf("depost done: ");
}
void withdraw(void)
{
    //scanf ammount
    //update
    printf("withdraw done: ");
}
int balance(int user_account)
{
    // Find account in file
    //
    printf("balance check: ");
}
void delete (int user_account)
{

    printf("deleted: ");
}
void record(void)
{

    printf("here is the record: ");
}
int check_password(char pass[100])
{
    int len = strlen(pass);
    printf("Correct password\n");
}
void encrypt(char password[100], int key)
{
    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {

        if (password[i] == '!')
        {
            password[i] = '!';
        }

        else if (password[i] == ',')
        {
            password[i] = ',';
        }

        else if (isspace(password[i]))
        {
            password[i] = ' ';
        }
        else if (isupper(password[i]))
        {
            int p1 = password[i] - 65;
            char c1 = ((p1 + key) % 26) + 65;
            password[i] = c1;
        }

        else if (islower(password[i]))
        {
            int p2 = password[i] - 97;
            char c2 = ((p2 + key) % 26) + 97;
            password[i] = c2;
        }
    }
    return;
}