#include "funcoes.h"

void alterarMedicamentoPreco(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);   
    
    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO.....");

    gotoxy(30,15);
    printf("                  ");

    gotoxy(30,15);
    scanf("%f", &temporaria.preco);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.preco = temporaria.preco;
    } else{
        return;
    }   
}