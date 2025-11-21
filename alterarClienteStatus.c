#include "funcoes.h"

void alterarClienteStatus(TipoListaCliente *listaCliente, int codigo){
    
    char alteracao;
    reg_clientes temporaria;
    ApontadorCliente resultado;

    resultado = pesquisaCliente(listaCliente, codigo);  

    limpa_msg();
    gotoxy(2,23);

    gotoxy(53,17);
    printf(" ");

    gotoxy(53,17);
    scanf("%d", &temporaria.status);

    gotoxy(30,19);
    printf("CONFIRMA ALTERACAO ( S/N ) ? ");
    scanf(" %c", &alteracao);

    if(alteracao == 's' || alteracao == 'S'){
        resultado->conteudo.status = temporaria.status;
    } else {
        return;
    }

}