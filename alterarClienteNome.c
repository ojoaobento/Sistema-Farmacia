#include "funcoes.h"

void alterarClienteNome(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);   

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO");

    gotoxy(31,9);
    printf("                                                            ");

    gotoxy(31,9);
    fflush(stdin);
    fgets(temporaria.nome,50,stdin);

    gotoxy(30,19);
    printf("CONFIRMA ALTERACAO (S/N) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.nome, temporaria.nome);
    } else {
        return;
    }

}