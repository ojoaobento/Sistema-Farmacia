#include "funcoes.h"

void carregarMedicamentos(TipoListaMedicamento *listaMedicamento){

    ApontadorMedicamento novoElemento;
    reg_medicamentos temporaria;

    FILE *f = fopen("medicamentos.dat", "rb");

    while(fread(&temporaria, sizeof(reg_medicamentos), 1 , f) == 1){
        novoElemento = (ApontadorMedicamento) malloc(sizeof(reg_medicamentos));
        novoElemento->conteudo = temporaria;
        novoElemento->proximo = NULL;


        if(listaMedicamento->primeiro == NULL){
            listaMedicamento->primeiro = novoElemento;
            listaMedicamento->ultimo = novoElemento;
        } else{
            listaMedicamento->ultimo->proximo = novoElemento;
            listaMedicamento->ultimo = novoElemento;
        }
    }

    fclose(f);

}