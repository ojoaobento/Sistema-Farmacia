#include "funcoes.h"

void alterarFornecedorNome(TipoListaFornecedor *listaFornecedor, int codigo){
    
    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;
    int verificacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.....");
        
        gotoxy(21,12);
        printf("                                                  ");

        gotoxy(21,12);
        fflush(stdin);
        fgets(temporaria.nome,16,stdin);
        removerLinha(temporaria.nome);
        verificacao=0;
        if(strlen(temporaria.nome) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPÓ NOME.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);   

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