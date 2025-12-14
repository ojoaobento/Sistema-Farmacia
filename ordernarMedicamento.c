#include "funcoes.h"

void ordenarMedicamento(TipoListaMedicamento *listaMedicamento){
    ApontadorMedicamento p_auxiliar;
    ApontadorMedicamento r_auxiliar;
    reg_medicamentos temporaria;
    int trocou;

    do {
        p_auxiliar = listaMedicamento->primeiro;
        r_auxiliar = p_auxiliar->proximo;
        trocou=0;
        while(p_auxiliar != NULL){
            if(p_auxiliar->conteudo.id > r_auxiliar->conteudo.id){
                temporaria = p_auxiliar->conteudo;
                p_auxiliar->conteudo = r_auxiliar->conteudo;
                r_auxiliar->conteudo = temporaria;
                trocou=1;
            }
            p_auxiliar = p_auxiliar->proximo;
            r_auxiliar = r_auxiliar->proximo;
        }
    }while(trocou != 0);
}