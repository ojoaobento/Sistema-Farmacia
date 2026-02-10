#include "funcoes.h"

void alterarMedicamentoNome(TipoListaMedicamento *listaMedicamentos, int codigo){
    
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);

    do {

        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO......");

        gotoxy(30,12);
        printf("                                              ");

        gotoxy(30,12);
        fflush(stdin);
        fgets(temporaria.nome,14,stdin);
        removerLinha(temporaria.nome);
        verificacao=0;
        if(strlen(temporaria.nome) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM NOME VALIDO.......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.nome, temporaria.nome);
    } else {
        return;
    }
  
}