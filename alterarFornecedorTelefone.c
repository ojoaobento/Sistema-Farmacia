#include "funcoes.h"

void alterarFornecedorTelefone(TipoListaFornecedor *listaFornecedor, int codigo){

    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;
    int verificacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.....");
        
        gotoxy(21,14);
        printf("                                     ");

        gotoxy(21,14);
        fflush(stdin);
        fgets(temporaria.telefone,20,stdin);
        removerLinha(temporaria.telefone);
        verificacao=0;
        if(strlen(temporaria.telefone) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM TELEFONE VALIDO......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.telefone, temporaria.telefone);
    }else{
        return;
    }

}