#include "funcoes.h"

void alterarMedicamentoLote(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);
    
                
    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO......");

        gotoxy(30,15);
        printf("                                   ");

        gotoxy(30,15);
        fflush(stdin);
        fgets(temporaria.lote,20,stdin);
        removerLinha(temporaria.lote);
        verificacao=0;
        if(strlen(temporaria.lote) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPO LOTE.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.lote, temporaria.lote);
    } else {
        return;
    }
  
}