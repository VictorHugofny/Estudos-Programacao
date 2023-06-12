/* Questão 5. Construa uma estrutura aluno com nome, numero de matrícula e curso. Leia do
usuário a informações de 5 alunos, armazene em um vetor dessa estrutura e imprima os dados
na tela. */

#include <stdio.h>
#include <string.h>

#define false 0
#define true 1

typedef struct Student {
  char name[50];
  int number;
  int registration;
} Student;

const int TAM = 2;

void setFullName(char *name) {
  fgets(name, 50, stdin);
}

void keyboardCleanBuffer(int *getChar) {
  while ((*getChar = getchar()) != '\n' && *getChar != EOF)
    ;
}

void input(Student *student, int index) {
  printf("Informe o nome do aluno %i: ", index);
  fgets(student->name, 50, stdin);
  printf("Informe o número do aluno %i: ", index);
  scanf("%d", &student->number);
  printf("Informe a matrícula do aluno %i: ", index);
  scanf("%d", &student->registration);
  printf("\n");
  int getChar;
  keyboardCleanBuffer(&getChar);
}

void output(Student *student, int index) {
  printf("\nEstudante %i\n", index);
  printf("Nome: %s", student->name);
  printf("Número: %d\n", student->number);
  printf("Matrícula: %d\n", student->registration);
}

int main() {
  Student student[5] = {};

  for (int i = 0; i < TAM; i++)
    input(&student[i], i + 1);

  for (int i = 0; i < TAM; i++)
    output(&student[i], i + 1);

  return false;
}
