#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
    char *Name;
    int Age;
    char *Course;
    int Year;
    struct Student *next;
};

struct Student *head;
void InsertAtBeginning(char *name, int age, char *course, int year)
{
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    newNode->Name = strdup(name);
    newNode->Age = age;
    newNode->Course = strdup(course);
    newNode->Year = year;
    newNode->next = NULL;
    if (head != NULL)
    {
        newNode->next = head;
    }
    head = newNode;
}

void InsertAtEnd(char *name, int age, char *course, int year)
{
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    newNode->Name = strdup(name);
    newNode->Age = age;
    newNode->Course = strdup(course);
    newNode->Year = year;
    newNode->next = NULL;
    struct Student *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertAtPosition(char *name, int age, char *course, int year, int position)
{
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    newNode->Name = strdup(name);
    newNode->Age = age;
    newNode->Course = strdup(course);
    newNode->Year = year;
    newNode->next = NULL;
    int index = 1;
    struct Student *temp = head;
    //index - 1 so that 
    while (temp != NULL && index < position - 1)
    {
        temp = temp->next;
        index++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void Print()
{
    struct Student *temp = head;
    while (temp != NULL)
    {
        printf("Name: %s, Age: %d, Course: %s, Year: %d -> ", temp->Name, temp->Age, temp->Course, temp->Year);
        temp = temp->next;
    }
    printf("NULL\n");
}
// IT WILL NEVER ENOUGH

int main()
{
    InsertAtBeginning("jake", 20, "BSIT", 2);
    InsertAtBeginning("tonio", 20, "BSIT", 3);
    InsertAtEnd("zeke", 20, "BSIT", 2);
    InsertAtPosition("ezik", 20, "BSIT", 2, 2);
    Print();
    return 0;
}