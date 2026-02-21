#include "funcoes.h"

void ordenarCliente(TipoListaCliente *listaCliente){

    ApontadorCliente p_auxiliar;
    ApontadorCliente r_auxiliar;
    reg_clientes temporaria;
    int trocou;

    do {
        p_auxiliar = listaCliente->primeiro;
        r_auxiliar = p_auxiliar->proximo;
        trocou=0;
        while(r_auxiliar != NULL){
            if(p_auxiliar->conteudo.id_cliente > r_auxiliar->conteudo.id_cliente){
                temporaria = p_auxiliar->conteudo;
                p_auxiliar->conteudo = r_auxiliar->conteudo;
                r_auxiliar->conteudo = temporaria;
                trocou = 1;
            }
            p_auxiliar = p_auxiliar->proximo;
            r_auxiliar = r_auxiliar->proximo;
        }
    }while(trocou != 0);
}