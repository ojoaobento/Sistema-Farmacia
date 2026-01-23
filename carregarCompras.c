#include "funcoes.h"

void carregarCompras(TipoListaMovimentacao *listaMovimentacao){

    ApontadorMovimentacao p;
    ApontadorMovimentacao novo;
    reg_movimentacoes temporaria;

    
    FILE *f = fopen("compras.dat", "rb");


    p = listaMovimentacao->primeiro;
    while(fread(&temporaria,sizeof(reg_movimentacoes),1,f) == 1){

        novo = (ApontadorMovimentacao) malloc(sizeof(TipoMovimentacao));
        novo->proximo = NULL;

        novo->conteudo = temporaria;

        if(listaMovimentacao->primeiro == NULL){
            listaMovimentacao->primeiro = novo;
            listaMovimentacao->ultimo = novo;
        }else{
            listaMovimentacao->ultimo->proximo = novo;
            listaMovimentacao->ultimo = novo;
        }
    }

    fclose(f);

}