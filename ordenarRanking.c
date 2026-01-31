#include "funcoes.h"

void ordenarRanking(TipoListaRanking *listaRanking){

    ApontadorRanking p;
    ApontadorRanking r;
    reg_ranking temp;
    int trocou;

    do {
        p = listaRanking->primeiro;
        r = p->proximo;
        trocou=0;
        while(r != NULL){
            if(p->conteudo.quantidade_vendida < r->conteudo.quantidade_vendida){
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