#include "funcoes.h"

void alterarFornecedorEmail(TipoListaFornecedor *listaFornecedor, int codigo){
    
    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;
    int verificacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.....");

        gotoxy(21,15);
        printf("                                                  ");

        gotoxy(21,15);
        fflush(stdin);
        fgets(temporaria.email,50,stdin);
        removerLinha(temporaria.email);
        verificacao=0;
        if(strlen(temporaria.email) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM EMAIL VALIDO......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.email, temporaria.email);
    }else{
        return;
    }

}