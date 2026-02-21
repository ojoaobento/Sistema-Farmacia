#include "funcoes.h"

void carregarEstoque(TipoListaEstoque *listaEstoque){

    ApontadorEstoque novo;
    reg_estoque temp;

    FILE *f = fopen("estoque.dat", "rb");

    while(fread(&temp,sizeof(reg_estoque),1,f) == 1){

        novo = (ApontadorEstoque) malloc(sizeof(TipoEstoque));
        novo->proximo = NULL;

        novo->conteudo = temp;

        if(listaEstoque->primeiro == NULL){
            listaEstoque->primeiro = novo;
            listaEstoque->ultimo = novo;
        }else{
            listaEstoque->ultimo->proximo = novo;
            listaEstoque->ultimo = novo;
        }
    }

    fclose(f);

}