#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    float populacao; // em milhões
    float area;      // em km²
    float pib;       // em bilhões
    int pturisticos;
    float densidade;
    float super_poder;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("Digite o código do estado: ");
    scanf("%s", carta->estado);

    printf("Digite o código da cidade: ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome); // permite espaços

    printf("Digite a População da cidade (em milhões): ");
    scanf("%f", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pturisticos);

    // Cálculo da densidade e do super poder
    carta->densidade = (carta->populacao * 1000000) / carta->area;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pturisticos;
}

void exibirCarta(Carta carta) {
    printf("\n--- Carta: %s (%s) ---\n", carta.nome, carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("População: %.2f milhões\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pturisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\n===== COMPARAÇÃO =====\n");

    printf("\nPopulação: %s vence\n", c1.populacao > c2.populacao ? c1.nome : c2.nome);
    printf("Área: %s vence\n", c1.area > c2.area ? c1.nome : c2.nome);
    printf("PIB: %s vence\n", c1.pib > c2.pib ? c1.nome : c2.nome);
    printf("Pontos turísticos: %s vence\n", c1.pturisticos > c2.pturisticos ? c1.nome : c2.nome);
    printf("Densidade Populacional: %s vence\n", c1.densidade < c2.densidade ? c1.nome : c2.nome); // menor vence
    printf("Super Poder: %s vence\n", c1.super_poder > c2.super_poder ? c1.nome : c2.nome);
}

int main() {
    Carta carta1, carta2;

    printf("=== Cadastro da Carta 1 ===\n");
    cadastrarCarta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    cadastrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}
