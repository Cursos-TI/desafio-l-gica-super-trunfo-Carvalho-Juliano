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


//Funções que executam a comparação entre os atributos
//Funções para executar as comparações com objetivo de deixar o código do switch mais limpo.
void compararPopulacao(char *nomeA, unsigned long int populacaoA, char *nomeB, unsigned long int populacaoB) {
    if (populacaoA == populacaoB) {
        printf("Carta 1: %s - População: %li habitantes\nCarta 2: %s - População: %li habitantes\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeA, nomeB);
    } else if (populacaoA > populacaoB) {
        printf("Carta 1: %s - População: %li habitantes\nCarta 2: %s - População: %li habitantes\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeA);
    } else {
        printf("Carta 1: %s - População: %li habitantes\nCarta 2: %s - População: %li habitantes\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, populacaoA, nomeB, populacaoB, nomeB);
    };
}

void compararPontosTuristicos(char *nomeA, int pontosA, char *nomeB, int pontosB) {
    if (pontosA == pontosB) {
        printf("Carta 1: %s - Pontos Turisticos: %i\nCarta 2: %s - Pontos Turisticos: %i\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, pontosA, nomeB, pontosB, nomeA, nomeB);
    } else if (pontosA > pontosB) {
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
        printf("Carta 1: %s - PIB: %.2f R$\nCarta 2: %s - PIB: %.2f R$\nResultado: Carta 1 (%s) e Carta 2 (%s) empataram!\n\n", nomeA, pibA, nomeB, pibB, nomeA, nomeB);
    } else if (pibA > pibB) {
        printf("Carta 1: %s - PIB: %.2f R$\nCarta 2: %s - PIB: %.2f R$\nResultado: Carta 1 (%s) venceu!\n\n", nomeA, pibA, nomeB, pibB, nomeA);
    } else {
        printf("Carta 1: %s - PIB: %.2f R$\nCarta 2: %s - PIB: %.2f R$\nResultado: Carta 2 (%s) venceu!\n\n", nomeA, pibA, nomeB, pibB, nomeB);
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

//Função parar chamar o menu ignorando a primeira opção selecionada.
void mostrarMenu(int ignorar) {
    if ( ignorar != 1) printf("1. População.\n");
    if ( ignorar != 2) printf("2. Pontos turísticos.\n");
    if ( ignorar != 3) printf("3. Area.\n");
    if ( ignorar != 4) printf("4. PIB.\n");
    if ( ignorar != 5) printf("5. Densidade populacional\n");
    if ( ignorar != 6) printf("6. Pib per capta\n");
    if ( ignorar != 7) printf("7. Super poder\n");
}


int main () {
    //Variaveis que serão usadas para cadastrar as cartas.
    char estadoA, estadoB, codigoA[20], codigoB[20], nomeA[50], nomeB[50];
    int pontosA, pontosB, opcaoA, opcaoB;
    unsigned long int populacaoA, populacaoB; 
    float areaA, areaB, pibA, pibB, somaDosAtributosA, somaDosAtributosB;
    float densidadePopulacionalA, pibPerCaptaA, densidadePopulacionalB, pibPerCaptaB;
    float superPoderA, superPoderB;

    //Carta A
    //Dados da carta A
    printf("Insira os dados da primeira carta \n");
    printf("Insira o estado da cidade: \n");
    scanf(" %c", &estadoA);
    printf("Insira o codigo da carta A: \n");
    scanf("%s", codigoA);
    getchar();
    printf("Insira o nome da cidade A: \n");
    fgets(nomeA, 50, stdin);
    printf("Insira a população da cidade A: \n");
    scanf("%li", &populacaoA);
    printf("Insira a area da cidade A: \n");
    scanf("%f", &areaA);
    printf("Insira o PIB da cidade A: \n");
    scanf("%f", &pibA);
    printf("Insira a quantidade de pontos turisticos da cidade A: \n");
    scanf("%i", &pontosA);
    densidadePopulacionalA = calcDensidadePopulacional(populacaoA, areaA);
    pibPerCaptaA = calcPibPerCapta(pibA, populacaoA);
    superPoderA = calcSuperPoder(pibA, pontosA, populacaoA, areaA, pibPerCaptaA, densidadePopulacionalA);

    //Dados da carta B
    printf("Insira os dados da segunda carta \n");
    printf("Insira o estado da cidade B: \n");
    scanf(" %c", &estadoB);
    printf("Insira o codigo da carta B: \n");
    scanf("%s", codigoB);
    getchar();
    printf("Insira o nome da cidade B: \n");
    fgets(nomeB, 50, stdin);
    printf("Insira a população da cidade B: \n");
    scanf("%li", &populacaoB);
    printf("Insira a area da cidade B: \n");
    scanf("%f", &areaB);
    printf("Insira o PIB da cidade B: \n");
    scanf("%f", &pibB);
    printf("Insira a quantidade de pontos turisticos da cidade B: \n");
    scanf("%i", &pontosB);
    densidadePopulacionalB = calcDensidadePopulacional(populacaoB, areaB);
    pibPerCaptaB = calcPibPerCapta(pibB, populacaoB);
    superPoderB = calcSuperPoder(pibB, pontosB, populacaoB, areaB, pibPerCaptaB, densidadePopulacionalB);

    printf("<-------Carta A------>\n");
    printf("Carta A:\nEstado: %c\nCódigo: %s\nNome da cidade: %sPopulação: %li Habitantes\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Túristicos: %i\nDensidade Populacional: %.2f hab/km²\nPib per Capta: %.2f reais\nSuper Poder: %.2f\n", estadoA, codigoA, nomeA, populacaoA, areaA, pibA, pontosA, densidadePopulacionalA, pibPerCaptaA, superPoderA);
    printf("-------------------------------------------- \n");
    printf("<-------Carta B------>\n");
    printf("Carta B:\nEstado: %c\nCódigo: %s\nNome da cidade: %sPopulação: %li Habitantes\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Túristicos: %i\nDensidade Populacional: %.2f hab/km²\nPib per Capta: %.2f reais\nSuper Poder: %2.f\n", estadoB, codigoB, nomeB, populacaoB, areaB, pibB, pontosB, densidadePopulacionalB, pibPerCaptaB, superPoderB);

    //menu interativo. O usuario vai escolher qual atributo deseja comparar.
    printf("Menu iterativo para selecionar qual dos atributos devem ser comparados:\n");
    printf("Escolhe o PRIMEIRO atributo a ser comparado entre as cartas:\n");
    printf("1. População.\n");
    printf("2. Pontos turísticos.\n");
    printf("3. Area.\n");
    printf("4. PIB.\n");
    printf("5. Densidade populacional.\n");
    printf("6. Pib per capta.\n");
    printf("7. Super poder.\n");
    printf("Escolha a primeira opção:");
    scanf("%d", &opcaoA);
    //Verificação dos dados inseridos
    if(opcaoA < 1 || opcaoA > 7) {
        printf("Opção invalida!\n");
        return 1;
    }
    printf("-----------------------------\n");

    printf("Agora escolha o SEGUNDO atributo.\n");
    mostrarMenu(opcaoA); // Função para exibir o menu sem a escolha da primeira opção
    printf("Escolha a segunda opção: ");
    scanf("%d", &opcaoB);
     //Verificação dos dados inseridos
     if(opcaoB < 1 || opcaoB > 7) {
        printf("Opção invalida!\n");
        return 1;
    }
    printf("-----------------------------\n");

    //Switch que armazena o resultado da primeira escolha do usuario e faz a comparação com a segunda escolha.
    switch (opcaoA)
    {
    case 1: //População
        switch (opcaoB)
        {
        case 2: //Pontos turísticos
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (populacaoA + pontosA);
            somaDosAtributosB = (populacaoB + pontosB);

            printf("Soma dos atributos A: %f\n", somaDosAtributosA);
            printf("Soma dos atributos B: %f\n", somaDosAtributosB);
            
            //Caso os atributos nao sejam iguais(que causaria empate) o programa exibe quem venceu. essa operação foi executada para todas as comparações
            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);
        
            break;

        case 3: //Área
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            compararArea(nomeA, areaA, nomeB, areaB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = ((populacaoA / 1000000.0) + areaA); //Ajuste do valor da população para facilitar o resultado dos calculos quando a operação for executada com um outro numero float. 
            somaDosAtributosB = ((populacaoB / 1000000.0) + areaB); //Ajuste do valor da população para facilitar o resultado dos calculos quando a operação for executada com um outro numero float.

            somaDosAtributosA != somaDosAtributosB 
            ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
            : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);
            
            break;
        case 4: //PIB
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            compararPib(nomeA, pibA, nomeB, pibB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = ((populacaoA / 1000000.0) + pibA);
            somaDosAtributosB = ((populacaoB / 1000000.0) + pibB);

            somaDosAtributosA != somaDosAtributosB 
            ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
            : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 5: //Densidade populacional
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);    
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            //Soma dos atributos
            somaDosAtributosA = ((populacaoA / 1000000.0 ) + densidadePopulacionalA);
            somaDosAtributosB = ((populacaoB / 1000000.0 ) + densidadePopulacionalB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 6: //Pib per capta
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);    
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            //Soma dos atributos
            somaDosAtributosA = ((populacaoA / 1000000.0) + pibPerCaptaA);
            somaDosAtributosB = ((populacaoB / 1000000.0) + pibPerCaptaB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 7: //Super poder
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);    
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            //Soma dos atributos
            somaDosAtributosA = ((populacaoA / 1000000.0) + superPoderA);
            somaDosAtributosB = ((populacaoB / 1000000.0) + superPoderB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        default:
            printf("Valor invalido!");
            break;
        };

        break;

    case 2: //Pontos turisticos
        switch (opcaoB)
        {
        case 1: //População
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pontosA + populacaoA);
            somaDosAtributosB = (pontosB + populacaoB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 3: //Área
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            compararArea(nomeA, areaA, nomeB, areaB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pontosA + areaA);
            somaDosAtributosB = (pontosB + areaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 4: //PIB
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            compararPib(nomeA, pibA, nomeB, pibB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pontosA + pibA);
            somaDosAtributosB = (pontosB + pibB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 5: //Densidade populacional
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);    
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            //Soma dos atributos
            somaDosAtributosA = (pontosA + densidadePopulacionalA);
            somaDosAtributosB = (pontosB + densidadePopulacionalB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 6: //Pib per capta
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);     
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            //Soma dos atributos
            somaDosAtributosA = (pontosA  + pibPerCaptaA);
            somaDosAtributosB = (pontosB + pibPerCaptaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 7: //Super poder
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);     
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            //Soma dos atributos
            somaDosAtributosA = (pontosA  + superPoderA);
            somaDosAtributosB = (pontosB  + superPoderB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        default:
            printf("Valor invalido!");
            break;
        }
        break;

    case 3: //area
        switch (opcaoB)
        {
        case 1: //População
            compararArea(nomeA, areaA, nomeB, areaB);
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (areaA + (populacaoA / 1000000.0)); //Ajuste para facilitar o resultado do calculo
            somaDosAtributosB = (areaB + (populacaoB / 1000000.0)); //Ajuste para facilitar o resultado do calculo

            somaDosAtributosA != somaDosAtributosB 
            ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
            : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 2: //Pontos turisticos
            compararArea(nomeA, areaA, nomeB, areaB);
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (areaA + pontosA);
            somaDosAtributosB = (areaB + pontosB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 4: // PIB
            compararArea(nomeA, areaA, nomeB, areaB);
            compararPib(nomeA, pibA, nomeB, pibB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (areaA + pibA);
            somaDosAtributosB = (areaB + pibB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 5: //Densidade populacional
            compararArea(nomeA, areaA, nomeB, areaB);    
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            //Soma dos atributos
            somaDosAtributosA = (areaA + densidadePopulacionalA);
            somaDosAtributosB = (areaB + densidadePopulacionalB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 6: //Pib per capta
            compararArea(nomeA, areaA, nomeB, areaB);     
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            //Soma dos atributos
            somaDosAtributosA = (areaA  + pibPerCaptaA);
            somaDosAtributosB = (areaB + pibPerCaptaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 7: //Super poder
            compararArea(nomeA, areaA, nomeB, areaB);     
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            //Soma dos atributos
            somaDosAtributosA = (areaA  + superPoderA);
            somaDosAtributosB = (areaB  + superPoderB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        
        default:
            break;
        }
        break;
    case 4: // comparar PIB
        switch (opcaoB)
        {
        case 1: //População
            compararPib(nomeA, pibA, nomeB, pibB);
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibA + (populacaoA / 1000000.0));
            somaDosAtributosB = (pibB + (populacaoB / 1000000.0));

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);
                
            break;
        case 2: //Pontos turisticos
            compararPib(nomeA, pibA, nomeB, pibB);
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibA + pontosA);
            somaDosAtributosB = (pibB + pontosB);

            somaDosAtributosA != somaDosAtributosB 
            ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
            : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 3: //Área
            compararPib(nomeA, pibA, nomeB, pibB);
            compararArea(nomeA, areaA, nomeB, areaB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibA + areaA);
            somaDosAtributosB = (pibB + areaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 5: //Densidade populacional
            compararPib(nomeA, pibA, nomeB, pibB);   
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            //Soma dos atributos
            somaDosAtributosA = (pibA + densidadePopulacionalA);
            somaDosAtributosB = (pibB + densidadePopulacionalB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 6: //Pib per capta
            compararPib(nomeA, pibA, nomeB, pibB);     
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            //Soma dos atributos
            somaDosAtributosA = (pibA  + pibPerCaptaA);
            somaDosAtributosB = (pibB + pibPerCaptaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 7: //Super poder
            compararPib(nomeA, pibA, nomeB, pibB);     
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            //Soma dos atributos
            somaDosAtributosA = (pibA  + superPoderA);
            somaDosAtributosB = (pibB  + superPoderB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        default:
            printf("Valor invalido!\n");
            break;
        }
        break;
    case 5: //comparar densidade populacional
        switch (opcaoB)
        {
        case 1: //População
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (densidadePopulacionalA + (populacaoA / 1000000.0));
            somaDosAtributosB = (densidadePopulacionalB + (populacaoB / 1000000.0));

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 2: //Pontos turisticos
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (densidadePopulacionalA + pontosA);
            somaDosAtributosB = (densidadePopulacionalB + pontosB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 3: //Área
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            compararArea(nomeA, areaA, nomeB, areaB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (densidadePopulacionalA + areaA);
            somaDosAtributosB = (densidadePopulacionalB + areaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 4: // PIB
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            compararPib(nomeA, pibA, nomeB, pibB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (densidadePopulacionalA + pibA);
            somaDosAtributosB = (densidadePopulacionalB + pibB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 6: //Pib per capta
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);     
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            //Soma dos atributos
            somaDosAtributosA = (densidadePopulacionalA  + pibPerCaptaA);
            somaDosAtributosB = (densidadePopulacionalB + pibPerCaptaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 7: //Super poder
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);     
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            //Soma dos atributos
            somaDosAtributosA = (densidadePopulacionalA  + superPoderA);
            somaDosAtributosB = (densidadePopulacionalB  + superPoderB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        default:
            printf("Valor invalido!\n");
            break;
        }
       
    break;

    case 6: //comparar pib per capta
        switch (opcaoB)
        {
        case 1: //População
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibPerCaptaA + (populacaoA / 1000000.0));
            somaDosAtributosB = (pibPerCaptaB + (populacaoB / 1000000.0));

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 2: //Pontos turisticos
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibPerCaptaA + pontosA);
            somaDosAtributosB = (pibPerCaptaB + pontosB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 3: //Área
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            compararArea(nomeA, areaA, nomeB, areaB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibPerCaptaA + areaA);
            somaDosAtributosB = (pibPerCaptaB + areaB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 4: // PIB
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            compararPib(nomeA, pibA, nomeB, pibB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (pibPerCaptaA + pibA);
            somaDosAtributosB = (pibPerCaptaB + pibB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 5: //Densidade populacional
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);   
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            //Soma dos atributos
            somaDosAtributosA = (pibPerCaptaA + densidadePopulacionalA);
            somaDosAtributosB = (pibPerCaptaB + densidadePopulacionalB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 7: //Super poder
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);     
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            //Soma dos atributos
            somaDosAtributosA = (pibPerCaptaA  + superPoderA);
            somaDosAtributosB = (pibPerCaptaB  + superPoderB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;

            default:
                printf("Valor invalido!\n");
                break;
        }
        break;

    case 7: // comparar com super poder
        switch (opcaoB)
        {
        case 1: //População
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            compararPopulacao(nomeA, populacaoA, nomeB, populacaoB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (superPoderA + (populacaoA / 1000000.0));
            somaDosAtributosB = (superPoderB + (populacaoB / 1000000.0));

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 2: //Pontos turisticos
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            compararPontosTuristicos(nomeA, pontosA, nomeB, pontosB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (superPoderA + pontosA);
            somaDosAtributosB = (superPoderB + pontosB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 3: //Área
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            compararArea(nomeA, areaA, nomeB, areaB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (superPoderA + areaA);
            somaDosAtributosB = (superPoderB + areaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 4: // PIB
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);
            compararPib(nomeA, pibA, nomeB, pibB);
            printf("--------------------------------------\n");
            //Soma dos atributos
            somaDosAtributosA = (superPoderA + pibA);
            somaDosAtributosB = (superPoderB + pibB);

           somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 5: //Densidade populacional
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);   
            compararDensidadePopulacional(nomeA, densidadePopulacionalA, nomeB, densidadePopulacionalB);
            //Soma dos atributos
            somaDosAtributosA = (superPoderA + densidadePopulacionalA);
            somaDosAtributosB = (superPoderB + densidadePopulacionalB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;
        case 6: //Pib per capta
            compararSuperPoder(nomeA, superPoderA, nomeB, superPoderB);     
            compararPibPerCapta(nomeA, pibPerCaptaA, nomeB, pibPerCaptaB);
            //Soma dos atributos
            somaDosAtributosA = (superPoderA  + pibPerCaptaA);
            somaDosAtributosB = (superPoderB + pibPerCaptaB);

            somaDosAtributosA != somaDosAtributosB 
                ? printf("A cidade %s ganhou pois sua soma dos atributos deu %.2f\n", 
                    somaDosAtributosA > somaDosAtributosB ? nomeA : nomeB,
                    somaDosAtributosA > somaDosAtributosB ? somaDosAtributosA : somaDosAtributosB)
                : printf("A soma dos atributos de cidade %s e cidade %s deu empate!\n", nomeA, nomeB);

            break;

        default:
            printf("Valor invalido!\n");
            break;
        }

        break;
    default:
        printf("Valor invalido!\n");
        break;
    }

    return 0;
}