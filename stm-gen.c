#include <stdio.h>
#include <string.h>

#define SYM_LIST_LENGTH 80
#define FST_LIST_LENGTH 20
#define MAX_OF_STATES 80

typedef struct {
  int amount;
  int list[FST_LIST_LENGTH];
} FinalSt;

typedef struct {
  int amount;
  char list[SYM_LIST_LENGTH];
} Sym;

typedef int (*TrTablePointer)[SYM_LIST_LENGTH];
typedef int (TrTable)[MAX_OF_STATES][SYM_LIST_LENGTH];

int get_opt(void);
void get_sym(Sym *);
void get_fst(FinalSt *);
void get_st_amount(int *);
void get_initial_st(int *);
void get_transition_table(TrTablePointer, Sym *, int);
void get_program_name(char *);
void debug_info(Sym *, int, FinalSt *, int, TrTablePointer, char *);
//void gen_fn();

int main(void) {
  Sym sym;
  FinalSt finalSt;
  int st_amount;
  int initial_st;
  TrTable trTable;
  char c;
  char program_name[80];

  while((c = get_opt()) != 'q') {
    switch(c) {
    case '0':
      get_sym(&sym);
      break;
    case '1':
      get_st_amount(&st_amount);
      break;
    case '2':
      get_fst(&finalSt);
      break;
    case '3':
      get_initial_st(&initial_st);
      break;
    case '4':
      get_transition_table(trTable, &sym, st_amount);
      break;
    case '5':
      get_program_name(program_name);
      break;
    case '6':
      //gen_fn();
      break;
    case '7':
      //gen_goto();
      break;
    case '8':
      debug_info(&sym, st_amount, &finalSt, initial_st, trTable, program_name);
      break;
    }
  }
  
  return 0;
}

int get_opt(void)
{
  int ret;
  for (int i = 0; i < 40; i++) printf("*");
  printf("\n");
  printf("0 ..... Entrar com conjunto de símbolos.\n");
  printf("1 ..... Entrar com número de estados.\n");
  printf("2 ..... Entrar com conjunto de estados finais.\n");
  printf("3 ..... Entrar com estado inicial.\n");
  printf("4 ..... Entrar com a tabela de transições.\n");
  printf("5 ..... Entrar com nome do programa.\n");
  printf("6 ..... Gerar programa por função.\n");
  printf("7 ..... Gerar programa por goto.\n");
  printf("8 ..... Exibir configurações.\n");
  printf("q ..... Sair.\n");
  for (int i = 0; i < 40; i++) printf("*");
  printf("\n");
  printf("O que deseja fazer? ");
  ret = getchar();
  while (getchar() != '\n')
    continue;
  printf("\n");
  return ret;
}

void get_sym(Sym *sym)
{
  printf("Quantos símbolos? ");
  scanf("%d", &sym->amount);
  getchar();

  for (int i = 0; i < sym->amount; i++) {
    printf("Qual o símbolo %d? ", i);
    scanf("%c", &sym->list[i]);
    while (getchar() != '\n')
      continue;
  }
  printf("\n");
}

void get_st_amount(int *st_amount)
{
  printf("Quantos estados? ");
  scanf("%d", st_amount);
  while (getchar() != '\n')
    continue;
  printf("\n");
}

void get_fst(FinalSt *fst)
{
  printf("Quantos estados finais? ");
  scanf("%d", &fst->amount);

  for (int i = 0; i < fst->amount; i++) {
    printf("Qual o estado final %d? ", i);
    scanf("%d", &fst->list[i]);
    while (getchar() != '\n')
      continue;
  }
  printf("\n");
}

void get_initial_st(int *ist)
{
  printf("Qual o estado inicial? ");
  scanf("%d", ist);
  while (getchar() != '\n')
    continue;
  printf("\n");
}

void get_transition_table(TrTablePointer trTable, Sym *sym, int st_amount)
{
  for (int i = 0; i < st_amount; i++) {
    for (int j = 0; j < sym->amount; j++) {
      printf("Para o estado e%d e símbolo '%c', qual o próximo estado? ", i, sym->list[j]);
      scanf("%d", &trTable[i][j]);
      while(getchar() != '\n')
        continue;
    }
  }
  printf("\n");
}

void get_program_name(char *name)
{
  printf("Qual o nome do programa? ");
  scanf("%s", name);
  while(getchar() != '\n')
    continue;
  printf("\n");
}

void debug_info(Sym *sym, int st_amount, FinalSt *finalSt, int initial_st, TrTablePointer trTable, char *name)
{
  printf("Quantidade de símbolos: %d\n", sym->amount);
  for (int i = 0; i < sym->amount; i++) {
    printf("Símbolo %d: '%c'\n", i, sym->list[i]);
  }
  printf("\n");

  printf("Quantidade de estados: %d\n\n", st_amount);

  printf("Quantidade de estados finais: %d\n", finalSt->amount);
  for (int i = 0; i < finalSt->amount; i++) {
    printf("Estado final %d: e%d\n", i, finalSt->list[i]);
  }
  printf("\n");

  printf("Estado inicial: e%d\n\n", initial_st);

  printf("Tabela de transições:\n");
  for (int i = 0; i < st_amount; i++) {
    for (int j = 0; j < sym->amount; j++) {
      int next_st = trTable[i][j];
      printf("Estado e%d e símbolo '%c', próximo estado: ", i, sym->list[j]);
      if (next_st >= 0) {
        printf("e%d\n", next_st);
      } else {
        printf("-\n");
      }
    }
  }
  printf("\n");

  printf("Nome do programa: %s\n\n", name);
}

