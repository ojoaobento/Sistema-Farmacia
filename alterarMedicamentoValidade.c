#include "funcoes.h"

void alterarMedicamentoValidade(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);   


    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO.....");

    gotoxy(30,14);
    printf("                                 ");
                    
    gotoxy(30,14);
    fflush(stdin);
    fgets(temporaria.validade,11,stdin);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.validade, temporaria.validade);
    } else{
        return;
    }  
}