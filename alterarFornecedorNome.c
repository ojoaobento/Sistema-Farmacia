#include "funcoes.h"

void alterarFornecedorNome(TipoListaFornecedor *listaFornecedor, int codigo){
    
    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO.....");
    
    gotoxy(21,12);
    printf("                                                  ");

    gotoxy(21,12);
    fflush(stdin);
    fgets(temporaria.nome,50,stdin);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.nome, temporaria.nome);
    }else{
        return;
    }

}