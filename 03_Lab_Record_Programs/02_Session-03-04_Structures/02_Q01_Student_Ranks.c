// Session-3 (3 hours) and Session-4 (3 hours): Structures

// Q1. Write a program in ‘C’ language, which accepts Enrolment number, Name
// Aggregate marks secured in a Program by a student. Assign ranks to students
// according to the marks secured. Rank-1 should be awarded to the students who
// secured the highest marks and so on. The program should print the enrolment
// number, name of the student and the rank secured in ascending order.

#include <stdio.h>
#include <string.h>

struct Student
{
    char enrolment[20];
    char name[50];
    float marks;
    int rank;
};

int main()
{
    int n, i, j;
    struct Student s[50], temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Accept student details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enrolment Number: ");
        scanf("%s", s[i].enrolment);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Aggregate Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Sort students by marks in descending order (highest marks first)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s[j].marks < s[j + 1].marks)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Assign ranks based on sorted order
    for (i = 0; i < n; i++)
    {
        s[i].rank = i + 1;
    }

    // Display the student ranking list
    printf("\n--- Student Ranks (Ascending Order of Ranks) ---\n");
    printf("Rank\tEnrolment No\tName\t\tMarks\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%s\t\t%.2f\n", s[i].rank, s[i].enrolment, s[i].name, s[i].marks);
    }

    return 0;
}