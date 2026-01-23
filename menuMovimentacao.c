#include "funcoes.h"

void menuMovimentacao(TipoListaMovimentacao *listaMovimentacao, TipoListaCliente *listaCliente, TipoListaMedicamento *listaMedicamento){

    int opcao;


    system("cls");
    tela();

    gotoxy(36,9);
    printf("MOVIMENTACOES");


    gotoxy(32,12);
    printf("1 - COMPRAS MEDICAMENTOS");

    gotoxy(32,13);
    printf("2 - REPOSICAO ESTOQUE");

    gotoxy(32,14);
    printf("3 - RETORNAR");

    gotoxy(37,16);
    printf("OPCAO : ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            compraMedicamento(listaMovimentacao, listaCliente, listaMedicamento);
            break;
        case 2:
            return;
            break;
        case 3:

            break;
        default:

            break;
    }
}