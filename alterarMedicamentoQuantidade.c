#include "funcoes.h"

void alterarMedicamentoQuantidade(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);    

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO.......");

    gotoxy(30,17);
    printf("              ");

    gotoxy(30,17);
    scanf("%d", &temporaria.quantidade);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.quantidade = temporaria.quantidade;
    } else{
        return;
    }
}