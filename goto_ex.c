#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 80

int cursor = -1;
char input[INPUT_LENGTH];

int main(void)
{
  printf("Input: ");
  fgets(input, INPUT_LENGTH, stdin);
  goto e0;

aceita:
  printf("Input aceito\n");
  exit(EXIT_SUCCESS);

rejeita:
  printf("Input rejeitado\n");
  exit(EXIT_FAILURE);

e0:
  cursor++;
  if (input[cursor] == 'a') {
    goto e1;
  } else {
    goto rejeita;
  }

e1:
  cursor++;
  if (input[cursor] == 'b') {
    goto e0;
  } else if (input[cursor] == 'c') {
    goto e2;
  } else if (input[cursor] == '\n') {
    goto aceita;
  } else {
    goto rejeita;
  }

e2:
  cursor++;
  if (input[cursor] == '\n') {
    goto aceita;
  } else {
    goto rejeita;
  }
}

