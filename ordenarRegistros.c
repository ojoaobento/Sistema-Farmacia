#include "funcoes.h"


void ordenarRegistros(TipoListaEstoque *listaEstoque){

    ApontadorEstoque p;
    ApontadorEstoque r;
    reg_estoque temp;
    int trocou;

    do {
        p = listaEstoque->primeiro;
        r = p->proximo;
        trocou=0;
        while(r != NULL){
            if(p->conteudo.id_medicamento > r->conteudo.id_medicamento){
                temp = p->conteudo;
                p->conteudo = r->conteudo;
                r->conteudo = temp;
                trocou=1;
            }
            p = p->proximo;
            r = r->proximo;
        }
    }while(trocou != 0);
}