#include "funcoes.h"

void alterarFornecedorCnpj(TipoListaFornecedor *listaFornecedor, int codigo){
    
    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;
    int verificacao;
    int outraVerificacao;


    resultado = pesquisaFornecedor(listaFornecedor, codigo);


    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.......");

        gotoxy(21,13);
        printf("                                ");

        gotoxy(21,13);
        fflush(stdin);
        fgets(temporaria.cnpj,15,stdin);

        removerLinha(temporaria.cnpj);
        verificacao=0;
        outraVerificacao=0;
        if(strlen(temporaria.cnpj) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPO CNPJ...........");
            verificacao = 1;
            getch();
        }else if(strlen(temporaria.cnpj) != 14){
            limpa_msg();
            gotoxy(2,23);
            printf("CNPJ INVALIDO, INSIRA NOVAMENTE..........");
            outraVerificacao = 1;
            getch();
        }
    }while(verificacao != 0 || outraVerificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.cnpj, temporaria.cnpj);
    }else{
        return;
    }


}