#include "funcoes.h"

void alterarClienteEnd(TipoListaCliente *listaCliente, int codigo){

    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);  
    

    limpa_msg();
    gotoxy(2,23);
    printf("ALTERANDO CAMPO");

    gotoxy(27,15);
    printf("                                                                      ");

    gotoxy(27,15);
    fflush(stdin);
    fgets(temporaria.endereco,60,stdin);

    limpa_msg();
    gotoxy(2,23);
    printf("CONFIRMA ALTERACAO ( S/N ) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        strcpy(resultado->conteudo.endereco,temporaria.endereco);
    } else {
        return;
    }

}