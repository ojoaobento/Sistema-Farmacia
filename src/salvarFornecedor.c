#include "funcoes.h"

void salvarFornecedor(TipoListaFornecedor listaFornecedor){

    ApontadorFornecedor p_auxiliar;

    FILE *f = fopen("fornecedor.dat", "wb");

    p_auxiliar = listaFornecedor.primeiro;

    while(p_auxiliar != NULL){
        fwrite(&p_auxiliar->conteudo,sizeof(reg_fornecedor),1,f);
        p_auxiliar = p_auxiliar->proximo;
    }

    fclose(f);
}