#include "funcoes.h"

void exclusaoCliente(TipoListaCliente *lista){

    ApontadorCliente resultado;
    int codigo;

    system("cls");
    tela();

    limpa_msg();
    gotoxy(2,23);
    printf("INSIRA O CODIGO DO CADASTRO QUE DESEJA EXCLUIR: ");
    scanf("%d", &codigo);


    resultado = pesquisaCliente(codigo, lista);

    if(resultado == NULL){
        system("cls");
        tela();

        limpa_msg();

        gotoxy(2,23);
        printf("O CODIGO INSERIDAO NAO EXISTE, RETORNE AO MENU PRINCIPAL....");

        getch();

        return;
    } else {
        
    }

}