#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

float obter_valor(Carta carta, int atributo, char *atributo_nome, int *menor_vence) {
    *menor_vence = 0;
    switch (atributo) {
        case 1: sprintf(atributo_nome, "População"); return carta.populacao;
        case 2: sprintf(atributo_nome, "Área"); return carta.area;
        case 3: sprintf(atributo_nome, "PIB"); return carta.pib;
        case 4: sprintf(atributo_nome, "Pontos Turísticos"); return carta.pontos_turisticos;
        case 5: sprintf(atributo_nome, "Densidade Populacional"); *menor_vence = 1; return carta.densidade_populacional;
        case 6: sprintf(atributo_nome, "PIB per Capita"); return carta.pib_per_capita;
        default: return -1;
    }
}

void comparar_cartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float valor1_1, valor1_2, valor2_1, valor2_2, soma1, soma2;
    char atributo_nome1[50], atributo_nome2[50];
    int menor_vence1, menor_vence2;

    valor1_1 = obter_valor(carta1, atributo1, atributo_nome1, &menor_vence1);
    valor1_2 = obter_valor(carta1, atributo2, atributo_nome2, &menor_vence2);
    valor2_1 = obter_valor(carta2, atributo1, atributo_nome1, &menor_vence1);
    valor2_2 = obter_valor(carta2, atributo2, atributo_nome2, &menor_vence2);

    printf("\nComparação de cartas:\n");
    printf("Atributo 1: %s\n", atributo_nome1);
    printf("  - Carta 1 (%s - %s): %.2f\n", carta1.nome, carta1.estado, valor1_1);
    printf("  - Carta 2 (%s - %s): %.2f\n", carta2.nome, carta2.estado, valor2_1);

    printf("Atributo 2: %s\n", atributo_nome2);
    printf("  - Carta 1 (%s - %s): %.2f\n", carta1.nome, carta1.estado, valor1_2);
    printf("  - Carta 2 (%s - %s): %.2f\n", carta2.nome, carta2.estado, valor2_2);

    soma1 = valor1_1 + valor1_2;
    soma2 = valor2_1 + valor2_2;

    printf("\nSoma dos atributos:\n");
    printf("  - Carta 1: %.2f\n", soma1);
    printf("  - Carta 2: %.2f\n", soma2);

    printf("\nResultado: ");
    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("Vencedor: %s\n", (soma1 > soma2) ? carta1.nome : carta2.nome);
    }
}

int main() {
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.27, 415.92, 40};

    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    int opcao1, opcao2;
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao1);

    do {
        printf("Escolha o segundo atributo para comparar (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao2);
    } while (opcao1 == opcao2);

    comparar_cartas(carta1, carta2, opcao1, opcao2);
    return 0;
}
