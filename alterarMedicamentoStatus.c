#include "funcoes.h"

void alterarMedicamentoStatus(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);  

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO......");

        gotoxy(30,18);
        printf("                     ");

        gotoxy(30,18);
        scanf("%d", &temporaria.status);
        verificacao=0;
        if(temporaria.status != 0 && temporaria.status != 1){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM STATUS VALIDO.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

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