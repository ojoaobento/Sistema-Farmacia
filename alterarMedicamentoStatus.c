#include "funcoes.h"

void alterarMedicamentoStatus(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);  

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO......");

    gotoxy(30,18);
    printf("                     ");

    gotoxy(30,18);
    scanf("%d", &temporaria.status);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.status = temporaria.status;
    } else {
        return;
    }

}