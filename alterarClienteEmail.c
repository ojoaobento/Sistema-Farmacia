#include "funcoes.h"

void alterarClienteEmail(TipoListaCliente *listaCliente, int codigo){
    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);   

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO");

    gotoxy(14,13);
    printf("                                                            ");

    gotoxy(14,13);
    fflush(stdin);
    fgets(temporaria.email,50,stdin);

    gotoxy(30,19);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.email, temporaria.email);
    } else {
        return;
    }

}