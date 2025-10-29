#include "funcoes.h"

ApontadorCliente pesquisaCliente(int codigo, TipoListaCliente *lista){
    
    ApontadorCliente p_auxiliar;

    p_auxiliar = lista->primeiro;

    while(p_auxiliar != NULL){

        if(p_auxiliar->conteudo.id_cliente == codigo){
            return p_auxiliar;
        }

        p_auxiliar = p_auxiliar->proximo;
    }

    return NULL;

}

