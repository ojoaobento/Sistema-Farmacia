#include "funcoes.h"

void alterarClienteCPF(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;

    resultado = pesquisaCliente(listaCliente, codigo);

    do {
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO");

        gotoxy(27,12);
        printf("                                        ");

        gotoxy(27,12);
        fflush(stdin);
        fgets(temporaria.cpf,12,stdin);

        verificacao=0;
        if(strlen(temporaria.cpf) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("PREENCHA O CAMPO CPF.......");
            verificacao=1;
            getch();
        }else if(strlen(temporaria.cpf) != 11){
            limpa_msg();
            gotoxy(2,23);
            printf("CPF INVALIDO, INSIRA NOVAMENTE.......");
            verificacao=1;
            getch();         
        }
    }while(verificacao != 0);  

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.cpf, temporaria.cpf);
    } else {
        return;
    }


}