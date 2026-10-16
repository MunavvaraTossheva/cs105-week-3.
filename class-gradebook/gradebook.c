#include <stdio.h>

typedef struct
{
    char name[50];
    int score;
} Student;

int main(void)
{
    Student students[10];
    int student_count;

    do
    {
        printf("Number of students: ");
        if (scanf("%d", &student_count) != 1)
        {
            return 1;
        }
    }
    while (student_count < 3 || student_count > 10);

    for (int i = 0; i < student_count; i++)
    {
        printf("Student %d name: ", i + 1);
        if (scanf("%49s", students[i].name) != 1)
        {
            return 1;
        }

        do
        {
            printf("%s's score: ", students[i].name);
            if (scanf("%d", &students[i].score) != 1)
            {
                return 1;
            }
        }
        while (students[i].score < 0 || students[i].score > 100);
    }

    int sum = 0;
    int top_index = 0;

    for (int i = 0; i < student_count; i++)
    {
        sum += students[i].score;

        if (students[i].score > students[top_index].score)
        {
            top_index = i;
        }
    }

    double average = (double) sum / student_count;
    Student top_student = students[top_index];

    for (int i = 0; i < student_count - 1; i++)
    {
        int max_index = i;

        for (int j = i + 1; j < student_count; j++)
        {
            if (students[j].score > students[max_index].score)
            {
                max_index = j;
            }
        }

        Student temp = students[i];
        students[i] = students[max_index];
        students[max_index] = temp;
    }

    
    printf("\nAverage: %.2f\n", average);
    printf("Top student: %s (%d)\n",
           top_student.name, top_student.score);

    printf("\nRanking:\n");

    for (int i = 0; i < student_count; i++)
    {
        printf("%d. %s - %d\n",
               i + 1, students[i].name, students[i].score);
    }

    return 0;
}