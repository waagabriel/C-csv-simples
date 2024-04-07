/*
 *              waagabriel
 */
#include <stdio.h>
#include <string.h>
#define ERROR -1
int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "erro nenhum paramentro especificado!\n");
    return ERROR;
  }
  FILE *arquivo = fopen(argv[1], "r");
  char *linha = NULL;
  size_t tamanho = 0;
  ssize_t leitura = 0;
  if (arquivo == NULL) {
    fprintf(stderr, "arquivo nao existe");
    return ERROR;
  }
  printf("qual a linha que deseja ver?\t");
  int index = 0;
  if ((scanf("%i", &index)) != 1)
    return ERROR;
  int atual = 0;
  char *delim = ",";
  while ((leitura = getline(&linha, &tamanho, arquivo)) != -1) {
    if (atual == index) {
      linha = strtok(linha, delim);
      printf(">%s\n", linha);
      while (linha != NULL) {
        printf(">%s\n", linha);
        linha = strtok(NULL, delim);
      }
    }
    atual++;
  }
}
