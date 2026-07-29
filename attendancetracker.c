#include <stdio.h>
#include <ctype.h> // For toupper() function

#define MAX_NAME_LEN 50
#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char status; // 'P' or 'p' for Present, 'A' or 'a' for Absent
} Employee;

// Function Prototypes
void inputEmployeeData(Employee emp[], int size);
void displayEmployees(const Employee emp[], int size);
int countPresent(const Employee emp[], int size);
int countAbsent(const Employee emp[], int size);

int main() {
    int n;

    printf("======================================\n");
    printf("     EMPLOYEE ATTENDANCE TRACKER      \n");
    printf("======================================\n");

    // Get number of employees
    printf("Enter the number of employees (1 to %d): ", MAX_EMPLOYEES);
    scanf("%d", &n);

    // Basic range validation
    if (n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid number of employees. Exiting program.\n");
        return 1;
    }

    // Array of structures
    Employee employees[n];

    // 1. Input Data
    inputEmployeeData(employees, n);

    // 2. Display Records
    displayEmployees(employees, n);

    // 3 & 4. Calculate and Display Attendance Summary
    int presentCount = countPresent(employees, n);
    int absentCount = countAbsent(employees, n);

    printf("--------------------------------------\n");
    printf("          ATTENDANCE SUMMARY          \n");
    printf("--------------------------------------\n");
    printf("Total Employees : %d\n", n);
    printf("Total Present   : %d\n", presentCount);
    printf("Total Absent    : %d\n", absentCount);
    printf("======================================\n");

    return 0;
}

// Function 1: Input details for all employees with input validation
void inputEmployeeData(Employee emp[], int size) {
    printf("\n--- Enter Employee Details ---\n");
    for (int i = 0; i < size; i++) {
        printf("\nEmployee #%d:\n", i + 1);

        printf("  Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("  Enter Name: ");
        // Read full string including spaces safely
        scanf(" %[^\n]", emp[i].name);

        // Loop until a valid status ('P', 'p', 'A', 'a') is entered
        do {
            printf("  Enter Status (P for Present, A for Absent): ");
            scanf(" %c", &emp[i].status);

            // Convert to uppercase for standard checks
            emp[i].status = toupper(emp[i].status);

            if (emp[i].status != 'P' && emp[i].status != 'A') {
                printf("  [Error] Invalid status! Please enter 'P' or 'A'.\n");
            }
        } while (emp[i].status != 'P' && emp[i].status != 'A');
    }
}

// Function 2: Display all employee records in tabular format
void displayEmployees(const Employee emp[], int size) {
    printf("\n======================================\n");
    printf("           EMPLOYEE RECORDS           \n");
    printf("======================================\n");
    printf("%-10s %-25s %-10s\n", "ID", "Name", "Status");
    printf("--------------------------------------\n");

    for (int i = 0; i < size; i++) {
        char *statusStr = (emp[i].status == 'P') ? "Present" : "Absent";
        printf("%-10d %-25s %-10s\n", emp[i].id, emp[i].name, statusStr);
    }
}

// Function 3: Count the total number of present employees
int countPresent(const Employee emp[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (emp[i].status == 'P') {
            count++;
        }
    }
    return count;
}

// Function 4: Count the total number of absent employees
int countAbsent(const Employee emp[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (emp[i].status == 'A') {
            count++;
        }
    }
    return count;
}