#include "funcoes.h"

void alterarMedicamentoPA(TipoListaMedicamento listaMedicamentos, int codigo){
     
    int verificacao;
    ApontadorMedicamento resultado;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, codigo);   


    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO......");

        gotoxy(30,13);
        printf("                                                         ");

        gotoxy(30,13);
        fflush(stdin);
        fgets(temporaria.principio_ativo,20,stdin);
        removerLinha(temporaria.principio_ativo);
        verificacao=0;
        if(strlen(temporaria.principio_ativo) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPO PRINCIPIO ATIVO......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        strcpy(resultado->conteudo.principio_ativo, temporaria.principio_ativo);
    } else{
        return;
    }
}