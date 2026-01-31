#include "funcoes.h"

void menuPrincipal(TipoListaCliente *listaCliente, TipoListaMedicamento *listaMedicamento, TipoListaFornecedor *listaFornecedor, TipoListaMovimentacao *listaMovimentacao, TipoListaEstoque *listaEstoque, TipoListaRanking *listaRanking){
    
    int opcao;

    do {
        system("cls");
        tela();
        limpa_msg();

        gotoxy(35,12);
        printf("1 - CLIENTES");

        gotoxy(35,13);
        printf("2 - MEDICAMENTOS");

        gotoxy(35,14);
        printf("3 - FORNECEDORES");

        gotoxy(35,15);
        printf("4 - MOVIMENTACOES");

        gotoxy(35,16);
        printf("5 - RELATORIOS");

        gotoxy(35,17);
        printf("6 - SAIR e SALVAR");

        gotoxy(35,19);
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                menuClientes(listaCliente);
                break;
            case 2:
                menuMedicamentos(listaMedicamento, listaFornecedor);
                break;
            case 3:
                menuFornecedores(listaFornecedor);
                break;
            case 4:
                menuMovimentacao(listaMovimentacao, listaCliente, listaMedicamento, listaEstoque);
                break;
            case 5:
                menuRelatorio(listaMedicamento, listaMovimentacao, listaCliente, listaRanking);
                break;
            case 6:

                break;
            default:

                break;
        }
    }while(opcao != 6);
}