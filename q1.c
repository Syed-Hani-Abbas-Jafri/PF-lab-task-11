#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int roll;
    float marks[3];
    float percentage;
    char grade[3];
};

float inputMarks() {
    float m;
    do {
        scanf("%f", &m);
        if (m < 0 || m > 100)
            printf("Invalid! Enter marks (0-100): ");
    } while (m < 0 || m > 100);
    return m;
}

void calculateGrade(struct Student *s) {
    if ((*s).percentage >= 90) strcpy((*s).grade, "A+");
    else if ((*s).percentage >= 80) strcpy((*s).grade, "A");
    else if ((*s).percentage >= 70) strcpy((*s).grade, "B+");
    else if ((*s).percentage >= 60) strcpy((*s).grade, "B");
    else if ((*s).percentage >= 50) strcpy((*s).grade, "C");
    else strcpy((*s).grade, "F");
}

void sortByPercentage(struct Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].percentage < s[j+1].percentage) {
                struct Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main() {

    struct Student s[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float total = 0;
        printf("\nStudent %d\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Roll: ");
        scanf("%d", &s[i].roll);

        for (int j = 0; j < 3; j++) {
            printf("Marks %d (0-100): ", j+1);
            s[i].marks[j] = inputMarks();
            total += s[i].marks[j];
        }

        s[i].percentage = total / 3;
        calculateGrade(&s[i]);
    }

    float classAvg = 0;
    for (int i = 0; i < n; i++)
        classAvg += s[i].percentage;
    classAvg /= n;

    printf("\n\nAll Students:\n");
    for (int i = 0; i < n; i++) {
        printf("%s  Roll:%d  %.2f%%  Grade:%s\n",
               s[i].name, s[i].roll, s[i].percentage, s[i].grade);
    }

    printf("\nClass Average: %.2f%%\n", classAvg);

    printf("\nAbove Average:\n");
    for (int i = 0; i < n; i++)
        if (s[i].percentage > classAvg)
            printf("%s (%.2f)\n", s[i].name, s[i].percentage);

    printf("\nBelow Average:\n");
    for (int i = 0; i < n; i++)
        if (s[i].percentage < classAvg)
            printf("%s (%.2f)\n", s[i].name, s[i].percentage);

    printf("\nStudents by Grade:\n");
    char grades[][3] = {"A+","A","B+","B","C","F"};
    for (int g = 0; g < 6; g++) {
        printf("\nGrade %s:\n", grades[g]);
        for (int i = 0; i < n; i++) {
            if (strcmp(s[i].grade, grades[g]) == 0)
                printf("%s (%.2f)\n", s[i].name, s[i].percentage);
        }
    }

    struct Student temp[MAX];
    for (int i = 0; i < n; i++) temp[i] = s[i];
    sortByPercentage(temp, n);

    printf("\nRanking:\n");
    for (int i = 0; i < n; i++)
        printf("Rank %d: %s (%.2f)\n", i+1, temp[i].name, temp[i].percentage);

    return 0;
}
