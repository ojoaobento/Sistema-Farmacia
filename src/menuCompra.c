#include "funcoes.h"

void menuCompras(TipoListaMovimentacao *listaMovimentacao, TipoListaCliente *listaCliente, TipoListaMedicamento *listaMedicamento){
    
    int opcao;
    
    do {
        system("cls");
        tela();

        gotoxy(32,12);
        printf("1 - COMPRAR MEDICAMENTO");

        gotoxy(32,13);
        printf("2 - CONSULTAR COMPRAS");

        gotoxy(32,14);
        printf("3 - RETORNAR");

        gotoxy(32,16);
        printf("OPCAO : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                compraMedicamento(listaMovimentacao, listaCliente, listaMedicamento);
                break;
            case 2:
                consultarCompras(listaMovimentacao);
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