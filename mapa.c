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

int menu, idCount = 1;
struct project projects[200];

void printMenu()
{
  printf("===============================================================\n");
  printf(" 1 - Inserir novo projeto\n");
  printf(" 2 - Listar todos os projetos\n");
  printf(" 3 - Listar todos os projetos: a fazer\n");
  printf(" 4 - Listar todos os projetos: fazendo\n");
  printf(" 5 - Listar todos os projetos feitos\n");
  printf(" 6 - Listar todos os projetos por limite de orçamento\n");
  printf(" 0 - Sair\n");
  printf("===============================================================\n\n");
}

int createProject()
{
  int enumStatus;
  printf("\nCadastro de Projeto\n");
  printf("Código: %d", idCount);
  projects[idCount - 1].id = idCount++;
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
  return 1;
}

void listProjects(struct project p)
{
  printf(" Projeto: %d\n", p.id);
  printf(" Título: %s\n", p.title);
  printf(" Descrição: %s\n", p.description);
  printf(" Ano: %d\n", p.year);
  printf(" Status(1 (A Fazer), 2 (Fazendo) ou 3 (Concluído): %d\n", p.status);
  printf(" Gerente: %s\n", p.manager);
  printf(" Orçamento: %.2lf\n", p.budget);
  printf(" Estimativa para Conclusão em dias: %d\n", p.daysToFinish);
  printf(" Quantidade de Pessoas: %d\n\n", p.people);
}

int main()
{
  printf(" Selecione uma das opções abaixo:\n");
  printMenu();

  while (scanf("%d", &menu) && menu)
  {
    switch (menu)
    {
    case 1:
      if (idCount >= 200)
      {
        printf("\n Número máximo de %d cadastros atingido!\n\n", idCount);
        printMenu();
        continue;
      }

      int wasCreated = createProject();

      if (wasCreated)
      {
        printf("\n Projeto cadastrado com sucesso!\n\n");
      }
      else
      {
        printf("\n Houve um erro no cadastro!\n\n");
      }

      printMenu();
      break;

    case 2:
      if (idCount == 1)
      {
        printf("\n Ainda não existem projetos cadastrados\n\n");
        printMenu();
        break;
      }
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].id == 0)
        {
          printf("\n");
          continue;
        }

        listProjects(projects[i]);
      }

      printMenu();
      break;

    case 3:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].status != 1 && idCount == 1)
        {
          printf("\n Não existem projetos a fazer\n\n");
          break;
        }

        if (projects[i].status != 1)
        {
          printf("\n");
          continue;
        }

        listProjects(projects[i]);
      }

      printMenu();
      break;

    case 4:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].status != 2 && idCount == 1)
        {
          printf("\n Não existem projetos em execução\n\n");
          break;
        }

        if (projects[i].status != 2)
        {
          printf("\n");
          continue;
        }

        listProjects(projects[i]);
      }

      printMenu();
      break;

    case 5:
      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].status != 3 && idCount == 1)
        {
          printf("\n Não existem projetos concluídos\n\n");
          break;
        }

        if (projects[i].status != 3)
        {
          printf("\n");
          continue;
        }

        listProjects(projects[i]);
      }
      printMenu();
      break;

    case 6:
      goto Cleanup;
    Cleanup:;
      double limitBudget;
      printf("Digite o orçamento limite para listar os projetos: ");
      scanf("%lf", &limitBudget);

      for (int i = 0; i < idCount; i++)
      {
        if (projects[i].budget < limitBudget && idCount == 1)
        {
          printf("\n Não existem projetos cadastrados\n\n");
          break;
        }

        if (projects[i].budget < limitBudget)
        {
          printf("\n");
          continue;
        }

        listProjects(projects[i]);
      }
      printMenu();
      break;

    default:
      printf("\n Opção inválida. Digite novamente.\n\n");
      printMenu();
      break;
    }
  }
  return 0;
}
