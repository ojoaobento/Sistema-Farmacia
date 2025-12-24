#include "funcoes.h"

void alterarFornecedor(TipoListaFornecedor *listaFornecedor){

    ApontadorFornecedor resultado;
    int codigo;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO FORNECEDOR QUE DESEJA ALTERAR : ");
    scanf("%d", &codigo);

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    if(resultado == NULL){
        system("cls");
        tela();

        limpa_msg();
        gotoxy(2,23);
        printf("O CODIGO INSERIDO NAO EXISTE, VOLTE AO MENU PRINCIPAL.....");
        getch();
        return;
    } else{
        system("cls");
        tela();

        
    }

}