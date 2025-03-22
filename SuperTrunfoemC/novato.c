#include <stdio.h>

int main()
{

       int populacao1, populacao2;
       float area1, area2, pib1, pib2;
       int pontosTuristicos1, pontosTuristicos2;

       printf("Digite os dados da primeira carta:\n");
       printf("Estado (A-H): ");
       scanf(" %c", &estado1);
       printf("Código: ");
       scanf(" %s", codigo1);
       printf("Nome da cidade: ");
       scanf(" %49s", nomeCidade1);
       printf("População: ");
       scanf(" %d", &populacao1);
       printf("Área (km²): ");
       scanf(" %f", &area1);
       printf("PIB: ");
       scanf(" %f", &pib1);
       printf("Pontos turísticos: ");
       scanf(" %d", &pontosTuristicos1);

       printf("\nDigite os dados da segunda carta:\n");
       printf("Estado (A-H): ");
       scanf(" %c", &estado2);
       printf("Código: ");
       scanf(" %s", codigo2);
       printf("Nome da cidade: ");
       scanf(" %49s", nomeCidade2);
       printf("População: ");
       scanf(" %d", &populacao2);
       printf("Área (km²): ");
       scanf(" %f", &area2);
       printf("PIB: ");
       scanf(" %f", &pib2);
       printf("Pontos turísticos: ");
       scanf(" %d", &pontosTuristicos2);

       printf("\nCarta 1:\n");
       printf("Estado: %c\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos turísticos: %d\n",
              estado1, codigo1, nomeCidade1, populacao1, area1, pib1, pontosTuristicos1);

       printf("\nCarta 2:\n");
       printf("Estado: %c\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos turísticos: %d\n",
              estado2, codigo2, nomeCidade2, populacao2, area2, pib2, pontosTuristicos2);

       return 0;
}
