#include "funcoes.h"

void alterarClienteData(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO");

    gotoxy(27,16);
    printf("                          ");               

    gotoxy(27,16);
    fflush(stdin);
    fgets(temporaria.data_cadastro,19,stdin);


    gotoxy(30,19);
    printf("CONFIRMA ALTERACAO ( S/N ) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.data_cadastro,temporaria.data_cadastro);
    } else {
        return;
    }

}