#include <stdio.h>
#include <string.h>

//funções para calcular os atributos densidade populacionar e pib per capta.
float calcDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

float calcPibPerCapta(float pib, int populacao) {
    return  (pib*1e9) / populacao; //O pib foi convertido para bilhões no intuido de aumentar a precisão na hora do resultado
    
}

//Função para calcular o super poder de uma carta
float calcSuperPoder(float pib, int pontos, unsigned long int populacao, float area, float pibPerCapta, float densidadePopulacional) {
    return (float) (pontos + populacao + area + pib + pibPerCapta) - densidadePopulacional;
}

//Feito funções para executar as comparações com objetivo de deixar o código do switch mais limpo.
void compararPopulacao(char *nomeA, unsigned long int populacaoA, char *nomeB, unsigned long int populacaoB) {
    if (populacaoA == populacaoB) {
        printf("Carta 1: %s - População: %li\nCarta 2: %s - População: %li\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeA, nomeB);
    } else if (populacaoA > populacaoB) {
        printf("Carta 1: %s - População: %li\nCarta 2: %s - População: %li\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeA);
    } else {
        printf("Carta 1: %s - População: %li\nCarta 2: %s - População: %li\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeB);
    };
}

void compararPontosTuristicos(char *nomeA, int pontosA, char *nomeB, int pontosB) {
    if (pontosA == pontosB) {
        printf("Carta 1: %s - Pontos Turisticos: %i\nCarta 2: %s - Pontos Turisticos: %i\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, pontosA, nomeB, pontosB, nomeA, nomeB);
    }
    if (pontosA > pontosB) {
        printf("Carta 1: %s - Pontos Turisticos: %i\nCarta 2: %s - Pontos Turisticos: %i\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pontosA, nomeB, pontosB, nomeA);
    } else {
        printf("Carta 1: %s - Pontos Turisticos: %i\nCarta 2: %s - Pontos Turisticos: %i\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pontosA, nomeB, pontosB, nomeB);
    };
}

void compararArea(char *nomeA, float areaA, char *nomeB, float areaB) {
    if (areaA == areaB) {
        printf("Carta 1: %s - Area: %.2f\nCarta 2: %s - Area: %.2f\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, areaA, nomeB, areaB, nomeA, nomeB);
    } else if (areaA > areaB) {
        printf("Carta 1: %s - Area: %.2f\nCarta 2: %s - Area: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, areaA, nomeB, areaB, nomeA);
    } else {
        printf("Carta 1: %s - Area: %.2f\nCarta 2: %s - Area: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, areaA, nomeB, areaB, nomeB);
    };
}

void compararPib(char *nomeA, float pibA, char *nomeB, float pibB) {
    if (pibA == pibB) {
        printf("Carta 1: %s - PIB: %.2f\nCarta 2: %s - PIB: %.2f\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, pibA, nomeB, pibB, nomeA, nomeB);
    } else if (pibA > pibB) {
        printf("Carta 1: %s - PIB: %.2f\nCarta 2: %s - PIB: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pibA, nomeB, pibB, nomeA);
    } else {
        printf("Carta 1: %s - PIB: %.2f\nCarta 2: %s - PIB: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pibA, nomeB, pibB, nomeB);
    };
}

void compararDensidadePopulacional(char *nomeA, float densidadePopulacionalA, char *nomeB, float densidadePopulacionalB) {
    if (densidadePopulacionalA == densidadePopulacionalB) {
        printf("Carta 1: %s - Densidade populacional: %.2f\nCarta 2: %s - Densidade populacional: %.2f\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB, nomeA, nomeB);
    }else if (densidadePopulacionalA < densidadePopulacionalB) {
        printf("Carta 1: %s - Densidade populacional: %.2f\nCarta 2: %s - Densidade populacional: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB, nomeA);
    } else {
        printf("Carta 1: %s - Densidade populacional: %.2f\nCarta 2: %s - Densidade populacional: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB, nomeB);
    };
}

void compararPibPerCapta(char *nomeA, float pibPerCaptaA, char *nomeB, float pibPerCaptaB) {
    if (pibPerCaptaA == pibPerCaptaB) {
        printf("Carta 1: %s - PIB per capta: %.2f\nCarta 2: %s - PIB per capta: %.2f\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, pibPerCaptaA, nomeB, pibPerCaptaB, nomeA, nomeB);
    } else if (pibPerCaptaA > pibPerCaptaB) {
        printf("Carta 1: %s - PIB per capta: %.2f\nCarta 2: %s - PIB per capta: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pibPerCaptaA, nomeB, pibPerCaptaB, nomeA);
    } else {
        printf("Carta 1: %s - PIB per capta: %.2f\nCarta 2: %s - PIB per capta: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pibPerCaptaA, nomeB, pibPerCaptaB, nomeB);
    }
}

void compararSuperPoder(char *nomeA, float superPoderA, char *nomeB, float superPoderB) {
    if (superPoderA == superPoderB) {
        printf("Carta 1: %s - Super poder: %.2f\nCarta 2: %s - Super poder: %.2f\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, superPoderA, nomeB, superPoderB, nomeA, nomeB);
    } else if (superPoderA > superPoderB) {
        printf("Carta 1: %s - Super poder: %.2f\nCarta 2: %s - Super poder: %.2f\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, superPoderA, nomeB, superPoderB, nomeA);
    } else {
        printf("Carta 1: %s - Super poder: %.2f\nCarta 2: %s - Super poder: %.2f\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, superPoderA, nomeB, superPoderB, nomeB);
    }
}

int main() {
    //para agilidade no teste do código, os dados das cartas vao ser inseridos manualmente no script e no ultimo exercicio serão inseridos via terminal
    char estadoA, estadoB, codigoA[20], codigoB[20], nomeA[50], nomeB[50];
    int pontosA, pontosB;
    unsigned long int populacaoA, populacaoB; //Alteração feita à pedido do exercicio Mestre.
    float areaA, areaB, pibA, pibB;
    float densidadePopulacionalA, pibPerCaptaA, densidadePopulacionalB, pibPerCaptaB;
    float superPoderA, superPoderB;
    int opcao; //Variavel para o menu de opções (Desafio aventureiro.)

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
    superPoderA = calcSuperPoder(pibA, pontosA, populacaoA, areaA, pibPerCaptaA, densidadePopulacionalA);

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
    superPoderB = calcSuperPoder(pibB, pontosB, populacaoB, areaB, pibPerCaptaB, densidadePopulacionalB);
    

    //menu interativo. O usuario vai escolher qual atributo deseja comparar.
    printf("Menu iterativo para selecionar qual dos atributos devem ser comparados:\n");
    printf("1. População.\n");
    printf("2. Pontos turísticos.\n");
    printf("3. Area.\n");
    printf("4. PIB.\n");
    printf("5. Densidade populacional.\n");
    printf("6. PIB per capta.\n");
    printf("7. Super poder.\n");
    printf("8. Sair.\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    

    switch (opcao)
    {
    //Carta A x Carta B <--População-->
    case 1:
        printf("Comparação entre População:\n");
        compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
        break;

    //Carta A x Carta B <--Pontos Turisticos-->    
    case 2:
        printf("Comparação entre Pontos Turisticos:\n");
        compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
        break;

    //Carta A x Carta B <--Area-->    
    case 3:
        printf("Comparação entre Area:\n");
        compararArea(nomeA, areaA, nomeB, areaB);
        break;

    //Carta A x Carta B <--PIB-->
    case 4:
        printf("Comparação entre PIB\n");
        compararPib(nomeA, pibA, nomeB, pibB);
        break;

    //Carta A x Carta B <--Densidade populacional-->    
    case 5:
        printf("Comparação entre densidade populacional:\n");
        compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
        break;
    
    //Carta A x Carta B <--PIB per capta-->    
    case 6:
        printf("Comparação entre PIB per capta:\n");
        compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
        break;
    
    //Carta A x Carta B <--Super Poder-->    
    case 7:
        printf("Comparação entre Super poder:\n");
        compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
        break;

    case 8:
        printf("Saindo...");
        break;
    
    default:
        printf("Opção invalida");
        break;
    }

    return 0;
}