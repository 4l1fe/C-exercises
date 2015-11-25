#include <stdio.h>
#include <stdbool.h>

#define STRLEN 5

int readln(char s[], int maxlen) {
  char ch;
  int i=0;
  bool chars_remain = true;

  while (chars_remain) {
    ch = getchar();
    if ((ch == '\n') || (ch == EOF)) {
      chars_remain = false;
    }
    else if (i < maxlen -1) {
      s[i] = ch;
      i++;
    }
  }
  s[i] = '\0';
  return i;
}


int main(int argc, char *argv[]) {
  char firstname[STRLEN];
  char lastname[STRLEN];
  int len_firstname;
  int len_lastname;

  printf("Firstname: ");
  len_firstname = readln(firstname, STRLEN);
  printf("Lastname: ");
  len_lastname = readln(lastname, STRLEN);
  printf("%s %s\n", firstname, lastname);
  printf("f len = %d, l len = %d\n", len_firstname, len_lastname);
  return 0;
}
