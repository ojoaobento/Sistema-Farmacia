#include "funcoes.h"

void salvarMedicamentos(TipoListaMedicamento listaMedicamento){
    
    ApontadorMedicamento p_auxiliar;

    FILE *f = fopen("medicamentos.dat", "wb");

    p_auxiliar = listaMedicamento.primeiro;

    while(p_auxiliar != NULL){
        fwrite(&p_auxiliar->conteudo, sizeof(reg_medicamentos), 1, f);
        p_auxiliar = p_auxiliar->proximo;
    }

    fclose(f);

}