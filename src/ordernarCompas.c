#include "funcoes.h"

void ordenarCompras(TipoListaMovimentacao *listaMovimentacao){
    ApontadorMovimentacao p;
    ApontadorMovimentacao r;
    reg_movimentacoes temp;
    int trocou;

    do {
        p = listaMovimentacao->primeiro;
        r = p->proximo;
        trocou=0;
        while(r != NULL){
            if(p->conteudo.cd_cliente > r->conteudo.cd_cliente){
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