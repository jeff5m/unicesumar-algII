#include <stdio.h>
#include <string.h>

enum PROJECT_STATUS
{
  toDo = 1,
  doing = 2,
  done = 3
};

struct project
{
  int id;
  char title[30], description[100], manager[30];
  int year;
  enum PROJECT_STATUS status;
  double budget;
  int daysToFinish;
  int people;
};

void printMenu()
{
  printf("=======================================\n");
  printf(" 1 - Inserir novo projeto\n");
  printf(" 2 - Listar todos os projetos\n");
  printf(" 3 - Listar todos os projetos: a fazer\n");
  printf(" 4 - Listar todos os projetos: fazendo\n");
  printf(" 5 - Listar todos os projetos feitos\n");
  printf(" 0 - Sair\n");
  printf("=======================================\n");
}

// void listProjectsToDo()
// {
//   printf("listando projetos a fazer\n");
//   printMenu();
// }

// void listProjectsOnGoing()
// {
//   printf("listando projetos fazendo\n");
//   printMenu();
// }

// void listProjectsDone()
// {
//   printf("listando projetos concluídos\n");
//   printMenu();
// }

int main()
{
  int menu, idCount = 1;
  struct project projects[200];

  printf(" Selecione uma das opções abaixo:\n");
  printMenu();

  while (scanf("%d", &menu) && menu)
  {
    switch (menu)
    {
    case 1:
      if (idCount > 200)
      {
        printf("Número máximo de cadastros atingido!");
        continue;
      }

      int enumStatus;
      printf("\nCadastro de Projeto\n");
      printf("Código: %d", idCount);
      projects[idCount - 1].id = idCount;
      printf("\nTítulo: ");
      scanf("%s", projects[idCount - 1].title);
      printf("Descrição: ");
      scanf("%s", projects[idCount - 1].description);
      printf("Ano: ");
      scanf("%d", &projects[idCount - 1].year);
      printf("Status(1 (A Fazer), 2 (Fazendo) ou 3 (Concluído): ");
      scanf("%d", &enumStatus);
      projects[idCount - 1].status = enumStatus;
      printf("Gerente: ");
      scanf("%s", projects[idCount - 1].manager);
      printf("Orçamento: ");
      scanf("%lf", &projects[idCount - 1].budget);
      printf("Estimativa para Conclusão em dias: ");
      scanf("%d", &projects[idCount - 1].daysToFinish);
      printf("Quantidade de Pessoas: ");
      scanf("%d", &projects[idCount - 1].people);
      printf("\nProjeto cadastrado com sucesso!\n\n");
      idCount++;
      printMenu();
      break;

    case 2:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].id == 0)
        {
          printf("\nNão existem projetos cadastrados\n\n");
          printMenu();
          continue;
        }
        printf("Projeto: %d\n", projects[i].id);
        printf("Título: %s\n", projects[i].title);
        printf("Descrição: %s\n", projects[i].description);
        printf("Ano: %d\n", projects[i].year);
        printf("Status(1 (A Fazer), 2 (Fazendo) ou 3 (Concluído): %d\n", projects[i].status);
        printf("Gerente: %s\n", projects[i].manager);
        printf("Orçamento: %.2lf\n", projects[i].budget);
        printf("Estimativa para Conclusão em dias: %d\n", projects[i].daysToFinish);
        printf("Quantidade de Pessoas: %d\n", projects[i].people);
      }
      break;

    case 3:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].status != 1)
        {
          printf("\nNão existem projetos a fazer\n\n");
          printMenu();
          continue;
        }
        printf("Projeto: %d\n", projects[i].id);
        printf("Título: %s\n", projects[i].title);
        printf("Descrição: %s\n", projects[i].description);
        printf("Ano: %d\n", projects[i].year);
        printf("Status(1 (A Fazer), 2 (Fazendo) ou 3 (Concluído): %d\n", projects[i].status);
        printf("Gerente: %s\n", projects[i].manager);
        printf("Orçamento: %.2lf\n", projects[i].budget);
        printf("Estimativa para Conclusão em dias: %d\n", projects[i].daysToFinish);
        printf("Quantidade de Pessoas: %d\n", projects[i].people);
      }
      break;

    case 4:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].status != 2)
        {
          printf("\nNão existem projetos em andamento\n\n");
          printMenu();
          continue;
        }
        printf("Projeto: %d\n", projects[i].id);
        printf("Título: %s\n", projects[i].title);
        printf("Descrição: %s\n", projects[i].description);
        printf("Ano: %d\n", projects[i].year);
        printf("Status(1 (A Fazer), 2 (Fazendo) ou 3 (Concluído): %d\n", projects[i].status);
        printf("Gerente: %s\n", projects[i].manager);
        printf("Orçamento: %.2lf\n", projects[i].budget);
        printf("Estimativa para Conclusão em dias: %d\n", projects[i].daysToFinish);
        printf("Quantidade de Pessoas: %d\n", projects[i].people);
      }
      break;

    case 5:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].status != 3)
        {
          printf("\nNão existem projetos concluídos\n\n");
          printMenu();
          continue;
        }
        printf("Projeto: %d\n", projects[i].id);
        printf("Título: %s\n", projects[i].title);
        printf("Descrição: %s\n", projects[i].description);
        printf("Ano: %d\n", projects[i].year);
        printf("Status(1 (A Fazer), 2 (Fazendo) ou 3 (Concluído): %d\n", projects[i].status);
        printf("Gerente: %s\n", projects[i].manager);
        printf("Orçamento: %.2lf\n", projects[i].budget);
        printf("Estimativa para Conclusão em dias: %d\n", projects[i].daysToFinish);
        printf("Quantidade de Pessoas: %d\n", projects[i].people);
      }
      break;

    default:
      printf("\nOpção inválida. Digite novamente.\n\n");
      printMenu();
      break;
    }
  }
  return 0;
}
