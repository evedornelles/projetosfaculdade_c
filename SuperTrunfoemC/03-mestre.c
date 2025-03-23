#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct
{
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional e PIB per capita
void calcular_atributos(Carta *carta)
{
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + carta->pib_per_capita + (1 / carta->densidade_populacional);
}

// Função para ler os dados de uma carta
void ler_carta(Carta *carta, int numero)
{
    printf("\nDigite os dados da Carta %d:\n", numero);
    printf("Nome: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    printf("Populacao: ");
    scanf("%lu", &carta->populacao);
    printf("Area: ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
    calcular_atributos(carta);
}

// Função para comparar dois valores e imprimir o vencedor
void comparar_e_exibir(const char *atributo, float valor1, float valor2, int menor_vence)
{
    int resultado = (menor_vence ? (valor1 < valor2) : (valor1 > valor2)) ? 1 : 0;
    printf("%s: Carta %d venceu (%d)\n", atributo, resultado ? 1 : 2, resultado);
}

int main()
{
    Carta carta1, carta2;

    // Leitura das cartas
    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);

    // Exibição dos resultados da comparação
    printf("\nComparacao de Cartas:\n");
    comparar_e_exibir("Populacao", carta1.populacao, carta2.populacao, 0);
    comparar_e_exibir("Area", carta1.area, carta2.area, 0);
    comparar_e_exibir("PIB", carta1.pib, carta2.pib, 0);
    comparar_e_exibir("Pontos Turisticos", carta1.pontos_turisticos, carta2.pontos_turisticos, 0);
    comparar_e_exibir("Densidade Populacional", carta1.densidade_populacional, carta2.densidade_populacional, 1);
    comparar_e_exibir("PIB per Capita", carta1.pib_per_capita, carta2.pib_per_capita, 0);
    comparar_e_exibir("Super Poder", carta1.super_poder, carta2.super_poder, 0);

    return 0;
}
