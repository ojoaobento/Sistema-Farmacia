#include "funcoes.h"

void carregarFornecedor(TipoListaFornecedor *listaFornecedor){

    ApontadorFornecedor novoElemento;
    reg_fornecedor temporaria;


    FILE *f = fopen("fornecedor.dat", "rb");

    while(fread(&temporaria,sizeof(reg_fornecedor),1,f) == 1){
        novoElemento = (ApontadorFornecedor) malloc(sizeof(TipoFornecedor));
        novoElemento->conteudo = temporaria;
        novoElemento->proximo = NULL;

        if(listaFornecedor->primeiro == NULL){
            listaFornecedor->primeiro = novoElemento;
            listaFornecedor->ultimo = novoElemento;
            listaFornecedor->primeiro->anterior = NULL;
        }else{
            novoElemento->anterior = listaFornecedor->ultimo;
            listaFornecedor->ultimo->proximo = novoElemento;
            listaFornecedor->ultimo = novoElemento;
            listaFornecedor->ultimo->proximo = NULL;
        }
    }

    fclose(f);
}