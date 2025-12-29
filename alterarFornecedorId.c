#include "funcoes.h"

void alterarFornecedorId(TipoListaFornecedor *listaFornecedor, int *codigo){

    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    ApontadorFornecedor p_auxiliar;
    int verificacao;
    char confirmacao;

    resultado = pesquisaFornecedor(listaFornecedor, *codigo);

    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.....");
        
        gotoxy(21,11);
        printf("              ");

        gotoxy(21,11);
        scanf("%d", &temporaria.id);
        verificacao=0;
        p_auxiliar = listaFornecedor->primeiro;
        while(p_auxiliar != NULL){
            if(p_auxiliar != resultado && p_auxiliar->conteudo.id == temporaria.id){
                limpa_msg();
                gotoxy(2,23);
                printf("O CODIGO INSERIDO JA EXISTE, INSIRA OUTRO.....");
                verificacao=1;
                getch();
            }
            p_auxiliar = p_auxiliar->proximo;
        }
    }while(verificacao != 0);      

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.id = temporaria.id;
        *codigo = temporaria.id;
    }else{
        return;
    }

}