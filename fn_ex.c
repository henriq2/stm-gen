#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 80

void aceita(void);
void rejeita(void);
void e0(void);
void e1(void);
void e2(void);

int cursor = -1;
char input[INPUT_LENGTH];

int main(void)
{
  printf("Input: ");
  fgets(input, INPUT_LENGTH, stdin);
  e0();
}

void aceita()
{
  printf("Input aceito\n");
  exit(EXIT_SUCCESS);
}

void rejeita()
{
  printf("Input rejeitado\n");
  exit(EXIT_FAILURE);
}

void e0()
{
  cursor++;
  if (input[cursor] == 'a') {
    e1();
  } else {
    rejeita();
  }
}

void e1()
{
  cursor++;
  if (input[cursor] == 'b') {
    e0();
  } else if (input[cursor] == 'c') {
    e2();
  } else if (input[cursor] == '\n') {
    aceita();
  } else {
    rejeita();
  }
}

void e2()
{
  cursor++;
  if (input[cursor] == '\n') {
    aceita();
  } else {
    rejeita();
  }
}

