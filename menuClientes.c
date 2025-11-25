#include "funcoes.h"

void menuClientes(TipoListaCliente *listaCliente){
    
    int opcao;
    
    do {
        system("cls");
        tela();

        gotoxy(33, 9);
        printf("CADASTRO DE CLIENTES");

        gotoxy(35,12);
        printf("1 - INCLUSAO");

        gotoxy(35,13);
        printf("2 - ALTERAR");

        gotoxy(35,14);
        printf("3 - CONSULTAR");

        gotoxy(35,15);
        printf("4 - CONSULTAR POR ORDEM");
        
        gotoxy(35,16);
        printf("5 - INATIVAR");

        gotoxy(35,17);
        printf("6 - EXCLUSAO");

        gotoxy(35,18);
        printf("7 - RETORNAR");

        gotoxy(37,20);
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inclusaoCliente(listaCliente);
                break;
            case 2:
                alterarCliente(listaCliente);
                break;
            case 3:
                consultaCliente(listaCliente);
                break;
            case 4:
                consultaOrdemCliente(listaCliente);
                break;
            case 5:

                break;
            case 6:
                exclusaoCliente(listaCliente);
                break;
            case 7:

                break;
            default:

                break;
            
        }

    }while(opcao != 5);
}