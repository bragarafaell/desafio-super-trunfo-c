#include <stdio.h>
#include <stdlib.h>

/*
 * Desafio Super Trunfo - Nível Mestre
 * Objetivo: Ler, calcular, calcular Super Poder e comparar atributos.
 */
int main() {

    // --- Variáveis da Carta 1 ---
    char estado1;
    char codigo1[5]; 
    char nomeCidade1[50];
    // MUDANÇA (Mestre): int -> unsigned long int
    unsigned long int populacao1; 
    float area1;
    float pib1; // PIB em bilhões
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;
    // NOVA VARIÁVEL (Mestre)
    float superPoder1;

    // --- Variáveis da Carta 2 ---
    char estado2;
    char codigo2[5];
    char nomeCidade2[50];
    // MUDANÇA (Mestre): int -> unsigned long int
    unsigned long int populacao2;
    float area2;
    float pib2; // PIB em bilhões
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;
    // NOVA VARIÁVEL (Mestre)
    float superPoder2;
    
    // --- Variáveis de Comparação (NOVO - Mestre) ---
    // 1 = Carta 1 vence, 0 = Carta 2 vence (ou empata)
    int compPopulacao;
    int compArea;
    int compPib;
    int compPontos;
    int compDensidade; // Regra especial: menor vence
    int compPibPerCapita;
    int compSuperPoder;

    // --- Início do Programa ---
    printf("--- Super Trunfo Cidades - Batalha ---\n");
    
    // --- Leitura da Carta 1 ---
    printf("\n--- Cadastro da Carta 1 ---\n");
    
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1); 

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); 

    printf("Digite a Populacao: ");
    // MUDANÇA (Mestre): %d -> %lu (para unsigned long int)
    scanf("%lu", &populacao1); 

    printf("Digite a Area (em km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais, ex: 699.28): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Cálculos Carta 1 ---
    densidade1 = (float)populacao1 / area1; // (float) garante divisão correta
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;

    // CÁLCULO SUPER PODER (NOVO - Mestre)
    // Atenção às conversões de tipo (casting) para somar
    superPoder1 = (float)populacao1 + 
                  area1 + 
                  pib1 + // Usamos o valor em bilhões (ex: 699.28)
                  (float)pontosTuristicos1 + 
                  pibPerCapita1 + 
                  (1.0 / densidade1); // Inverso da densidade

    // --- Leitura da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2); 

    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2); // %lu

    printf("Digite a Area (em km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais, ex: 300.50): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos Carta 2 ---
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;

    // CÁLCULO SUPER PODER (NOVO - Mestre)
    superPoder2 = (float)populacao2 + 
                  area2 + 
                  pib2 + 
                  (float)pontosTuristicos2 + 
                  pibPerCapita2 + 
                  (1.0 / densidade2);

    // --- Exibição dos Dados (Opcional no Mestre, mas bom para checar) ---
    printf("\n\n--- Cartas Cadastradas ---\n");
    printf("\nCarta 1 (%s - %s): Pop: %lu, Area: %.2f, PIB: %.2fbi, Pontos: %d, Dens: %.2f, PIB p/c: %.2f, SP: %.2f\n",
           codigo1, nomeCidade1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);
    printf("Carta 2 (%s - %s): Pop: %lu, Area: %.2f, PIB: %.2fbi, Pontos: %d, Dens: %.2f, PIB p/c: %.2f, SP: %.2f\n",
           codigo2, nomeCidade2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);


    // --- COMPARAÇÃO DAS CARTAS (NOVO - Mestre) ---
    // (1 = Verdadeiro, 0 = Falso)
    compPopulacao     = populacao1 > populacao2;
    compArea          = area1 > area2;
    compPib           = pib1 > pib2;
    compPontos        = pontosTuristicos1 > pontosTuristicos2;
    compDensidade     = densidade1 < densidade2; // REGRA ESPECIAL: Menor vence!
    compPibPerCapita  = pibPerCapita1 > pibPerCapita2;
    compSuperPoder    = superPoder1 > superPoder2;


    // --- Exibição dos Resultados da Batalha ---
    printf("\n--- Resultado da Batalha ---\n");
    // (comp ? 1 : 2) é um operador ternário: se comp for 1, imprime 1, senão imprime 2.
    printf("Populacao:           Carta %d venceu (%d)\n", (compPopulacao ? 1 : 2), compPopulacao);
    printf("Area:                Carta %d venceu (%d)\n", (compArea ? 1 : 2), compArea);
    printf("PIB:                 Carta %d venceu (%d)\n", (compPib ? 1 : 2), compPib);
    printf("Pontos Turisticos:   Carta %d venceu (%d)\n", (compPontos ? 1 : 2), compPontos);
    printf("Densidade Popul.:    Carta %d venceu (%d)\n", (compDensidade ? 1 : 2), compDensidade); // Menor vence
    printf("PIB per Capita:      Carta %d venceu (%d)\n", (compPibPerCapita ? 1 : 2), compPibPerCapita);
    printf("Super Poder:         Carta %d venceu (%d)\n", (compSuperPoder ? 1 : 2), compSuperPoder);

    return 0;
}