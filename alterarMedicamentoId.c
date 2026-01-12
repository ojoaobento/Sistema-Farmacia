#include "funcoes.h"

void alterarMedicamentoId(TipoListaMedicamento *listaMedicamentos, int *codigo){
    int verificacao;
    ApontadorMedicamento resultado;
    ApontadorMedicamento p_auxiliar;
    reg_medicamentos temporaria;
    char confirmacao;

    resultado = pesquisaMedicamento(listaMedicamentos, *codigo);   

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO......");

        gotoxy(30,11);
        printf("                   ");

        gotoxy(30,11);
        scanf("%d", &temporaria.id);
        verificacao=0;
        p_auxiliar = listaMedicamentos->primeiro;
        while(p_auxiliar != NULL){
            if(temporaria.id == p_auxiliar->conteudo.id){
                limpa_msg();
                gotoxy(2,23);
                printf("ESSE ID JA EXISTE, INSIRA OUTRO.....");
                verificacao=1;
                getch();
                break;
            }
            p_auxiliar = p_auxiliar->proximo;
        }

    }while(verificacao != 0);

    gotoxy(30,19);
    printf("CONFIRMAR ALTERACAO ( S/N ) ? ");
    scanf(" %c", &confirmacao);

    if(confirmacao == 's' || confirmacao == 'S'){
        resultado->conteudo.id = temporaria.id;
        *codigo = temporaria.id;
    } else{
        return;
    }   
}