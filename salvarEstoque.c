#include "funcoes.h"

void salvarEstoque(TipoListaEstoque listaEstoque){

    ApontadorEstoque p;

    FILE *f = fopen("estoque.dat", "wb");


    p = listaEstoque.primeiro;

    while(p != NULL){
        fwrite(&p->conteudo,sizeof(reg_estoque),1,f);
        p = p->proximo;
    }

    fclose(f);

}