#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
  char pathShell[50] = "./compile_and_run.sh ";
  const char *path;
  int option;

  do {
    printf("Escolha uma das seguintes opções:\n");
    printf("\n1) Pilha");
    printf("\n2) Fila");
    printf("\n3) Lista\n");
    printf("\n0) Sair\n");
    printf("\nDigite: ");
    scanf("%i", &option);

    switch (option) {
      case 1:
        path = "stack";
        break;
      case 2:
        path = "queue";
        break;
      case 3:
        path = "list";
        break;
      case 0:
        break;
      default:
        system("clear");
        menu();
        break;
    }
    system(strcat(pathShell, path));
    exit(1);
  } while (option != 0);
}

int main() {
  menu();
  return false;
}
