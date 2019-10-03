#include <stdio.h>
#include <string.h>

#define LEN 10

typedef struct {
  char name[LEN];
  int days;
} month_t;

void swap_integers(int *i1, int *i2) {
  int temp = *i1;
  *i1 = *i2;
  *i2 = temp;
}

void swap_strings(char s1[], char s2[]) {
  char temp[LEN];
  strcpy(temp, s1);
  strcpy(s1, s2);
  strcpy(s2, temp);
}

void swap(month_t months[], int i1, int i2) {
  swap_strings(months[i1].name, months[i2].name);
  swap_integers(&months[i1].days, &months[i2].days);
}

int get_min_index(month_t months[], int start, int size) {
  month_t temp;
  strcpy(temp.name, months[start].name);
  temp.days = months[start].days;

  int min_index = start;

  int i = start + 1;

  while (i < size) {
    if (strcmp(months[i].name, temp.name) < 0) {
      strcpy(temp.name, months[i].name);
      temp.days = months[i].days;
      min_index = i;
    }
    i++;
  }
  
  return min_index;
}

void selection_sort(month_t months[], int size) {
  for (int i=0; i<size; i++) {
    int min_index = get_min_index(months, i, size);
    if (min_index != i) {
      swap(months, min_index, i);
    }
  }
}

month_t create_exam_month() {
  char entered_name[LEN];
  int entered_days;

  printf("Please enter the name ,less than 10 chars, and how manys days you want for the exam month: ");
  scanf("%s %d", entered_name, &entered_days);
  month_t res;

  strcpy(res.name, entered_name);
  res.days = entered_days;

  return res;
}

int
main(void)
{
  /*
  month_t jan = {"January", 31};
  month_t feb = {"Feburary", 28};

  swap(&jan, &feb);

  printf("jan has name %s and %d days.\n", jan.name, jan.days);
  printf("feb has name %s and %d days.\n", feb.name, feb.days);

  month_t exam_month = create_exam_month();

  printf("Exam month named %s and has %d days.\n", exam_month.name, exam_month.days);
  */

	char names[12][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  month_t months[13];

  for (int i=0; i<12; i++) {
    strcpy(months[i].name, names[i]);
    months[i].days = days[i];
  }

  month_t exam_month = create_exam_month();

  printf("Exam month named %s and has %d days.\n", exam_month.name, exam_month.days);

  months[12] = exam_month;

  for (int i=0; i<13; i++) {
    printf("%s has %d days.\n", months[i].name, months[i].days);
  }

  selection_sort(months, 13);
  printf("After sorting\n");

  for (int i=0; i<13; i++) {
    printf("%s has %d days.\n", months[i].name, months[i].days);
  }

    int extra_days = exam_month.days;
    int each = extra_days / 12;
    int rem = extra_days % 12;
  for(int i = 0; i < 12; i++)
  {
    if(strcmp(months[i].name, exam_month.name) != 0)
    {
        months[i].days -= each;
    }
  }

  return (0);
}
