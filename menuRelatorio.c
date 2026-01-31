#include "funcoes.h"

void menuRelatorio(TipoListaMedicamento *listaMedicamento, TipoListaMovimentacao *listaMovimentacao, TipoListaCliente *listaCliente, TipoListaRanking *listaRanking){

    int opcao;

    do {
        system("cls");
        tela();

        gotoxy(32,12);
        printf("1 - BALANCO DO ACERVO");

        gotoxy(32,13);
        printf("2 - BALANCO DAS MOVIMENTACOES");

        gotoxy(32,14);
        printf("3 - RETORNAR");


        gotoxy(32,16);
        printf("OPCAO : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                balancoAcervo(listaMedicamento, listaMovimentacao);
                break;
            case 2:
                balancoMovimentacao(listaCliente,listaMedicamento, listaMovimentacao, listaRanking);
                break;
            case 3:
                return;
                break;
            default:

                break;
        }

    } while(opcao != 3);
}