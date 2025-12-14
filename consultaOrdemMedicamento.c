#include "funcoes.h"

void consultaOrdemMedicamento(TipoListaMedicamento *listaMedicamento){

    ApontadorMedicamento p_auxiliar;

    system("cls");

    telaOrdemMedicamento();
    ordenarMedicamento(listaMedicamento);

    p_auxiliar = listaMedicamento->primeiro;
    while(p_auxiliar != NULL){
        gotoxy(3,7);
        printf("%d", p_auxiliar->conteudo.id);
    }

    getch();
}