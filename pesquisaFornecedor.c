#include "funcoes.h"

ApontadorFornecedor pesquisaFornecedor(TipoListaFornecedor listaFornecedor, int codigo){
    ApontadorFornecedor p_auxiliar;

    p_auxiliar = listaFornecedor.primeiro;
    while(p_auxiliar != NULL){
        if(p_auxiliar->conteudo.id == codigo){
            return p_auxiliar;
        }
    }
    return NULL;
}