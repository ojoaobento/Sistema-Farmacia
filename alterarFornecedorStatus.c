#include "funcoes.h"

void alterarFornecedorStatus(TipoListaFornecedor *listaFornecedor, int codigo){

    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    gotoxy(21,16);
    printf("                  ");
                
    gotoxy(21,16);
    scanf("%d", &temporaria.status);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.status = temporaria.status;
    }else{
        return;
    }

}