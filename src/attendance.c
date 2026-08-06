// this is the first demo 
#include <stdio.h>

struct Employee
{
    char name[50];
    int attendance;
};

void inputEmployees(struct Employee emp[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter employee %d name: ", i + 1);
        scanf("%s", emp[i].name);
    }
}

void markAttendance(struct Employee emp[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Is %s present? (1 = Present, 0 = Absent): ", emp[i].name);
        scanf("%d", &emp[i].attendance);
    }
}

int countPresent(struct Employee emp[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(emp[i].attendance == 1)
            count++;
    }

    return count;
}

int countAbsent(struct Employee emp[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(emp[i].attendance == 0)
            count++;
    }

    return count;
}

void displayReport(struct Employee emp[], int n)
{
    printf("\n----- Attendance Report -----\n");

    for(int i = 0; i < n; i++)
    {
        printf("%s\t", emp[i].name);

        if(emp[i].attendance == 1)
            printf("Present\n");
        else
            printf("Absent\n");
    }
}

int main()
{
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    inputEmployees(emp, n);

    markAttendance(emp, n);

    displayReport(emp, n);

    printf("\nTotal Present: %d\n", countPresent(emp, n));
    printf("Total Absent : %d\n", countAbsent(emp, n));

    return 0;
}