#include <stdio.h>

struct Employee {
    int id;
    char name[100];
    char designation[100];
    char department[100];
    float basicSalary;
};

int main() {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", emp.name);

    printf("Enter Employee Designation: ");
    scanf(" %[^\n]s", emp.designation);

    printf("Enter Employee Department: ");
    scanf(" %[^\n]s", emp.department);

    printf("Enter Employee Basic Salary: ");
    scanf("%f", &emp.basicSalary);

    // Calculate allowances and deductions
    float hra = 0.3 * emp.basicSalary;
    float da = 0.2 * emp.basicSalary;
    float pf = 0.1 * emp.basicSalary;
    float grossSalary = emp.basicSalary + hra + da;
    float netSalary = grossSalary - pf;

    // Print pay slip
    printf("\n------------------ PAY SLIP ------------------\n");
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Department: %s\n", emp.department);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("HRA: %.2f\n", hra);
    printf("DA: %.2f\n", da);
    printf("PF: %.2f\n", pf);
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    return 0;
}
