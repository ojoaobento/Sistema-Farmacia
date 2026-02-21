#include "funcoes.h"

void menuMedicamentos(TipoListaMedicamento *listaMedicamento, TipoListaFornecedor *listaFornecedor){

    int opcao;


    do {
        system("cls");
        tela();

        gotoxy(33,9);
        printf("CADASTRO MEDICAMENTOS");

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

        gotoxy(35,20);
        printf("OPCAO : ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inclusaoMedicamentos(listaMedicamento,listaFornecedor);
                break;
            case 2:
                alterarMedicamentos(listaMedicamento, listaFornecedor);
                break;
            case 3:
                consultarMedicamento(listaMedicamento);
                break;
            case 4:
                consultaOrdemMedicamento(listaMedicamento);
                break;
            case 5:
                inativarMedicamento(listaMedicamento);
                break;
            case 6:
                exclusaoMedicamento(listaMedicamento);
                break;
            case 7:
                return;
                break;
            default:
                system("cls");
                tela();
                gotoxy(2,23);
                printf("OPCAO INVALIDA, RETORNE AO MENU PRINCIPAL.....");
                getch();
                return;
                break;
        }
    }while(opcao != 7);
}