#include <stdio.h>

struct Employee
{
    char name[50];
    char attendance;
};

// Function to input employee names
void inputEmployees(struct Employee emp[], int n)
{
    printf("\n=========================================\n");
    printf("         ENTER EMPLOYEE NAMES\n");
    printf("=========================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("Employee %d Name : ", i + 1);
        scanf("%49s", emp[i].name);
    }
}

// Function to mark attendance
void markAttendance(struct Employee emp[], int n)
{
    char choice;

    printf("\n=========================================\n");
    printf("          MARK ATTENDANCE\n");
    printf("=========================================\n");

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            printf("Attendance for %-15s (P/A): ", emp[i].name);
            scanf(" %c", &choice);

            if (choice == 'P' || choice == 'p' ||
                choice == 'A' || choice == 'a')
            {
                // Convert lowercase to uppercase
                if (choice == 'p')
                    choice = 'P';

                if (choice == 'a')
                    choice = 'A';

                emp[i].attendance = choice;
                break;
            }
            else
            {
                printf("Invalid input! Please enter only P or A.\n\n");
            }
        }
    }
}

// Function to count present employees
int countPresent(struct Employee emp[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (emp[i].attendance == 'P')
        {
            count++;
        }
    }

    return count;
}

// Function to count absent employees
int countAbsent(struct Employee emp[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (emp[i].attendance == 'A')
        {
            count++;
        }
    }

    return count;
}

// Function to display attendance report
void displayReport(struct Employee emp[], int n)
{
    printf("\n===============================================\n");
    printf("         EMPLOYEE ATTENDANCE REPORT\n");
    printf("===============================================\n");

    printf("%-20s %-10s\n", "Employee Name", "Status");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        if (emp[i].attendance == 'P')
        {
            printf("%-20s %-10s\n", emp[i].name, "Present");
        }
        else
        {
            printf("%-20s %-10s\n", emp[i].name, "Absent");
        }
    }

    printf("-----------------------------------------------\n");
    printf("Total Present : %d\n", countPresent(emp, n));
    printf("Total Absent  : %d\n", countAbsent(emp, n));
    printf("===============================================\n");
}

int main()
{
    int n;

    printf("=========================================\n");
    printf("     EMPLOYEE ATTENDANCE TRACKER\n");
    printf("=========================================\n");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    inputEmployees(emp, n);

    markAttendance(emp, n);

    displayReport(emp, n);

    printf("\nThank you for using the Employee Attendance Tracker!\n");

    return 0;
}