#include <stdio.h>
typedef struct
{
    int id;
    char name[50];
    char major[50];
} Student;
int main(void)
{
    Student students[] = {
        {101, "Amina", "Computer Science"},
        {102, "Farid", "Mathematics"},
        {103, "Madina", "Economics"},
        {104, "Rustam", "Design"},
        {105, "Zebo", "Computer Science"}
    };
    int count = sizeof(students) / sizeof(students[0]);
    int id;
    int found = 0;
    printf("Student ID: ");
    if (scanf("%d", &id) != 1)
    {
        return 1;
    }
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Name: %s\n", students[i].name);
            printf("Major: %s\n", students[i].major);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Student not found.\n");
    }
    return 0;
}