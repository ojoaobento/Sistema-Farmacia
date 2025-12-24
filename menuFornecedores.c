#include "funcoes.h"

void menuFornecedores(TipoListaFornecedor *listaFornecedor){
    
    int opcao;

    do {
        system("cls");
        tela();

        gotoxy(33,9);
        printf("CADASTRO FORNECEDORES");

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
        printf("OPCAO : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inclusaoFornecedor(listaFornecedor);
                break;
            case 2:
                alterarFornecedor(listaFornecedor);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            default:

                break;
        }

    }while(opcao != 7); 
}