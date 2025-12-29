#include "funcoes.h"

void alterarFornecedorTelefone(TipoListaFornecedor *listaFornecedor, int codigo){

    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO.....");
    
    gotoxy(21,14);
    printf("                                     ");

    gotoxy(21,14);
    fflush(stdin);
    fgets(temporaria.telefone,20,stdin);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.telefone, temporaria.telefone);
    }else{
        return;
    }

}