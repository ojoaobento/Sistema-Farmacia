#include "funcoes.h"

void alterarMedicamentoValidade(TipoListaMedicamento *listaMedicamentos, int codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);   


    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO.....");

        gotoxy(30,14);
        printf("                                 ");

        gotoxy(30,14);
        fflush(stdin);
        fgets(temporaria.validade,11,stdin);
        removerLinha(temporaria.validade);
        verificacao=0;
        if(strlen(temporaria.validade) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UMA VALIDADE CORRETA.........");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);
    
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