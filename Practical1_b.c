#include <stdio.h>
#include <stdlib.h>
struct student
{
  int roll_no;
  char *name;
  int marks[2];
};
void display(struct student *s, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("Student %d\n", (i + 1));
    printf("Name:%s\n", (s + i)->name);
    printf("Roll No:%d\n", (s + i)->roll_no);
    for (int j = 0; j < 2; j++)
    {
      printf("Subject %d marks:%d\n", (j + 1), (s + i)->marks[j]);
    }
    printf("\n");
  }
}
void insertion(struct student *s, int N, int choice)
{
  printf("Enter details for Student\n");
  int i, j;
  if (choice == 1)
  {
    for (i = 0; i < N; i++)
    {
      printf("Student %d\n", (i + 1));
      printf("Enter student name:");
      (s + i)->name = (char *)malloc(100 * sizeof(char));
      fflush(stdin);
      gets((s + i)->name);
      printf("Enter roll no:");
      scanf("%d", &(s + i)->roll_no);
      for (j = 0; j < 2; j++)
      {
        printf("Enter subject %d marks:", j + 1);
        scanf("%d", &(s + i)->marks[j]);
      }
    }
  }
  if (choice == 2)
  {
    for (i = 0; i < N - 1; i++)
    {
    }
    printf("Student %d\n", (N));
    printf("Enter student name:");
    (s + i)->name = (char *)malloc(100 * sizeof(char));
    fflush(stdin);
    gets((s + i)->name);
    printf("Enter roll no:");
    scanf("%d", &(s + i)->roll_no);
    for (j = 0; j < 2; j++)
    {
      printf("Enter Subject %d marks:", (j + 1));
      scanf("%d", &(s + i)->marks[j]);
    }
  }
}
void updation(struct student *s, int N)
{
  int stu_roll, i, subno, check = 0, choice1 = 0;
  printf("Enter student roll no:");
  scanf("%d", &stu_roll);
  for (i = 0; i < N; i++)
  {
    if ((s + i)->roll_no == stu_roll)
    {
      check = 1;
      printf("Enter 1 to update name\nEnter 2 to update roll no\nEnter 3 to update subject marks");
      scanf("%d", &choice1);
      while (choice1 != 4)
      {
        if (choice1 == 1)
        {
          printf("Enter new name:");
          fflush(stdin);
          gets((s + i)->name);
        }
        else if (choice1 == 2)
        {
          printf("Enter new roll no:");
          scanf("%d", &(s + i)->roll_no);
        }
        else if (choice1 == 3)
        {
          printf("Enter subject number whose marks are to be updated:");
          scanf("%d", &subno);
          printf("Enter new marks:");
          scanf("%d", &(s + i)->marks[subno - 1]);
        }
        printf("Enter 1 to update name\nEnter 2 to update roll no\nEnter 3 to update subject marks\nEnter 4 to quit.");
        scanf("%d", &choice1);
      }
    }
  }
  if (check == 0)
  {
    printf("Roll no not found!");
  }
}
int main()
{
  int N, i, choice1 = 0;
  printf("Enter the number of students :");
  scanf("%d", &N);
  struct student *s;
  s = (struct student *)malloc(sizeof(struct student) * N);
  insertion(s, N, 1);
  while (choice1 != 4)
  {
    printf("Enter 1 to insert student information\nEnter 2 to update student information\nEnter 3 to display student information\nEnter 4 to quit.");
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
      N++;
      s = (struct student *)realloc(s, N * sizeof(struct student));
      insertion(s, N, 2);
    }
    else if (choice1 == 2)
    {
      updation(s, N);
    }
    else if (choice1 == 3)
    {
      display(s, N);
    }
  }
}