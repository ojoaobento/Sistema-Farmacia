#include "funcoes.h"

void ordenarFornecedor(TipoListaFornecedor *listaFornecedor){
    ApontadorFornecedor p_auxiliar;
    ApontadorFornecedor r_auxiliar;
    reg_fornecedor temporaria;
    int trocou;

    do {
        p_auxiliar = listaFornecedor->primeiro;
        r_auxiliar = p_auxiliar->proximo;
        trocou=0;
        while(r_auxiliar != NULL){
            if(p_auxiliar->conteudo.id > r_auxiliar->conteudo.id){
                p_auxiliar->conteudo = temporaria;
                p_auxiliar->conteudo = r_auxiliar->conteudo;
                r_auxiliar->conteudo = temporaria;
                trocou = 1;
            }
            p_auxiliar = p_auxiliar->proximo;
            r_auxiliar = r_auxiliar->proximo;
        }

    }while(trocou != 0);
}