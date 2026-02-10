#include "funcoes.h"

void alterarClienteEmail(TipoListaCliente *listaCliente, int codigo){
    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;
    int verificacao;

    resultado = pesquisaCliente(listaCliente, codigo);   


    do {
        
        limpa_msg();
        gotoxy(2,23);
        printf("ALTERANDO CAMPO");

        gotoxy(27,14);
        printf("                                                            ");

        gotoxy(27,14);
        fflush(stdin);
        fgets(temporaria.email,50,stdin);
        removerLinha(temporaria.email);
        verificacao=0;
        if(strlen(temporaria.email) == 0){
            limpa_msg();
            gotoxy(2,23);
            printf("INSIRA UM EMAIL VALIDO......");
            verificacao=1;
            getch();
        }
    }while(verificacao != 0);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.email, temporaria.email);
    } else {
        return;
    }

}