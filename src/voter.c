#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_VOTERS 100

// Structure for storing voter information
struct Voter
{
    char name[50];
    int age;
    char id[20];
};

// Function to clear unwanted input from the keyboard buffer
void clearInputBuffer()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // Clear remaining characters
    }
}

// Function to safely get a positive integer
int getPositiveInteger(char message[])
{
    int value;

    while (1)
    {
        printf("%s", message);

        if (scanf("%d", &value) == 1)
        {
            clearInputBuffer();

            if (value > 0)
            {
                return value;
            }

            printf("\n  [!] Invalid input! Please enter a positive number.\n\n");
        }
        else
        {
            printf("\n  [!] Invalid input! Please enter a number.\n\n");
            clearInputBuffer();
        }
    }
}

// Function to check voter eligibility
int checkEligible(int age)
{
    return (age >= 18);
}

// Function to display a line
void printLine()
{
    printf("==================================================\n");
}

int main()
{
    struct Voter voters[MAX_VOTERS];
    int n;

    // ==============================
    // Welcome Screen
    // ==============================

    printLine();
    printf("             VOTER REGISTRATION SYSTEM\n");
    printLine();

    printf("\nThis system stores voter information and\n");
    printf("checks voting eligibility based on age.\n\n");

    // ==============================
    // Number of Voters
    // ==============================

    while (1)
    {
        n = getPositiveInteger("Enter number of voters (1-100): ");

        if (n <= MAX_VOTERS)
        {
            break;
        }

        printf("\n  [!] Maximum allowed voters is %d.\n\n", MAX_VOTERS);
    }

    // ==============================
    // Input Voter Information
    // ==============================

    printf("\n");
    printLine();
    printf("              ENTER VOTER INFORMATION\n");
    printLine();

    for (int i = 0; i < n; i++)
    {
        printf("\n--------------- Voter %d ---------------\n", i + 1);

        // Name
        printf("Name       : ");
        scanf("%49s", voters[i].name);
        clearInputBuffer();

        // Age
        voters[i].age = getPositiveInteger("Age        : ");

        // Voter ID
        printf("Voter ID   : ");
        scanf("%19s", voters[i].id);
        clearInputBuffer();
    }

    // ==============================
    // Display Results
    // ==============================

    printf("\n\n");
    printLine();
    printf("               VOTER RESULTS\n");
    printLine();

    for (int i = 0; i < n; i++)
    {
        printf("\nVoter %d\n", i + 1);
        printf("------------------------------------------\n");
        printf("Name       : %s\n", voters[i].name);
        printf("Age        : %d\n", voters[i].age);
        printf("Voter ID   : %s\n", voters[i].id);

        // Eligibility check
        if (checkEligible(voters[i].age))
        {
            printf("Status     : ELIGIBLE TO VOTE\n");
        }
        else
        {
            printf("Status     : NOT ELIGIBLE TO VOTE\n");
        }
    }

    // ==============================
    // Summary
    // ==============================

    int eligible = 0;
    int notEligible = 0;

    for (int i = 0; i < n; i++)
    {
        if (checkEligible(voters[i].age))
        {
            eligible++;
        }
        else
        {
            notEligible++;
        }
    }

    printf("\n");
    printLine();
    printf("                 SUMMARY\n");
    printLine();

    printf("Total Voters          : %d\n", n);
    printf("Eligible Voters       : %d\n", eligible);
    printf("Not Eligible Voters   : %d\n", notEligible);

    printLine();

    printf("\nThank you for using the Voter Registration System!\n\n");

    return 0;
}