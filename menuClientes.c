#include "funcoes.h"

void menuClientes(TipoListaCliente *lista){
    
    int opcao;
    
    do {
        system("cls");
        tela();

        gotoxy(32, 9);
        printf("CADASTRO DE CLIENTES");

        gotoxy(35,12);
        printf("1- INCLUSAO");

        gotoxy(35,13);
        printf("2- ALTERAR");

        gotoxy(35,14);
        printf("3- EXCLUSAO");

        gotoxy(35,15);
        printf("4- CONSULTAR");

        gotoxy(35,16);
        printf("5- RETORNAR");

        gotoxy(35,18);
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inclusaoCliente(lista);
                break;
            case 2:
                alterarCliente(lista);
                break;
            case 3:
                exclusaoCliente(lista);
                break;
            case 4:
                consultaCliente(lista);
                break;
            case 5:

                break;
            default:

                break;
            
        }

    }while(opcao != 5);
}