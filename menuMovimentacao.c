#include "funcoes.h"

void menuMovimentacao(TipoListaMovimentacao *listaMovimentacao){

    int opcao;


    system("cls");
    tela();

    gotoxy(36,9);
    printf("MOVIMENTACOES");


    gotoxy(32,12);
    printf("1 - COMPRAS MEDICAMENTOS");

    gotoxy(32,13);
    printf("2 - REPOSICAO ESTOQUE");

    gotoxy(37,15);
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