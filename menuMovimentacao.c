#include "funcoes.h"

void menuMovimentacao(TipoListaMovimentacao *listaMovimentacao, TipoListaCliente *listaCliente, TipoListaMedicamento *listaMedicamento, TipoListaEstoque *listaEstoque){

    int opcao;

    do {
        system("cls");
        tela();

        gotoxy(36,9);
        printf("MOVIMENTACOES");

        gotoxy(32,12);
        printf("1 - COMPRAS");

        gotoxy(32,13);
        printf("2 - MOVIMENTAR ESTOQUE");

        gotoxy(32,14);
        printf("3 - RETORNAR");

        gotoxy(32,16);
        printf("OPCAO : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                menuCompras(listaMovimentacao, listaCliente, listaMedicamento);          
                break;
            case 2:
                menuReposicao(listaMedicamento, listaEstoque);
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