#include "funcoes.h"

void esvaziarRanking(TipoListaRanking *listaRanking){

    ApontadorRanking p;
    ApontadorRanking temp;

    p = listaRanking->primeiro;

    while(p != NULL){
        temp = p;
        p = p->proximo;
        free(temp);
    }
    listaRanking->primeiro = NULL;
    listaRanking->ultimo = NULL;
}