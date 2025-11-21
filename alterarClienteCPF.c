#include "funcoes.h"

void alterarClienteCPF(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO");

    gotoxy(27,12);
    printf("                                            ");


    gotoxy(27,12);
    fflush(stdin);
    fgets(temporaria.cpf,15,stdin);

    gotoxy(30,19);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.cpf, temporaria.cpf);
    } else {
        return;
    }


}