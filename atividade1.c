#include <stdio.h>

int main() {
    double salary;
    printf("=====================================\n");
    printf(" Empresa: Prime Solutions\n");
    printf(" Nome: Jeff Matheus Santos Pereira\n");
    printf(" RA: 20152829-5\n");
    printf("=====================================\n");
    printf(" Digite seu ultimo salario liquido: R$");
    scanf("%lf", &salary);
    printf("=====================================\n");
    printf(" Salario informado: R$%.2f\n", salary);
    salary += (7.5/100)*salary;
    if (salary <= 1750) {
        printf(" O provavel valor do salario a receber é: R$%.2f\n", salary + 150);
        printf("=====================================\n");
    } else {
        printf(" O provavel valor do salario a receber é: R$%.2f\n", salary);
        printf("=====================================\n");    
    }
    return 0;
}

