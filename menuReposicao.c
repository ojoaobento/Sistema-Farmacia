#include "funcoes.h"

void menuReposicao(TipoListaMedicamento *listaMedicamento, TipoListaEstoque *listaEstoque){

    int opcao;
    do{
        system("cls");
        tela();

        gotoxy(32,12);
        printf("1 - MOVIMENTAR ESTOQUE");

        gotoxy(32,13);
        printf("2 - CONSULTAR REGISTROS DE MOVIMENTACAO");

        gotoxy(32,14);
        printf("3 - RETORNAR");

        gotoxy(32,16);
        printf("OPCAO : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                movimentacaoEstoque(listaMedicamento, listaEstoque);
                break;
            case 2:
                consultarRegistrosMovimentacao(listaEstoque);
                break;
            case 3:
                return;
                break;
            default:
                system("cls");
                tela();
                limpa_msg();
                gotoxy(2,23);
                printf("OPCAO INVALIDA, VOLTE AO MENU PRINCIPAL.....");
                getch();
                return;
                break;
        }

    }while(opcao != 3);
}