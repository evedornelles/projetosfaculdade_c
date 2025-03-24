#include <stdio.h>

typedef struct
{
       char estado[3];
       char codigo[10];
       char nome[50];
       int populacao;
       float area;
       float pib;
       int pontos_turisticos;
       float densidade_populacional;
       float pib_per_capita;
} Carta;

double calcular_densidade_populacional(int populacao, float area)
{
       return populacao / area;
}

double calcular_pib_per_capita(float pib, int populacao)
{
       return pib / populacao;
}

void comparar_cartas(Carta carta1, Carta carta2, char atributo[])
{
       printf("Comparação de cartas (Atributo: %s):\n", atributo);
       float valor1, valor2;

       if (strcmp(atributo, "Populacao") == 0)
       {
              valor1 = carta1.populacao;
              valor2 = carta2.populacao;
       }
       else if (strcmp(atributo, "Area") == 0)
       {
              valor1 = carta1.area;
              valor2 = carta2.area;
       }
       else if (strcmp(atributo, "PIB") == 0)
       {
              valor1 = carta1.pib;
              valor2 = carta2.pib;
       }
       else if (strcmp(atributo, "Densidade Populacional") == 0)
       {
              valor1 = carta1.densidade_populacional;
              valor2 = carta2.densidade_populacional;
       }
       else if (strcmp(atributo, "PIB per capita") == 0)
       {
              valor1 = carta1.pib_per_capita;
              valor2 = carta2.pib_per_capita;
       }
       else
       {
              printf("Atributo inválido!\n");
              return;
       }

       printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, valor1);
       printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, valor2);

       if ((strcmp(atributo, "Densidade Populacional") == 0 && valor1 < valor2) ||
           (strcmp(atributo, "Densidade Populacional") != 0 && valor1 > valor2))
       {
              printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
       }
       else if (valor1 == valor2)
       {
              printf("Resultado: Empate!\n");
       }
       else
       {
              printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
       }
}

int main()
{
       Carta carta1 = {"SP", "C01", "São Paulo", 12300000, 1521.11, 700000000000, 15};
       Carta carta2 = {"RJ", "C02", "Rio de Janeiro", 6000000, 1182.30, 360000000000, 10};

       carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
       carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);

       carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);
       carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

       comparar_cartas(carta1, carta2, "Populacao");

       return 0;
}
