#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Employee {
    int id;
    char name[50];
    char department[20];
    char designation[20];
    float salary;
    struct Date joinDate;
    char phone[20];
    char email[50];
    int expYears;
};

int calculateExperience(struct Date d) {
    int currentYear = 2025;
    return currentYear - d.year;
}

void computeExperience(struct Employee emp[], int n) {
    for(int i = 0; i < n; i++) {
        emp[i].expYears = calculateExperience(emp[i].joinDate);
    }
}

void departmentStats(struct Employee emp[], int n) {
    float sum = 0;
    int count = 0;
    char dept[20];
    printf("Enter department: ");
    scanf("%s", dept);

    for(int i = 0; i < n; i++) {
        if(strcmp(emp[i].department, dept) == 0) {
            sum += emp[i].salary;
            count++;
        }
    }

    if(count == 0) {
        printf("No employees found\n");
        return;
    }

    printf("Total Salary: %.2f\n", sum);
    printf("Average Salary: %.2f\n", sum / count);
}

void giveAppraisal(struct Employee emp[], int n) {
    int percent;
    printf("Enter appraisal percentage (5-15): ");
    scanf("%d", &percent);

    if(percent < 5 || percent > 15) {
        printf("Invalid percentage\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        emp[i].salary += emp[i].salary * percent / 100.0;
    }

    printf("Appraisal applied\n");
}

void searchByDepartment(struct Employee emp[], int n) {
    char dept[20];
    printf("Enter department: ");
    scanf("%s", dept);

    for(int i = 0; i < n; i++) {
        if(strcmp(emp[i].department, dept) == 0) {
            printf("%d %s %s %.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
        }
    }
}

void searchByDesignation(struct Employee emp[], int n) {
    char des[20];
    printf("Enter designation: ");
    scanf("%s", des);

    for(int i = 0; i < n; i++) {
        if(strcmp(emp[i].designation, des) == 0) {
            printf("%d %s %s %.2f\n", emp[i].id, emp[i].name, emp[i].department, emp[i].salary);
        }
    }
}

void searchByExperience(struct Employee emp[], int n) {
    int exp;
    printf("Enter minimum years of experience: ");
    scanf("%d", &exp);

    for(int i = 0; i < n; i++) {
        if(emp[i].expYears >= exp) {
            printf("%d %s %d years\n", emp[i].id, emp[i].name, emp[i].expYears);
        }
    }
}

void promotionEligible(struct Employee emp[], int n) {
    for(int i = 0; i < n; i++) {
        if(emp[i].expYears > 3) {
            printf("%d %s (%s) Eligible for Promotion\n",
                   emp[i].id, emp[i].name, emp[i].designation);
        }
    }
}

int main() {
    struct Employee emp[5];
    int n = 5;

    for(int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i+1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Department: ");
        scanf("%s", emp[i].department);
        printf("Designation: ");
        scanf("%s", emp[i].designation);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        printf("Joining Date (dd mm yyyy): ");
        scanf("%d %d %d", &emp[i].joinDate.day, &emp[i].joinDate.month, &emp[i].joinDate.year);
        printf("Phone: ");
        scanf("%s", emp[i].phone);
        printf("Email: ");
        scanf("%s", emp[i].email);
    }

    computeExperience(emp, n);

    printf("\nEmployees with Promotion Eligibility:\n");
    promotionEligible(emp,n);

    printf("\nDepartment Salary Stats:\n");
    departmentStats(emp, n);

    printf("\nSearch By Department:\n");
    searchByDepartment(emp, n);

    printf("\nSearch By Designation:\n");
    searchByDesignation(emp, n);

    printf("\nSearch By Experience:\n");
    searchByExperience(emp, n);

    printf("\nApplying Appraisal:\n");
    giveAppraisal(emp, n);

    return 0;
}
