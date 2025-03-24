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

void comparar_cartas(Carta carta1, Carta carta2, int atributo) {
    float valor1, valor2;
    char atributo_nome[50];
    int menor_vence = 0;

    switch (atributo) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            sprintf(atributo_nome, "População");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            sprintf(atributo_nome, "Área");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            sprintf(atributo_nome, "PIB");
            break;
        case 4:
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            sprintf(atributo_nome, "Pontos Turísticos");
            break;
        case 5:
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            sprintf(atributo_nome, "Densidade Populacional");
            menor_vence = 1;
            break;
        case 6:
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            sprintf(atributo_nome, "PIB per Capita");
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("\nComparação de cartas (Atributo: %s):\n", atributo_nome);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, valor2);

    if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else if ((valor1 > valor2 && !menor_vence) || (valor1 < valor2 && menor_vence)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    }
}

int main() {
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.27, 415.92, 40};

    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    comparar_cartas(carta1, carta2, opcao);

    return 0;
}
