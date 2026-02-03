#include "funcoes.h"

void alterarClienteTelefone(TipoListaCliente *listaCliente, int codigo){


    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);   

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO");

    gotoxy(27,13);
    printf("                    ");

    gotoxy(27,13);
    fflush(stdin);
    fgets(temporaria.telefone,20,stdin);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);


    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.telefone, temporaria.telefone);
    } else {
        return;
    }              

}