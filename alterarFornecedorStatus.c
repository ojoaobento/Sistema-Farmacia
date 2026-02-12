#include "funcoes.h"

void alterarFornecedorStatus(TipoListaFornecedor *listaFornecedor, int codigo){

    ApontadorFornecedor resultado;
    reg_fornecedor temporaria;
    char confirmacao;
    int verificacao;

    resultado = pesquisaFornecedor(listaFornecedor, codigo);

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.....");
        
        gotoxy(21,16);
        printf("                  ");
                    
        gotoxy(21,16);
        scanf("%d", &temporaria.status);
        
        limpa_msg();
        gotoxy(2,23);
        printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
        scanf(" %c", &confirmacao);
        verificacao=0;
        if(temporaria.status != 0 || temporaria.status != 1){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM STATUS VALIDO.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.status = temporaria.status;
    }else{
        return;
    }

}