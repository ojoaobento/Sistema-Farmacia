#include "funcoes.h"

ApontadorMedicamento pesquisaMedicamento(TipoListaMedicamento *listaMedicamento, int codigo){
    ApontadorMedicamento p_auxiliar;

    p_auxiliar = listaMedicamento->primeiro;

    while(p_auxiliar != NULL){
        if(p_auxiliar->conteudo.id == codigo){
            return p_auxiliar;
            break;
        }
        p_auxiliar = p_auxiliar->proximo;
    }

    return NULL;
}