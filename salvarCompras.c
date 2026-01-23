#include "funcoes.h"

void salvarCompras(TipoListaMovimentacao listaMovimentacao){

    ApontadorMovimentacao p;

    FILE *f = fopen("compras.dat", "wb");


    p = listaMovimentacao.primeiro;

    while(p != NULL){
        fwrite(&p->conteudo,sizeof(reg_movimentacoes),1,f);
        p = p->proximo;
    }

    fclose(f);

}