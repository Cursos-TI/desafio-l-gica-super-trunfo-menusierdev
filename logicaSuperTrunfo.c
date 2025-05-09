#include <stdio.h>

int main() {
    // Variáveis da Carta 1
    char estado1[3];
    char codigo1[3];
    char cidade1[20];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;

    // Variáveis da Carta 2
    char estado2[3];
    char codigo2[3];
    char cidade2[20];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Entrada dos dados da carta 1
    printf("Carta 1:\n");
    printf("Digite a sigla do estado (ex: SP): ");
    scanf("%s", estado1);

    printf("Digite o código da carta (ex: 01): ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a população: ");
    scanf("%d", &populacao1);

    printf("Digite a área em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos1);

    // Entrada dos dados da carta 2
    printf("\nCarta 2:\n");
    printf("Digite a sigla do estado (ex: SP): ");
    scanf("%s", estado2);

    printf("Digite o código da carta (ex: 02): ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: ");
    scanf("%d", &populacao2);

    printf("Digite a área em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // Cálculo de Densidade Populacional e PIB per capita
    float densidade1 = populacao1 / area1;
    float pibpercapita1 = pib1 / populacao1;

    float densidade2 = populacao2 / area2;
    float pibpercapita2 = pib2 / populacao2;

    // Atributos para comparação
    int atributo1, atributo2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;

    printf("\n--- MENU DE COMPARAÇÃO ---\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Digite sua escolha: ");
    scanf("%d", &atributo1);

    // Menu Dinâmico: retira a opção escolhida
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Número de pontos turísticos\n"); break;
                case 5: printf("5 - Densidade Populacional\n"); break;
            }
        }
    }
    printf("Digite sua escolha: ");
    scanf("%d", &atributo2);

    // Pegando os valores do primeiro atributo
    switch (atributo1) {
        case 1:
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            break;
        case 2:
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;
        case 3:
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            break;
        case 4:
            valor1_carta1 = pontos1;
            valor1_carta2 = pontos2;
            break;
        case 5:
            valor1_carta1 = densidade1;
            valor1_carta2 = densidade2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Pegando os valores do segundo atributo
    switch (atributo2) {
        case 1:
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            break;
        case 2:
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            break;
        case 3:
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            break;
        case 4:
            valor2_carta1 = pontos1;
            valor2_carta2 = pontos2;
            break;
        case 5:
            valor2_carta1 = densidade1;
            valor2_carta2 = densidade2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Exibindo valores
    printf("\nComparação entre %s (%s) e %s (%s)\n", cidade1, estado1, cidade2, estado2);

    printf("\n--- Atributo 1 ---\n");
    printf("%s: %.2f\n", cidade1, valor1_carta1);
    printf("%s: %.2f\n", cidade2, valor1_carta2);

    printf("\n--- Atributo 2 ---\n");
    printf("%s: %.2f\n", cidade1, valor2_carta1);
    printf("%s: %.2f\n", cidade2, valor2_carta2);

    // Avaliando vitória para cada atributo (regra especial para densidade!)
    float ponto_carta1 = 0;
    float ponto_carta2 = 0;

    // Primeiro atributo
    if (atributo1 == 5) { // densidade -> menor vence
        valor1_carta1 < valor1_carta2 ? (ponto_carta1 += valor1_carta1) : (ponto_carta2 += valor1_carta2);
    } else { // outros -> maior vence
        valor1_carta1 > valor1_carta2 ? (ponto_carta1 += valor1_carta1) : (ponto_carta2 += valor1_carta2);
    }

    // Segundo atributo
    if (atributo2 == 5) { // densidade -> menor vence
        valor2_carta1 < valor2_carta2 ? (ponto_carta1 += valor2_carta1) : (ponto_carta2 += valor2_carta2);
    } else { // outros -> maior vence
        valor2_carta1 > valor2_carta2 ? (ponto_carta1 += valor2_carta1) : (ponto_carta2 += valor2_carta2);
    }

    // Mostrando soma
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", cidade1, ponto_carta1);
    printf("%s: %.2f\n", cidade2, ponto_carta2);

    // Resultado final
    printf("\n--- Resultado Final ---\n");
    if (ponto_carta1 > ponto_carta2) {
        printf("%s venceu!\n", cidade1);
    } else if (ponto_carta2 > ponto_carta1) {
        printf("%s venceu!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}