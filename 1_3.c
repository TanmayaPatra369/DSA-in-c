#include<stdio.h>
#include <stdio.h>


struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
    float grossSalary;
};


float calculateGrossSalary(struct Employee emp) {
    float hra = (emp.hraPercentage / 100) * emp.basicSalary;
    float da = (emp.daPercentage / 100) * emp.basicSalary;
    return emp.basicSalary + hra + da;
}

int main() {
    int n;

    
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    
    struct Employee employees[n];

    
    for (int i = 0; i < n; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("Emp-ID: ");
        scanf("%d", &employees[i].empId);
        printf("Name: ");
        scanf("%s", employees[i].name);  
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hraPercentage);
        printf("DA Percentage: ");
        scanf("%f", &employees[i].daPercentage);

        
        float grossSalary;
        employees[i].grossSalary= calculateGrossSalary(employees[i]);
        printf("\n");
    }

    
    printf("Employee Information with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Emp-ID: %d\n", employees[i].empId);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("Gross Salary: %.2f\n", employees[i].grossSalary);
        printf("\n");
    }

    return 0;
}

