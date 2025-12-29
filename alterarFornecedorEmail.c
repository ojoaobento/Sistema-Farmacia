#include "funcoes.h"

void alterarFornecedorEmail(TipoListaFornecedor *listaFornecedor, int codigo){
    
    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);


    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO.....");

    gotoxy(21,15);
    printf("                                                  ");

    gotoxy(21,15);
    fflush(stdin);
    fgets(temporaria.email,50,stdin);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.email, temporaria.email);
    }else{
        return;
    }

}