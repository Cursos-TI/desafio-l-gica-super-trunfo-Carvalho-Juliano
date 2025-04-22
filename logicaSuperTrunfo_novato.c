#include <stdio.h>
#include <string.h>

//funções para calcular os atributos densidade populacionar e pib per capta.
float calcDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

float calcPibPerCapta(float pib, int populacao) {
    return  (pib*1e9) / populacao; //O pib foi convertido para bilhões no intuido de aumentar a precisão na hora do resultado
    
}

float calcSuperPoder(float pib, int pontos, unsigned long int populacao, float area, float pibPerCapta, float densidadePopulacional) {
    return (float) (pontos + populacao + area + pib + pibPerCapta) - densidadePopulacional;
}

int main() {
    //para agilidade no teste do código, os dados das cartas vao ser inseridos manualmente no script e no ultimo exercicio serão inseridos via terminal
    char estadoA, estadoB, codigoA[20], codigoB[20], nomeA[50], nomeB[50];
    int pontosA, pontosB;
    unsigned long int populacaoA, populacaoB; //Alteração feita à pedido do exercicio Mestre.
    float areaA, areaB, pibA, pibB;
    float densidadePopulacionalA, pibPerCaptaA, densidadePopulacionalB, pibPerCaptaB;
    float SuperPoderA, SuperPoderB; 

    //Inserção dos dados via código
    //Carta A
    estadoA ='A';
    strcpy(codigoA, "A01");
    strcpy(nomeA, "São Paulo");
    pontosA = 50;
    populacaoA = 12325000;
    areaA = 1524.11;
    pibA = 699.28;
    densidadePopulacionalA = calcDensidadePopulacional(populacaoA, areaA);
    pibPerCaptaA = calcPibPerCapta(pibA, populacaoA);
    SuperPoderA = calcSuperPoder(pibA, pontosA, populacaoA, areaA, pibPerCaptaA, densidadePopulacionalA);

    //Carta B
    estadoB ='B';
    strcpy(codigoB,"B02");
    strcpy(nomeB, "Rio de Janeiro");
    pontosB = 30;
    populacaoB = 6748000;
    areaB = 1200.25;
    pibB = 300.50;
    densidadePopulacionalB = calcDensidadePopulacional(populacaoB, areaB);
    pibPerCaptaB = calcPibPerCapta(pibB, populacaoB);
    SuperPoderB = calcSuperPoder(pibB, pontosB, populacaoB, areaB, pibPerCaptaB, densidadePopulacionalB);
    
    //desafio lógica do jogo nivel: novato
    //Carta A x Carta B <--População-->
    if (populacaoA > populacaoB) {
        printf("Carta 1: %s - População: %li\nCarta 2: %s - População: %li\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeA);
    } else {
        printf("Carta 1: %s - População: %li\nCarta 2: %s - População: %li\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeB);
    };

    //Carta A x Carta B <--Pontos Turisticos-->
    if (pontosA > pontosB) {
        printf("Carta 1: %s - Pontos Turisticos: %i\nCarta 2: %s - Pontos Turisticos: %i\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pontosA, nomeB, pontosB, nomeA);
    } else {
        printf("Carta 1: %s - Pontos Turisticos: %i\nCarta 2: %s - Pontos Turisticos: %i\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pontosA, nomeB, pontosB, nomeB);
    };

    //Carta A x Carta B <--Area-->
    if (areaA > areaB) {
        printf("Carta 1: %s - Area: %.2f\nCarta 2: %s - Area: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, areaA, nomeB, areaB, nomeA);
    } else {
        printf("Carta 1: %s - Area: %.2f\nCarta 2: %s - Area: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, areaA, nomeB, areaB, nomeB);
    };

    //Carta A x Carta B <--PIB-->
    if (pibA > pibB) {
        printf("Carta 1: %s - PIB: %.2f\nCarta 2: %s - PIB: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pibA, nomeB, pibB, nomeA);
    } else {
        printf("Carta 1: %s - PIB: %.2f\nCarta 2: %s - PIB: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pibA, nomeB, pibB, nomeB);
    };

    //Carta A x Carta B <--Densidade populacional-->
    if (densidadePopulacionalA < densidadePopulacionalB) {
        printf("Carta 1: %s - Densidade populacional: %.2f\nCarta 2: %s - Densidade populacional: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB, nomeA);
    } else {
        printf("Carta 1: %s - Densidade populacional: %.2f\nCarta 2: %s - Densidade populacional: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB, nomeB);
    };

    //Carta A x Carta B <--PIB per capta-->
    if (pibPerCaptaA > pibPerCaptaB) {
        printf("Carta 1: %s - PIB per capta: %.2f\nCarta 2: %s -PIB per capta: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pibPerCaptaA, nomeB, pibPerCaptaB, nomeA);
    } else {
        printf("Carta 1: %s - PIB per capta: %.2f\nCarta 2: %s - PIB per capta: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pibPerCaptaA, nomeB, pibPerCaptaB, nomeB);
    };

    //Carta A x Carta B <--Super Poder-->
    if (SuperPoderA > SuperPoderB) {
        printf("Carta 1: %s - Super poder: %.2f\nCarta 2: %s - Super poder: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, SuperPoderA, nomeB, SuperPoderB, nomeA);
    } else {
        printf("Carta 1: %s - Super poder: %.2f\nCarta 2: %s - Super poder: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, SuperPoderA, nomeB, SuperPoderB, nomeB);
    }


    return 0;
}
