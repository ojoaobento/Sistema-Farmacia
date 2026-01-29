#include "funcoes.h"

void menuRelatorio(){

    int opcao;


    system("cls");
    tela();

    gotoxy(32,12);
    printf("1 - BALANCO DO ACERVO");

    gotoxy(32,13);
    printf("2 - BALANCO DAS MOVIMENTACOES");


    gotoxy(32,15);
    printf("OPCAO : ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:

            break;
        case 2:

            break;
        default:

            break;
    }
}