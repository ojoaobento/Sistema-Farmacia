#include "funcoes.h"

void alterarFornecedorCnpj(TipoListaFornecedor *listaFornecedor, int codigo){
    
    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;


    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    gotoxy(21,13);
    printf("                                ");

    gotoxy(21,13);
    fflush(stdin);
    fgets(temporaria.cnpj,15,stdin);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.cnpj, temporaria.cnpj);
    }else{
        return;
    }


}