#include "funcoes.h"

void alterarMedicamentoNome(TipoListaMedicamento *listaMedicamentos, int codigo){
    
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO......");

    gotoxy(30,11);
    printf("                                              ");

    gotoxy(30,11);
    fflush(stdin);
    fgets(temporaria.nome,50,stdin);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.nome, temporaria.nome);
    } else {
        return;
    }
  
}