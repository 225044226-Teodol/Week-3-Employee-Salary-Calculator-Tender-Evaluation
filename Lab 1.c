#include <stdio.h> 

int main()
{
    // We're processing 3 employees — this makes it easy to change the number later
    const int NUM_EMPLOYEES = 3;

    // Arrays: each one holds 3 values, one slot per employee
    // for example basicSalary[0] = employee 1's basic salary, basicSalary[1] = employee 2's, etc.
    float basicSalary[3];
    float housing[3];
    float transport[3];
    float tax[3];
    float grossSalary[3];
    float netSalary[3];

    // This loop runs 3 times (i = 0, 1, 2) — once per employee
    // Each time, it asks for that employee's details and stores them in the matching array slot
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        // i + 1 is just so we display "Employee 1" instead of "Employee 0" (arrays start at 0, humans don't)
        printf("\n--- Employee %d ---\n", i + 1);

        printf("Enter basic salary: ");
        scanf("%f", &basicSalary[i]);   // stores the input into slot i of the array

        printf("Enter housing allowance: ");
        scanf("%f", &housing[i]);

        printf("Enter transport allowance: ");
        scanf("%f", &transport[i]);

        printf("Enter tax: ");
        scanf("%f", &tax[i]);

        // Calculate this employee's gross and net salary right away, using their own array slot
        grossSalary[i] = basicSalary[i] + housing[i] + transport[i];
        netSalary[i] = grossSalary[i] - tax[i];
    }

    // Second loop: now that all data is captured, print a report for every employee
    printf("\n--- Salary Report ---\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Gross Salary: %.2f\n", grossSalary[i]);
        printf("Net Salary: %.2f\n", netSalary[i]);

        // Business rule: if net salary is 20000 or more, flag as High Income
        if (netSalary[i] >= 20000)
        {
            printf("Income Level: High Income\n");
        }
        else
        {
            printf("Income Level: Standard Income\n");
        }
    }

    return 0;  
}