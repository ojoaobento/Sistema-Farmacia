#include "funcoes.h"

void alterarMedicamentoLote(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);
    
                    
    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO......");

    gotoxy(30,14);
    printf("                                   ");

    gotoxy(30,14);
    fflush(stdin);
    fgets(temporaria.lote,20,stdin);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.lote, temporaria.lote);
    } else {
        return;
    }
  
}